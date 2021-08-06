/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:42:44 by djeon             #+#    #+#             */
/*   Updated: 2021/08/06 21:44:00 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

int init_carrier(t_carry **carrier, t_arg con)
{
	sem_t *sem;
	sem_t *arg_dead;
	int i;
	int dead;

	i = -1;
	dead = 0;
	if (!(*carrier = malloc(sizeof(t_carry) * con.num_of_philo)))
		return (-1);
	sem = sem_open("/semaphore", O_CREAT | O_EXCL, 0644, con.num_of_philo / 2);
	if (sem == SEM_FAILED)
	{
		sem_unlink("/semaphore");
		printf("open failed\n");
		return (-1);
	}
	arg_dead = sem_open("/semaphore2", O_CREAT | O_EXCL, 0644, 1);
	if (sem == SEM_FAILED)
	{
		sem_unlink("/semaphore2");
		printf("open failed\n");
		return (-1);
	}
	while (++i < con.num_of_philo)
	{
		(*carrier)[i].philo = i;
		(*carrier)[i].dead = &dead;
		(*carrier)[i].cur_num_eating = 0;
		(*carrier)[i].arg_dead = arg_dead;
		(*carrier)[i].sem = sem;
		(*carrier)[i].con = con;
	}
	return (0);
}
