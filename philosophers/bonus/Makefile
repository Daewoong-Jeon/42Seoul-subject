# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 19:34:17 by djeon             #+#    #+#              #
#    Updated: 2021/08/09 16:14:21 by djeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
HEADER = philosophers.h
CFLAGS = -Wall -Wextra -Werror
NAME = philosophers_bonus
SRC = main.c philo_exec.c monitor.c utils.c
OBJECTS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
