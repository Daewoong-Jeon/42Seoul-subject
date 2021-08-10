/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 16:33:50 by djeon             #+#    #+#             */
/*   Updated: 2021/08/10 13:57:05 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	eating(t_carry *carrier)
{
	struct timeval	cur;
	long			time;

	sem_wait(carrier->sem);
	sem_wait(carrier->msg);
	gettimeofday(&cur, NULL);
	time = get_gap_of_time(cur, carrier->con.start);
	printf("%ldms %d has taken a fork\n", time, carrier->philo);
	sem_post(carrier->msg);
	sem_wait(carrier->msg);
	gettimeofday(&cur, NULL);
	carrier->before = cur;
	carrier->cur_num_eating++;
	time = get_gap_of_time(cur, carrier->con.start);
	printf("%ldms %d is eating\n", time, carrier->philo);
	sem_post(carrier->msg);
	waiting(cur, carrier->con.time_to_eat);
	sem_post(carrier->sem);
}

void	sleeping_and_thinking(t_carry *carrier)
{
	struct timeval	cur;
	long			time;

	sem_wait(carrier->msg);
	gettimeofday(&cur, NULL);
	time = get_gap_of_time(cur, carrier->con.start);
	printf("%ldms %d is sleeping\n", time, carrier->philo);
	sem_post(carrier->msg);
	waiting(cur, carrier->con.time_to_sleep);
	sem_wait(carrier->msg);
	gettimeofday(&cur, NULL);
	time = get_gap_of_time(cur, carrier->con.start);
	printf("%ldms %d is thinking\n", time, carrier->philo);
	sem_post(carrier->msg);
}
