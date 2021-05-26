/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 13:20:51 by mac               #+#    #+#             */
/*   Updated: 2021/03/27 13:29:31 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main(int argc, char *argv[])
{
	char	s[50];
	int		fd;

	fd = open(argv[1], O_RDONLY);
	printf(BLUE"______TESTING <ft_strlen>______\n"RESET);
	printf(CYAN"[case 1] "RESET"ft_strlen = %zu\n", ft_strlen(""));
	printf(CYAN"[case 2] "RESET"ft_strlen = %zu\n", ft_strlen("djeon!"));
	printf(BLUE"______TESTING <ft_strcmp>______\n"RESET);
	printf(CYAN"[case 1] "RESET"ft_strcpy = %s\n", ft_strcpy(s, ""));
	printf(CYAN"[case 2] "RESET"ft_strcpy = %s\n", ft_strcpy(s, "djeon!"));
	printf(BLUE"______TESTING <ft_strcmp>______\n"RESET);
	printf(CYAN"[case 1] "RESET"ft_strcmp = %d\n", ft_strcmp("a", "a"));
	printf(CYAN"[case 2] "RESET"ft_strcmp = %d\n", ft_strcmp("a", "b"));
	printf(BLUE"______TESTING <ft_wrtie>______\n"RESET);
	printf(CYAN"[case 1] "RESET"ft_write = %zd\n", ft_write(1, "djeon!", 10));
	printf(CYAN"[case 2] "RESET"ft_write = %zd\n", ft_write(1, "djeon!", 3));
	printf(BLUE"______TESTING <ft_read>______\n"RESET);
	printf(CYAN"[case 1] "RESET"ft_read = %zd\n", ft_read(fd, s, 20));
	printf(BLUE"______TESTING <ft_strdup>______\n"RESET);
	printf(CYAN"[case 1] "RESET"ft_strdup = %s\n", ft_strdup(""));
	printf(CYAN"[case 2] "RESET"ft_strdup = %s\n", ft_strdup("djeon!"));
	return (1);
}
