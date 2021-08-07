/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:41:27 by djeon             #+#    #+#             */
/*   Updated: 2021/08/07 19:11:05 by djeon            ###   ########.fr       */
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

void monitor_process(t_carry *carrier)
{
	int i;
	int status;
	int full;

	full = 0;
	while (1)
	{
		i = -1;
		while (++i < carrier[0].con.num_of_philo)
		{
			status = -1;
			waitpid(carrier[i].pid, &status, 0);
			if (status == 0)
				full++;
			if (full == carrier[0].con.num_of_eat)
				return ;
			if ((status >> 8) == 1)
				break ;
			i++;
		}
		if ((status >> 8) == 1)
		{
			i = -1;
			while (++i < carrier[0].con.num_of_philo)
				kill(carrier[i].pid, SIGKILL);
			break ;
		}
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
			exit(0);
		gettimeofday(&cur, NULL);
		time = ((cur.tv_sec - carrier->before.tv_sec) * 1000000 + cur.tv_usec - carrier->before.tv_usec) / 1000;
		if (time > carrier->con.time_to_die)
		{
			sem_wait(carrier->arg_dead);
			printf("%ldms %d died\n", ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000 + cur.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
			exit(1);
			sem_post(carrier->arg_dead);
		}
		usleep(100);
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
		printf("%ldms %d has taken a fork\n", ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000 + cur.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
		gettimeofday(&cur, NULL);
		carrier->before = cur;
		carrier->cur_num_eating++;
		printf("%ldms %d is eating\n", ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000 + cur.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
		usleep(carrier->con.time_to_eat * 1000);
		sem_post(carrier->sem);
		gettimeofday(&cur, NULL);
		printf("%ldms %d is sleeping\n", ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000 + cur.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
		usleep(carrier->con.time_to_sleep * 1000);
		gettimeofday(&cur, NULL);
		printf("%ldms %d is thinking\n", ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000 + cur.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
	}
	pthread_join(monitor_id, NULL);
}

int main(int argc, char **argv)
{
	struct timeval start;
	t_carry *carrier;
	t_arg con;
	int i;

	i = -1;
	if (input_arg(&con, argc, argv) == -1)
		return (-1);
	if (init_carrier(&carrier, con) == -1)
		return (-1);
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
//	free_all(carrier);
	return (0);
}
