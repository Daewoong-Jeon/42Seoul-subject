/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:41:27 by djeon             #+#    #+#             */
/*   Updated: 2021/08/06 21:50:59 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void handle_signal(int signo)
{
	if (signo == SIGINT)
	{
		sem_unlink("/semaphore");
		sem_unlink("/semaphore2");
		exit(0);
	}
}

void *monitor(void *data)
{
	struct timeval cur;
	t_carry *carrier;
	long time;

	carrier = (t_carry *)data;
	while (1)
	{
		if (carrier->con.num_of_eat != -1 && carrier->cur_num_eating >=
				carrier->con.num_of_eat)
			break ;
		gettimeofday(&cur, NULL);
		time = ((cur.tv_sec - carrier->before.tv_sec) * 1000000 + cur.tv_usec - carrier->before.tv_usec) / 1000;
		if (time > carrier->con.time_to_die)
		{
			sem_wait(carrier->arg_dead);
			if (*(carrier->dead) == 0)
			{
				*(carrier->dead) = 1;
				sem_post(carrier->sem);
				printf("%ldms %d died\n", ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000 + cur.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
			}
			sem_post(carrier->arg_dead);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

void exec(t_carry *carrier)
{
	pthread_t monitor_id;
	struct timeval cur;

	pthread_create(&monitor_id, NULL, monitor, carrier);
	signal(SIGINT, handle_signal);
	while (1)
	{
		sem_wait(carrier->sem);
		gettimeofday(&cur, NULL);
		if (*(carrier->dead) == 1)
			return ;
		printf("%ldms %d has taken a fork\n", ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000 + cur.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
		gettimeofday(&cur, NULL);
		carrier->before = cur;
		carrier->cur_num_eating++;
		if (*(carrier->dead) == 1)
			return ;
		printf("%ldms %d is eating\n", ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000 + cur.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
		usleep(carrier->con.time_to_eat * 1000);
		sem_post(carrier->sem);
		gettimeofday(&cur, NULL);
		if (*(carrier->dead) == 1)
			return ;
		printf("%ldms %d is sleeping\n", ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000 + cur.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
		usleep(carrier->con.time_to_sleep * 1000);
		gettimeofday(&cur, NULL);
		if (*(carrier->dead) == 1)
			return ;
		printf("%ldms %d is thinking\n", ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000 + cur.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
	}
	pthread_join(monitor_id, NULL);
}

int main(int argc, char **argv)
{
	struct timeval start;
	t_carry *carrier;
	t_arg con;
//	sem_t *sem;
	pid_t *pid;
	int i;
	int status;

	i = -1;
	if (input_arg(&con, argc, argv) == -1)
		return (-1);
//	sem = sem_open("/semaphore", O_CREAT | O_EXCL, 0644, con.num_of_philo / 2);
	if (init_carrier(&carrier, con) == -1)
		return (-1);
	if (!(pid = malloc(sizeof(pid_t) * con.num_of_philo)))
		return (-1);
	gettimeofday(&start, NULL);
	while (++i < con.num_of_philo)
	{
		carrier[i].before = start;
		if ((pid[i] = fork()) == -1)
			return (-1);
		if (pid[i] == 0)
		{
			exec(&carrier[i]);
			break ;
		}
	}
	i = -1;
	while (++i < con.num_of_philo)
		waitpid(pid[i], &status, 0);
	sem_unlink("/semaphore");
	sem_unlink("/semaphore2");
	return (0);
}
