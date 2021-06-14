/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:52:35 by djeon             #+#    #+#             */
/*   Updated: 2021/06/14 20:08:30 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>


int				main(void)
{
	char		*line;

	line = readline("minishell :");
/*
	ft_putstr_fd("minishell $ ", 1);
	while (get_next_line(0, &line) > -1)
	{
		ft_putstr_fd("minishell $ ", 1);
	}
*/
	add_history(line);
}
