/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:27:21 by djeon             #+#    #+#             */
/*   Updated: 2021/07/26 14:50:10 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *odd_exec(void *data)
{
	t_carry *carrier;
	int num_eating;

	carrier = (t_carry *)data;
	carrier->before[carrier->philo] = carrier->con.start;
	num_eating = 0;
//	waiting(carrier, carrier->con.start, 1000 * carrier->con.time_to_eat);
//	if (carrier->con.num_of_philo % 2 == 1 && carrier->philo == carrier->con.num_of_philo - 1)
//		waiting(carrier, carrier->con.start, 2000 * carrier->con.time_to_eat);
	while (1)
	{
		if (pick_up(carrier, carrier->right, carrier->left) == -1)
			exit(0);
		if (eating(carrier, &num_eating) == -1)
			exit(0);
		put_down(carrier, carrier->right, carrier->left);
		if (carrier->con.num_of_eat != -1 &&
				num_eating >= carrier->con.num_of_eat)
			return (0);
		if (sleeping_and_thinking(carrier) == -1)
			exit(0);
//		usleep(1000);
//		if (carrier->con.time_to_eat > carrier->con.time_to_sleep)
//			usleep(1000 * (carrier->con.time_to_eat - carrier->con.time_to_sleep));
	}
	return (0);
}

void *even_exec(void *data)
{
	t_carry *carrier;
	int num_eating;

	carrier = (t_carry *)data;
	carrier->before[carrier->philo] = carrier->con.start;
	num_eating = 0;
	while (1)
	{
		if (pick_up(carrier, carrier->left, carrier->right) == -1)
			exit(0);
		if (eating(carrier, &num_eating) == -1)
			exit(0);
		put_down(carrier, carrier->left, carrier->right);
		if (carrier->con.num_of_eat != -1 &&
				num_eating >= carrier->con.num_of_eat)
			return (0);
		if (sleeping_and_thinking(carrier) == -1)
			exit(0);
//		usleep(1000);
//		if (carrier->con.time_to_eat > carrier->con.time_to_sleep)
//			usleep(1000 * (carrier->con.time_to_eat - carrier->con.time_to_sleep));
	}
	return (0);
}

int main(int argc, char **argv)
{
	struct timeval *time;
	t_carry *carrier;
	t_arg con;
	int *permit;
	int i;
	int status;

	if (input_arg(&con, argc, argv) == -1)
		return (-1);
	if (!(permit = malloc(sizeof(int) * con.num_of_philo)))
		return (-1);
	if (!(time = malloc(sizeof(struct timeval) * con.num_of_philo)))
		return (-1);
	i = -1;
	while (++i < con.num_of_philo)
		permit[i] = 1;
	i = -1;
	while (++i < con.num_of_philo)
		time[i] = con.start;
	if (init_carrier(&carrier, con, permit, time) == -1)
		exit(-1);
	i = -1;
	while (++i < con.num_of_philo)
	{
		if (i % 2 == 0)
			status = pthread_create(&carrier[i].p_thread, NULL, even_exec,
					&carrier[i]);
		else
			status = pthread_create(&carrier[i].p_thread, NULL, odd_exec,
					&carrier[i]);
		if (status < 0)
			exit(-1);
	}
	i = -1;
	while (++i < con.num_of_philo)
		pthread_join(carrier[i].p_thread, (void *)&status);
	return (0);
}
