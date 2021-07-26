/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:41:27 by djeon             #+#    #+#             */
/*   Updated: 2021/07/26 10:27:27 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void exec(t_carry *carrier, sem_t *sem)
{
	struct timeval time;
	int num_eating;

	num_eating = 0;
	while (1)
	{
		sem_wait(sem);
		gettimeofday(&time, NULL);
		printf("%ldms %d has taken a fork\n", ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
		gettimeofday(&time, NULL);
		printf("%ldms %d is eating\n", ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
		usleep(carrier->con.time_to_eat * 1000);
		sem_post(sem);
		gettimeofday(&time, NULL);
		printf("%ldms %d is sleeping\n", ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
		usleep(carrier->con.time_to_sleep * 1000);
		gettimeofday(&time, NULL);
		printf("%ldms %d is thinking\n", ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
	}
}

int main(int argc, char **argv)
{
	t_carry *carrier;
	t_arg con;
	sem_t *sem;
	pid_t *pid;
	int i;
	int status;

	i = -1;
	if (input_arg(&con, argc, argv) == -1)
		return (-1);
	sem = sem_open("semaphore", O_CREAT | O_EXCL, 0644, con.num_of_philo / 2);
	if (init_carrier(&carrier, con) == -1)
		return (-1);
	if (!(pid = malloc(sizeof(pid_t) * con.num_of_philo)))
		return (-1);
	while (++i < con.num_of_philo)
	{
		if ((pid[i] = fork()) == -1)
			return (-1);
		if (pid[i] == 0)
		{
			exec(&carrier[i], sem);
			break ;
		}
	}
	i = -1;
	while (++i < con.num_of_philo)
		waitpid(pid[i], &status, 0);
	return (0);
}
