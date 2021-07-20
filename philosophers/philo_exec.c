/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:57:46 by djeon             #+#    #+#             */
/*   Updated: 2021/07/20 21:57:34 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int eating(t_carry *carrier, int *num_eating)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	if (((time.tv_sec - carrier->before.tv_sec) * 1000000 + time.tv_usec - carrier->before.tv_usec) / 1000 > carrier->con.time_to_die)
	{
		printf("%ldms %d died\n", ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
		return (-1);
	}
	printf("%ldms %d has taken a fork\n", ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
	carrier->before = time;
	gettimeofday(&time, NULL);
	printf("%ldms %d is eating\n", ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
	usleep(carrier->con.time_to_eat * 1000);
	(*num_eating)++;
	return (0);
}

void sleeping_and_thinking(t_carry *carrier)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	printf("%ldms %d is sleeping\n", ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
	usleep(carrier->con.time_to_sleep * 1000);
	gettimeofday(&time, NULL);
	printf("%ldms %d is thinking\n", ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
}
