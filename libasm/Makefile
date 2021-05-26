# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djeon <student.42seoul.kr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 14:22:20 by mac               #+#    #+#              #
#    Updated: 2021/03/26 16:35:14 by djeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ASMSRC = ft_strlen.s \
	ft_strcpy.s \
	ft_strcmp.s \
	ft_strdup.s \
	ft_write.s \
	ft_read.s \

OBJ = $(ASMSRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.s
	NASM -f macho64 $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test	: re
	$(CC) $(CFLAGs) main.c -o test -L. -lasm
