/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:27:21 by djeon             #+#    #+#             */
/*   Updated: 2021/07/22 23:34:34 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *odd_exec(void *data)
{
	t_carry *carrier;
	int num_eating;

	carrier = (t_carry *)data;
	carrier->before = carrier->con.start;
	num_eating = 0;
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
	}
	return (0);
}

void *even_exec(void *data)
{
	t_carry *carrier;
	int num_eating;

	carrier = (t_carry *)data;
	carrier->before = carrier->con.start;
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
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_carry *carrier;
	t_arg con;
	int *permit;
	int i;
	int status;

	if (input_arg(&con, argc, argv) == -1)
		return (-1);
	if (!(permit = malloc(sizeof(int) * con.num_of_philo)))
		return (-1);
	i = -1;
	while (++i < con.num_of_philo)
		permit[i] = 1;
	if (init_carrier(&carrier, con, permit) == -1)
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
