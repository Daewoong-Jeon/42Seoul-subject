/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:42:44 by djeon             #+#    #+#             */
/*   Updated: 2021/07/26 10:27:08 by djeon            ###   ########.fr       */
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
	int i;

	i = -1;
	if (!(*carrier = malloc(sizeof(t_carry) * con.num_of_philo)))
		return (-1);
	while (++i < con.num_of_philo)
	{
		(*carrier)[i].philo = i;
		(*carrier)[i].con = con;
//		(*carrier)[i].sem = sem;
	}
	return (0);
}
