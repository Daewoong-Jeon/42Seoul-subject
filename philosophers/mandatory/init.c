/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 19:50:26 by djeon             #+#    #+#             */
/*   Updated: 2021/08/09 11:44:30 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int input_arg(t_arg *con, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (-1);
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

int init_carrier_sub(t_carry **carrier, t_arg con)
{
	pthread_mutex_t *fork;
	int *permit;
	int i;

	if (!(fork = malloc(sizeof(pthread_mutex_t) * con.num_of_philo)))
		return (-1);
	if (!(permit = malloc(sizeof(int) * con.num_of_philo)))
		return (-1);
	i = -1;
	while (++i < con.num_of_philo)
	{
		pthread_mutex_init(&fork[i], NULL);
		permit[i] = 1;
	}
	i = -1;
	while (++i < con.num_of_philo)
	{
		(*carrier)[i].permit = permit;
		(*carrier)[i].fork = fork;
	}
	return (0);
}

int init_carrier(t_carry **carrier, t_arg con)
{
	pthread_mutex_t dead_lock;
	int i;
	int *dead;

	if (!(*carrier = malloc(sizeof(t_carry) * con.num_of_philo)))
		return (-1);
	if (!(dead = malloc(sizeof(int))))
		return (-1);
	*dead = 0;
	pthread_mutex_init(&dead_lock, NULL);
	i = -1;
	while (++i < con.num_of_philo)
	{
		(*carrier)[i].philo = i;
		(*carrier)[i].cur_num_eating = 0;
		(*carrier)[i].out = 0;
		(*carrier)[i].dead = dead;
		(*carrier)[i].last_eat = con.start;
		(*carrier)[i].arg_dead = dead_lock;
		(*carrier)[i].con = con;
	}
	if (init_carrier_sub(carrier, con) == -1)
		return (-1);
	return (0);
}
