# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djeon <djeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 19:30:48 by djeon             #+#    #+#              #
#    Updated: 2021/05/27 19:50:41 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
HEADER = push_swap.h
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = main.c push_swap_function.c push_swap_sub.c list_function.c \
	  tmp.c

OBJECTS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	make all -C libft/
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) libft/libft.a

clean :
	rm -f $(OBJECTS)
	make clean -C libft/

fclean : clean
	rm -f $(NAME)
	make fclean -C libft/

re : fclean all
