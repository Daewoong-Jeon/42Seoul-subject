/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:34:47 by djeon             #+#    #+#             */
/*   Updated: 2021/08/09 17:55:16 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	process_state(t_carry *carrier, int *full)
{
	int	i;
	int	status;

	i = -1;
	while (++i < carrier[0].con.num_of_philo)
	{
		status = -1;
		waitpid(carrier[i].pid, &status, WNOHANG);
		if ((status >> 8) == 0)
			(*full)++;
		if (*full == carrier[0].con.num_of_philo)
			return (-1);
		if ((status >> 8) == 1)
		{
			i = -1;
			while (++i < carrier[0].con.num_of_philo)
				kill(carrier[i].pid, SIGKILL);
			return (-1);
		}
	}
	return (0);
}

void monitor_process(t_carry *carrier)
{
	int full;

	full = 0;
	while (1)
	{
		if (process_state(carrier, &full) == -1)
		{
			free_all();
			return ;
		}
		usleep(100);
	}
}

void *monitor_thread(void *data)
{
	struct timeval	cur;
	t_carry			*carrier;
	long			time;

	carrier = (t_carry *)data;
	while (1)
	{
		if (carrier->con.num_of_eat != -1 && carrier->cur_num_eating >= \
			carrier->con.num_of_eat)
		{
			sem_post(carrier->sem);
			exit(0);
		}
		gettimeofday(&cur, NULL);
		time = get_gap_of_time(cur, carrier->before);
		if (time > carrier->con.time_to_die)
		{
			sem_wait(carrier->arg_dead);
			time = get_gap_of_time(cur, carrier->con.start);
			printf("%ldms %d died\n", time, carrier->philo);
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}
