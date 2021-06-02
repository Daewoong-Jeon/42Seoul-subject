# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djeon <djeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 19:30:48 by djeon             #+#    #+#              #
#    Updated: 2021/06/02 21:31:20 by djeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
HEADER = push_swap.h
CFLAGS = -Wall -Wextra -Werror
NAME_1 = push_swap
NAME_2 = checker
SRC_1 = push_swap.c push_swap_sub.c push_swap_function.c list_function.c \
	  sort_23_ab.c sort_23_ba.c sort_23_ba_sub.c sort_sub.c \
	  print_instructions.c find_pivot.c \
	  tmp.c
SRC_2 = checker.c checker_function.c list_function.c \
	  ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \

OBJECTS_1 = $(SRC_1:.c=.o)
OBJECTS_2 = $(SRC_2:.c=.o)

all : $(NAME_1) $(NAME_2)

$(NAME_1) : $(OBJECTS_1)
	make all -C libft/
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_1) libft/libft.a

$(NAME_2) : $(OBJECTS_2)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_2) libft/libft.a

clean :
	rm -f $(OBJECTS_1)
	rm -f $(OBJECTS_2)
	make clean -C libft/

fclean : clean
	rm -f $(NAME_1)
	rm -f $(NAME_2)
	make fclean -C libft/

re : fclean all
