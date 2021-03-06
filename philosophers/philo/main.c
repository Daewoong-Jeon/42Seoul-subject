/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:27:21 by djeon             #+#    #+#             */
/*   Updated: 2021/08/12 13:31:24 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	routine(t_carry *carrier)
{
	int	num_of_philo;

	num_of_philo = carrier->con.num_of_philo;
	if (pick_up(carrier, &carrier->fork[carrier->philo],
			&carrier->fork[(carrier->philo + 1) % num_of_philo]) == -1)
		return (-1);
	if (eating(carrier) == -1)
	{
		put_down(&carrier->fork[carrier->philo],
			&carrier->fork[(carrier->philo + 1) % num_of_philo]);
		return (-1);
	}
	put_down(&carrier->fork[carrier->philo],
		&carrier->fork[(carrier->philo + 1) % num_of_philo]);
	if (sleeping_and_thinking(carrier) == -1)
		return (-1);
	return (0);
}

void	*exec(void *data)
{
	t_carry		*carrier;
	pthread_t	monitor_id;

	carrier = (t_carry *)data;
	pthread_create(&monitor_id, NULL, monitor, carrier);
	if (carrier->philo % 2 == 0)
		waiting(carrier, carrier->con.start, carrier->con.time_to_eat / 2);
	while (1)
	{
		if (routine(carrier) == -1)
			return (NULL);
		usleep(500);
	}
	pthread_join(monitor_id, NULL);
	return (NULL);
}

int	create_thread(t_carry *carrier, t_arg con)
{
	int	i;
	int	status;

	i = -1;
	while (++i < con.num_of_philo)
	{
		status = pthread_create(&carrier[i].p_thread, NULL, exec,
				&carrier[i]);
		if (status < 0)
		{
			free_all(carrier, con);
			return (-1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_carry	*carrier;
	t_arg	con;

	if (input_arg(&con, argc, argv) == -1)
		return (printf("input error\n"));
	if (init_carrier(&carrier, con) == -1)
		return (printf("init failed\n"));
	if (create_thread(carrier, con) == -1)
		return (printf("failed creating thread\n"));
	free_all(carrier, con);
	return (0);
}
