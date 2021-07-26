/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:57:46 by djeon             #+#    #+#             */
/*   Updated: 2021/07/26 13:55:15 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long convert_time(struct timeval time)
{
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int pick_up(t_carry *carrier, pthread_mutex_t *lock1, pthread_mutex_t *lock2)
{
//	long long left_philo;
//	long long right_philo;
//	long long philo_time;
//
//	philo_time = convert_time(carrier->before[carrier->philo]);
//	if (philo_time != convert_time(carrier->con.start))
//	{
//		if (carrier->philo != 0)
//			left_philo = convert_time(carrier->before[carrier->philo - 1]);
//		else
//			left_philo = convert_time(carrier->before[carrier->con.num_of_philo - 1]);
//		right_philo = convert_time(carrier->before[(carrier->philo + 1) %
//				carrier->con.num_of_philo]);
//		if (philo_time > left_philo || philo_time > right_philo)
//			usleep(10000);
//	}
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
//	carrier->before[carrier->philo] = carrier->time;
	carrier->permit[(carrier->philo + 1) % carrier->con.num_of_philo] = 1;
	carrier->permit[carrier->philo % carrier->con.num_of_philo] = 1;
	pthread_mutex_unlock(lock1);
	pthread_mutex_unlock(lock2);
}

int eating(t_carry *carrier, int *num_eating)
{
	struct timeval time;
	long tmp;

	gettimeofday(&time, NULL);
	tmp = ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000;
	if (((time.tv_sec - carrier->before->tv_sec) * 1000000 + time.tv_usec - carrier->before->tv_usec) / 1000 > carrier->con.time_to_die)
	{
		printf("%ldms %d died\n", tmp, carrier->philo);
		return (-1);
	}
	printf("%ldms %d has taken a fork\n", tmp, carrier->philo);
	gettimeofday(&time, NULL);
	tmp = ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000;
	printf("%ldms %d is eating\n", tmp, carrier->philo);
//	carrier->time = time;
	carrier->before[carrier->philo] = time;
	if (waiting(carrier, time, carrier->con.time_to_eat * 1000) == -1)
		return (-1);
	(*num_eating)++;
	return (0);
}

int sleeping_and_thinking(t_carry *carrier)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	printf("%ldms %d is sleeping\n", ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
	if (waiting(carrier, time, carrier->con.time_to_sleep * 1000) == -1)
		return (-1);
	gettimeofday(&time, NULL);
	printf("%ldms %d is thinking\n", ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
	return (0);
}
