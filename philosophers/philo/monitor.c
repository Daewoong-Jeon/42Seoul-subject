/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:46:08 by djeon             #+#    #+#             */
/*   Updated: 2021/08/09 18:34:50 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	kill_philo(t_carry *carrier, struct timeval cur)
{
	long	time;

	pthread_mutex_lock(&carrier->arg_dead);
	if (*(carrier->dead) == 0)
	{
		*(carrier->dead) = 1;
		pthread_mutex_unlock(&carrier->fork[carrier->philo]);
		time = get_gap_of_time(cur, carrier->con.start);
		printf("%ldms %d died\n", time, carrier->philo);
	}
	pthread_mutex_unlock(&carrier->arg_dead);
}

void	*monitor(void *data)
{
	struct timeval	cur;
	t_carry			*carrier;
	long			time;

	carrier = (t_carry *)data;
	while (1)
	{
		if (carrier->con.num_of_eat != -1 \
			&& carrier->cur_num_eating >= carrier->con.num_of_eat)
		{
			carrier->out = 1;
			return (NULL);
		}
		gettimeofday(&cur, NULL);
		time = get_gap_of_time(cur, carrier->last_eat);
		if (time > carrier->con.time_to_die)
		{
			kill_philo(carrier, cur);
			return (NULL);
		}
		waiting(carrier, cur, 1);
	}
}
