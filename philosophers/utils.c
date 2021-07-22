/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:51:14 by djeon             #+#    #+#             */
/*   Updated: 2021/07/22 14:51:47 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_atoi_v2(char *str)
{
	int result;
	int i;

	i = -1;
	result = 0;
	if (str == NULL || str[0] == '-')
	{
		printf("error\n");
		return (-1);
	}
	while (str[++i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		if (str[i] < '0' || str[i] > '9' || result < 0)
		{
			printf("error\n");
			return (-1);
		}
	}
	return (result);
}

int input_arg(t_arg *con, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("error\n");
		return (-1);
	}
	if ((con->num_of_philo = ft_atoi_v2(argv[1])) == -1)
		return (-1);
	if ((con->time_to_die = ft_atoi_v2(argv[2])) == -1)
		return (-1);
	if ((con->time_to_eat = ft_atoi_v2(argv[3])) == -1)
		return (-1);
	if ((con->time_to_sleep = ft_atoi_v2(argv[4])) == -1)
		return (-1);
	if (argv[5] == NULL)
		con->num_of_eat = -1;
	else
	{
		if ((con->num_of_eat = ft_atoi_v2(argv[5])) == -1)
			return (-1);
	}
	gettimeofday(&con->start, NULL);
	return (0);
}

int init_carrier(t_carry **carrier, t_arg con, int *permit)
{
	pthread_mutex_t *mutex_lock;
	int i;

	if (!(*carrier = malloc(sizeof(t_carry) * con.num_of_philo)))
		return (-1);
	if (!(mutex_lock = malloc(sizeof(pthread_mutex_t) * con.num_of_philo)))
		return (-1);
	i = -1;
	while (++i < con.num_of_philo)
		pthread_mutex_init(&mutex_lock[i], NULL);
	i = -1;
	while (++i < con.num_of_philo)
	{
		(*carrier)[i].permit = permit;
		(*carrier)[i].philo = i;
		(*carrier)[i].con = con;
		(*carrier)[i].left = &mutex_lock[i];
		if (i + 1 == con.num_of_philo)
			(*carrier)[i].right = &mutex_lock[0];
		else
			(*carrier)[i].right = &mutex_lock[i + 1];
	}
	return (0);
}

int waiting(t_carry *carrier, struct timeval start, long wait_time)
{
	struct timeval time;

	while (1)
	{
		gettimeofday(&time, NULL);
		if (((time.tv_sec - carrier->before.tv_sec) * 1000000 + time.tv_usec - carrier->before.tv_usec) / 1000 > carrier->con.time_to_die)
		{
			printf("%ldms %d died\n", ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
			return (-1);
		}
		if ((time.tv_sec - start.tv_sec) * 1000000 + time.tv_usec - start.tv_usec > wait_time)
			break ;
		usleep(20);
	}
	return (0);
}

int block(t_carry *carrier)
{
	struct timeval time;

	while (carrier->permit[(carrier->philo + 1) % carrier->con.num_of_philo] == 0
			|| carrier->permit[carrier->philo % carrier->con.num_of_philo] == 0)
	{
		usleep(20);
		gettimeofday(&time, NULL);
		if (((time.tv_sec - carrier->before.tv_sec) * 1000000 + time.tv_usec - carrier->before.tv_usec) / 1000 > carrier->con.time_to_die)
		{
			printf("%ldms %d died\n", ((time.tv_sec - carrier->con.start.tv_sec) * 1000000 + time.tv_usec - carrier->con.start.tv_usec) / 1000, carrier->philo);
			return (-1);
		}
	}
	carrier->permit[(carrier->philo + 1) % carrier->con.num_of_philo] = 0;
	carrier->permit[carrier->philo % carrier->con.num_of_philo] = 0;
	return (0);
}
