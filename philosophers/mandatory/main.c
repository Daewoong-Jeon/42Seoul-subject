/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:27:21 by djeon             #+#    #+#             */
/*   Updated: 2021/08/07 21:58:19 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		time = ((cur.tv_sec - carrier->before[carrier->philo].tv_sec) * 1000000 + cur.tv_usec - carrier->before[carrier->philo].tv_usec) / 1000;
		if (time > carrier->con.time_to_die)
		{
			pthread_mutex_lock(&carrier->arg_dead);
			if (*(carrier->dead) == 0)
			{
				*(carrier->dead) = 1;
				pthread_mutex_unlock(&carrier->fork[carrier->philo]);
				printf("%ldms %d died\n", ((cur.tv_sec - carrier->con.start.tv_sec) * 1000000 + cur.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
			}
			pthread_mutex_unlock(&carrier->arg_dead);
			return (NULL);
		}
		waiting(carrier, cur, 1000, 0);
	}
	return (NULL);
}

void *exec(void *data)
{
	t_carry *carrier;
	pthread_t monitor_id;

	carrier = (t_carry *)data;
	carrier->before[carrier->philo] = carrier->con.start;
	pthread_create(&monitor_id, NULL, monitor, carrier);
	if (carrier->philo % 2 == 0)
		waiting(carrier, carrier->con.start,
				carrier->con.time_to_eat * 1000, 0);
	while (1)
	{
		if (pick_up(carrier, &carrier->fork[carrier->philo],
		&carrier->fork[(carrier->philo + 1) % carrier->con.num_of_philo]) == -1)
			return (NULL);
		if (eating(carrier) == -1)
			return (NULL);
		put_down(carrier, &carrier->fork[carrier->philo],
			&carrier->fork[(carrier->philo + 1) % carrier->con.num_of_philo]);
		if (sleeping_and_thinking(carrier) == -1)
			return (NULL);
	}
	pthread_join(monitor_id, NULL);
	return (NULL);
}

int main(int argc, char **argv)
{
	t_carry *carrier;
	t_arg con;
	int *permit;
	int i;
	int status;

	if (input_arg(&con, argc, argv) == -1)
		return (0);
	if (!(permit = malloc(sizeof(int) * con.num_of_philo)))
		return (0);
	if (init_carrier(&carrier, con, permit) == -1)
		return (0);
	i = -1;
	while (++i < con.num_of_philo)
		permit[i] = 1;
	i = -1;
	while (++i < con.num_of_philo)
	{
		status = pthread_create(&carrier[i].p_thread, NULL, exec,
				&carrier[i]);
		if (status < 0)
			exit(-1);
	}
	i = -1;
	while (++i < con.num_of_philo)
		pthread_join(carrier[i].p_thread, (void *)&status);
	return (0);
}
