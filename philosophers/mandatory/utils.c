/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:51:14 by djeon             #+#    #+#             */
/*   Updated: 2021/08/09 18:31:35 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_gap_of_time(struct timeval a, struct timeval b)
{
	return (((a.tv_sec - b.tv_sec) * 1000000 + a.tv_usec - b.tv_usec) / 1000);
}

void	free_all(t_carry *carrier, t_arg con)
{
	int	i;
	int	status;

	i = -1;
	while (++i < con.num_of_philo)
	{
		pthread_mutex_destroy(&carrier[0].fork[i]);
		pthread_join(carrier[i].p_thread, (void *)&status);
	}
	pthread_mutex_destroy(&carrier[0].arg_dead);
	free(carrier[0].dead);
	free(carrier[0].fork);
	free(carrier[0].permit);
	free(carrier);
}

int	ft_atoi_v2(char *str)
{
	int	result;
	int	i;

	i = -1;
	result = 0;
	if (str == NULL || str[0] == '-')
		return (-1);
	while (str[++i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		if (str[i] < '0' || str[i] > '9' || result < 0)
			return (-1);
	}
	return (result);
}

int	waiting(t_carry *carrier, struct timeval start, long wait_time)
{
	struct timeval	cur;
	long			time;

	while (1)
	{
		if (*(carrier->dead) == 1)
			return (-1);
		gettimeofday(&cur, NULL);
		time = ((cur.tv_sec - start.tv_sec) * 1000000
				+ cur.tv_usec - start.tv_usec);
		if (time > wait_time * 1000)
			break ;
		usleep(100);
	}
	return (0);
}

int	block(t_carry *carrier)
{
	int	right;
	int	left;

	right = (carrier->philo + 1) % carrier->con.num_of_philo;
	left = carrier->philo % carrier->con.num_of_philo;
	while (carrier->permit[right] == 0 || carrier->permit[left] == 0)
	{
		if (*(carrier->dead) == 1)
			return (-1);
		usleep(100);
	}
	carrier->permit[right] = 0;
	carrier->permit[left] = 0;
	return (0);
}
