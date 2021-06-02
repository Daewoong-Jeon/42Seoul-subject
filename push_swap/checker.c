/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:54:23 by djeon             #+#    #+#             */
/*   Updated: 2021/06/02 21:15:26 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		input_list_checker(t_stack **a_head, char *argv[], int argc)
{
	t_stack			*tmp;
	char			**str_tmp;
	int				i;

	if (argc > 2)
	{
		i = 1;
		while (argv[i] != NULL)
		{
			tmp = ft_new(ft_atoi(argv[i++]));
			ft_add(a_head, tmp);
		}
	}
	else
	{
		i = 0;
		str_tmp = ft_split(argv[1], ' ');
		while (str_tmp[i] != NULL)
		{
			tmp = ft_new(ft_atoi(argv[i++]));
			ft_add(a_head, tmp);
		}
	}
}

void		sort(t_stack **a_head, t_stack **b_head, char *line)
{
	if (ft_strncmp("sa", line, 2) == 0)
		swap_list_checker(a_head);
	else if (ft_strncmp("sb", line, 2) == 0)
		swap_list_checker(b_head);
	else if (ft_strncmp("ss", line, 2) == 0)
	{
		swap_list_checker(a_head);
		swap_list_checker(b_head);
	}
	else if (ft_strncmp("pa", line, 2) == 0)
		push_list_checker(a_head, b_head);
	else if (ft_strncmp("pb", line, 2) == 0)
		push_list_checker(b_head, a_head);
	else if (ft_strncmp("ra", line, 2) == 0)
		rotate_list_checker(a_head, -1);
	else if (ft_strncmp("rb", line, 2) == 0)
		rotate_list_checker(b_head, -1);
	else if (ft_strncmp("rr", line, 2) == 0)
	{
		rotate_list_checker(a_head, -1);
		rotate_list_checker(b_head, -1);
	}
	else if (ft_strncmp("rra", line, 3) == 0)
		rotate_list_checker(a_head, 1);
	else if (ft_strncmp("rrb", line, 3) == 0)
		rotate_list_checker(b_head, 1);
	else if (ft_strncmp("rrr", line, 3) == 0)
	{
		rotate_list_checker(a_head, 1);
		rotate_list_checker(b_head, 1);
	}
}

int			get_instructions(t_stack **a_head, t_stack **b_head)
{
	char			*line;

	while (get_next_line(0, &line) > -1)
	{
		if (ft_strncmp("ERROR", line, 5) == 0)
			return (-1);
		else
			sort(a_head, b_head, line);
		free(line);
	}
	free(line);
	return (0);
}

int			main(int argc, char *argv[])
{
	t_stack			*a_head;
	t_stack			*b_head;

	a_head = NULL;
	b_head = NULL;
	if (argc == 1)
		return (0);
	input_list_checker(&a_head, argv, argc);
	if (get_instructions(&a_head, &b_head) == -1)
	{
		ft_putstr_fd("ERROR\n", 1);
		return (0);
	}
}
