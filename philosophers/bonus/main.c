/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:41:27 by djeon             #+#    #+#             */
/*   Updated: 2021/08/09 16:21:13 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int input_arg(t_arg *con, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (-1);
	if ((con->num_of_philo = ft_atoi_v2(argv[1])) == -1)
		return (-1);
	if ((con->time_to_die = ft_atoi_v2(argv[2])) == -1)
		return (-1);
	if ((con->time_to_eat = ft_atoi_v2(argv[3])) == -1)
		return (-1);
	if ((con->time_to_sleep = ft_atoi_v2(argv[4])) == -1)
		return (-1);
	if (argv[5] == NULL)
		con->num_of_eat = -1;
	else
	{
		if ((con->num_of_eat = ft_atoi_v2(argv[5])) == -1)
			return (-1);
	}
	gettimeofday(&con->start, NULL);
	return (0);
}

int init_carrier(t_carry **carrier, t_arg con)
{
	sem_t *sem;
	sem_t *arg_dead;
	sem_t *msg;
	int i;

	if (!(*carrier = malloc(sizeof(t_carry) * con.num_of_philo)))
		return (-1);
	sem = sem_open("/semaphore", O_CREAT | O_EXCL, 0644, con.num_of_philo / 2);
	arg_dead = sem_open("/semaphore2", O_CREAT | O_EXCL, 0644, 1);
	msg = sem_open("/semaphore3", O_CREAT | O_EXCL, 0644, 1);
	if (sem == SEM_FAILED || arg_dead == SEM_FAILED || msg == SEM_FAILED)
		return (-1);
	i = -1;
	while (++i < con.num_of_philo)
	{
		(*carrier)[i].philo = i;
		(*carrier)[i].cur_num_eating = 0;
		(*carrier)[i].arg_dead = arg_dead;
		(*carrier)[i].sem = sem;
		(*carrier)[i].msg = msg;
		(*carrier)[i].con = con;
	}
	return (0);
}

void exec(t_carry *carrier)
{
	pthread_t monitor_id;

	pthread_create(&monitor_id, NULL, monitor_thread, carrier);
	signal(SIGINT, handle_signal);
	while (1)
	{
		eating(carrier);
		sleeping_and_thinking(carrier);
	}
	pthread_join(monitor_id, NULL);
}

int create_process(t_carry *carrier, t_arg con)
{
	struct timeval start;
	int i;

	i = -1;
	gettimeofday(&start, NULL);
	while (++i < con.num_of_philo)
	{
		carrier[i].before = start;
		if ((carrier[i].pid = fork()) == -1)
			return (-1);
		if (carrier[i].pid == 0)
		{
			exec(&carrier[i]);
			break ;
		}
	}
	if (i == con.num_of_philo)
		monitor_process(carrier);
	return (0);
}

int main(int argc, char **argv)
{
	t_carry *carrier;
	t_arg con;

	if (input_arg(&con, argc, argv) == -1)
		return (printf("input error\n"));
	if (init_carrier(&carrier, con) == -1)
	{
		free_all();
		return (printf("init failed\n"));
	}
	if (create_process(carrier, con) == -1)
		return (printf("failed creating process\n"));
	return (0);
}
