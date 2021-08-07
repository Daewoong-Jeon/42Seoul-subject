/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:57:46 by djeon             #+#    #+#             */
/*   Updated: 2021/08/07 22:01:12 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int pick_up(t_carry *carrier, pthread_mutex_t *lock1, pthread_mutex_t *lock2)
{
	pthread_mutex_lock(lock1);
	pthread_mutex_lock(lock2);
	if (carrier->permit[(carrier->philo + 1) % carrier->con.num_of_philo] == 1
		&& carrier->permit[carrier->philo % carrier->con.num_of_philo] == 1)
	{
		carrier->permit[(carrier->philo + 1) % carrier->con.num_of_philo] = 0;
		carrier->permit[carrier->philo % carrier->con.num_of_philo] = 0;
		pthread_mutex_unlock(lock1);
		pthread_mutex_unlock(lock2);
		return (0);
	}
	pthread_mutex_unlock(lock1);
	pthread_mutex_unlock(lock2);
	if (block(carrier) == -1)
		return (-1);
	return (0);
}

void put_down(t_carry *carrier, pthread_mutex_t *lock1, pthread_mutex_t *lock2)
{
	pthread_mutex_lock(lock1);
	pthread_mutex_lock(lock2);
	carrier->permit[(carrier->philo + 1) % carrier->con.num_of_philo] = 1;
	carrier->permit[carrier->philo % carrier->con.num_of_philo] = 1;
	pthread_mutex_unlock(lock1);
	pthread_mutex_unlock(lock2);
}

int eating(t_carry *carrier)
{
	struct timeval cur;
	long cur_time;

	gettimeofday(&cur, NULL);
	cur_time = ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000
			+ cur.tv_usec - carrier->con.start.tv_usec) / 1000;
	if (*(carrier->dead) == 1)
		return (-1);
	printf("%ldms %d has taken a fork\n", cur_time, carrier->philo);

	gettimeofday(&cur, NULL);
	cur_time = ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000
			+ cur.tv_usec - carrier->con.start.tv_usec) / 1000;
	if (*(carrier->dead) == 1)
		return (-1);
	carrier->before[carrier->philo] = cur;
	printf("%ldms %d is eating\n", cur_time, carrier->philo);
	if (waiting(carrier, cur, carrier->con.time_to_eat * 1000,
				carrier->sub * 1000) == -1)
		return (-1);

	(carrier->cur_num_eating)++;
	return (0);
}

int sleeping_and_thinking(t_carry *carrier)
{
	struct timeval cur;
	long cur_time;

	gettimeofday(&cur, NULL);
	cur_time = ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000
			+ cur.tv_usec - carrier->con.start.tv_usec) / 1000;
	if (*(carrier->dead) == 1)
		return (-1);
	printf("%ldms %d is sleeping\n", cur_time, carrier->philo);
	if (waiting(carrier, cur, carrier->con.time_to_sleep * 1000,
				carrier->sub * 1000) == -1)
		return (-1);

	gettimeofday(&cur, NULL);
	cur_time = ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000
			+ cur.tv_usec - carrier->con.start.tv_usec) / 1000;
	if (*(carrier->dead) == 1)
		return (-1);
	printf("%ldms %d is thinking\n", cur_time, carrier->philo);
	return (0);
}