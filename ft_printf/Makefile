# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 14:22:20 by mac               #+#    #+#              #
#    Updated: 2020/12/15 11:29:47 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_printf_print1.c \
	  ft_printf_print2.c ft_printf_utils3.c

OBJECTS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	make all -C libft/
	cp libft/libft.a $(NAME)
	ar rc $@ $(OBJECTS)

%.o:%.c	$(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER)

clean :
	rm -f $(OBJECTS)
	make clean -C libft/

fclean : clean
	rm -f $(NAME)
	make fclean -C libft/

re : fclean all
