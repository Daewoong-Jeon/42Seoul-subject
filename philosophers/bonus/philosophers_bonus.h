/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:42:46 by djeon             #+#    #+#             */
/*   Updated: 2021/07/26 10:27:22 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_arg
{
	int num_of_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_of_eat;
	struct timeval start;
} t_arg;

typedef struct s_carry
{
	int philo;
	sem_t *sem;
	t_arg con;
} t_carry;

int input_arg(t_arg *con, int argc, char **argv);
int init_carrier(t_carry **carrier, t_arg con);

#endif
