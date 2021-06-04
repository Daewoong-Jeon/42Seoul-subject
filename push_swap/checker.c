/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:54:23 by djeon             #+#    #+#             */
/*   Updated: 2021/06/04 11:01:26 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_instructions(t_stack **a_head, t_stack **b_head)
{
	char			*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp("Error", line, 5) == 0)
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
	if (input_list(&a_head, argv, argc) == -1)
		return (0);
	len = ft_listsize(a_head);
	if (get_instructions(&a_head, &b_head) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (check_sort(a_head, len) == -1)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	return (0);
}
