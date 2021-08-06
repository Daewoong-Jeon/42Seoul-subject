/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:51:14 by djeon             #+#    #+#             */
/*   Updated: 2021/08/06 11:53:40 by djeon            ###   ########.fr       */
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
	pthread_mutex_t *fork;
	pthread_mutex_t dead_lock;
	struct timeval *time;
	int i;
	int *dead;

	if (!(dead = malloc(sizeof(int))))
		return (-1);
	if (!(*carrier = malloc(sizeof(t_carry) * con.num_of_philo)))
		return (-1);
	if (!(fork = malloc(sizeof(pthread_mutex_t) * con.num_of_philo)))
		return (-1);
	if (!(time = malloc(sizeof(struct timeval) * con.num_of_philo)))
		return (-1);
	*dead = 0;
	i = -1;
	while (++i < con.num_of_philo)
		pthread_mutex_init(&fork[i], NULL);
	pthread_mutex_init(&dead_lock, NULL);
	i = -1;
	while (++i < con.num_of_philo)
	{
		(*carrier)[i].philo = i;
		(*carrier)[i].cur_num_eating = 0;
		(*carrier)[i].dead = dead;
		(*carrier)[i].permit = permit;
		(*carrier)[i].before = time;
		(*carrier)[i].fork = fork;
		(*carrier)[i].arg_dead = dead_lock;
		(*carrier)[i].con = con;
	}
	return (0);
}

int waiting(t_carry *carrier, struct timeval start, long wait_time, int sub)
{
	struct timeval cur;

	while (1)
	{
		if (*(carrier->dead) == 1)
			return (-1);
		gettimeofday(&cur, NULL);
		if ((cur.tv_sec - start.tv_sec) * 1000000 + cur.tv_usec - start.tv_usec > wait_time - sub)
			break ;
		usleep(100);
	}
	return (0);
}

int block(t_carry *carrier)
{
	while (carrier->permit[(carrier->philo + 1) % carrier->con.num_of_philo] == 0
			|| carrier->permit[carrier->philo % carrier->con.num_of_philo] == 0)
	{
		if (*(carrier->dead) == 1)
			return (-1);
		usleep(100);
	}
	carrier->permit[(carrier->philo + 1) % carrier->con.num_of_philo] = 0;
	carrier->permit[carrier->philo % carrier->con.num_of_philo] = 0;
	return (0);
}
