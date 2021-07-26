# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 19:34:17 by djeon             #+#    #+#              #
#    Updated: 2021/07/25 17:49:04 by djeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
HEADER = philosophers.h
CFLAGS = -Wall -Wextra -Werror
NAME = philosophers
SRC = main.c utils.c
OBJECTS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
