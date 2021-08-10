/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:42:44 by djeon             #+#    #+#             */
/*   Updated: 2021/08/10 13:51:34 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

long	get_gap_of_time(struct timeval a, struct timeval b)
{
	return (((a.tv_sec - b.tv_sec) * 1000000 + a.tv_usec - b.tv_usec) / 1000);
}

void	handle_signal(int signo)
{
	if (signo == SIGINT)
	{
		free_all();
		exit(0);
	}
}

void	free_all(void)
{
	sem_unlink("/semaphore");
	sem_unlink("/semaphore2");
	sem_unlink("/semaphore3");
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

void	waiting(struct timeval start, long wait_time)
{
	struct timeval	cur;
	long			time;

	while (1)
	{
		gettimeofday(&cur, NULL);
		time = ((cur.tv_sec - start.tv_sec) * 1000000
				+ cur.tv_usec - start.tv_usec);
		if (time > wait_time * 1000)
			break ;
		usleep(500);
	}
}
