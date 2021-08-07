/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:27:59 by djeon             #+#    #+#             */
/*   Updated: 2021/08/07 21:58:08 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

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
	int cur_num_eating;
	int *dead;
	int *permit;
	int sub;
	struct timeval *before;
	struct timeval start;
	struct timeval end;
	pthread_mutex_t *fork;
	pthread_mutex_t arg_dead;
	pthread_t p_thread;
	t_arg con; 
} t_carry;

int input_arg(t_arg *con, int argc, char **argv);
int init_carrier(t_carry **carrier, t_arg con, int *permit);
int waiting(t_carry *carrier, struct timeval time, long wait_time, int sub);
int block(t_carry *carrier);

int eating(t_carry *carrier);
int sleeping_and_thinking(t_carry *carrier);
int pick_up(t_carry *carrier, pthread_mutex_t *lock1, pthread_mutex_t *lock2);
void put_down(t_carry *carrier, pthread_mutex_t *lock1, pthread_mutex_t *lock2);

#endif