/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:42:46 by djeon             #+#    #+#             */
/*   Updated: 2021/08/08 18:00:06 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>

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
	struct timeval before;
	pid_t pid;
	sem_t *arg_dead;
	sem_t *sem;
	sem_t *msg;
	t_arg con;
} t_carry;

long get_gap_of_time(struct timeval a, struct timeval b);
void handle_signal(int signo);
void free_all(void);
int ft_atoi_v2(char *str);

void eating(t_carry *carrier);
void sleeping_and_thinking(t_carry *carrier);

void monitor_process(t_carry *carrier);
void *monitor_thread(void *data);

#endif
