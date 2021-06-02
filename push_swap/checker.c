/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:54:23 by djeon             #+#    #+#             */
/*   Updated: 2021/06/03 01:56:50 by mac              ###   ########.fr       */
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

int			get_instructions(t_stack **a_head, t_stack **b_head)
{
	char			*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp("ERROR", line, 5) == 0)
			return (-1);
		else if (line != NULL)
			if (sort(a_head, b_head, line) == -1)
				return (-1);
		free(line);
	}
	free(line);
	return (0);
}

int			check_sort(t_stack *lst, int len)
{
	t_stack			*tmp;
	int				i;

	i = 0;
	tmp = lst;
	while (tmp->next != lst)
	{
		if (tmp->data > tmp->next->data)
			return (-1);
		tmp = tmp->next;
		i++;
	}
	if (len != ++i)
		return (-1);
	return (0);
}

int			main(int argc, char *argv[])
{
	t_stack			*a_head;
	t_stack			*b_head;
	int				len;

	a_head = NULL;
	b_head = NULL;
	if (argc == 1)
		return (0);
	input_list_checker(&a_head, argv, argc);
	len = ft_listsize(a_head);
	if (get_instructions(&a_head, &b_head) == -1)
	{
		ft_putstr_fd("ERROR\n", 1);
		return (0);
	}
	if (check_sort(a_head, len) == -1)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	return (0);
}
