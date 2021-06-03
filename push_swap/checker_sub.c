/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:00:59 by djeon             #+#    #+#             */
/*   Updated: 2021/06/03 16:51:52 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				sort_sub(t_stack **a_head, t_stack **b_head, char *line)
{
	if (ft_strncmp("pa", line, 3) == 0)
		push_list_checker(a_head, b_head);
	else if (ft_strncmp("pb", line, 3) == 0)
		push_list_checker(b_head, a_head);
	else if (ft_strncmp("ra", line, 3) == 0)
		rotate_list_checker(a_head, -1);
	else if (ft_strncmp("rb", line, 3) == 0)
		rotate_list_checker(b_head, -1);
	else if (ft_strncmp("rr", line, 3) == 0)
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
	else
		return (-1);
	return (0);
}

int				sort(t_stack **a_head, t_stack **b_head, char *line)
{
	if (ft_strncmp("sa", line, 3) == 0)
		swap_list_checker(a_head);
	else if (ft_strncmp("sb", line, 3) == 0)
		swap_list_checker(b_head);
	else if (ft_strncmp("ss", line, 3) == 0)
	{
		swap_list_checker(a_head);
		swap_list_checker(b_head);
	}
	else
		return (sort_sub(a_head, b_head, line));
	return (0);
}

void			swap_list_checker(t_stack **lst)
{
	int			tmp;

	if (*lst == NULL)
		return ;
	tmp = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data = tmp;
}

void			push_list_checker(t_stack **lst1, t_stack **lst2)
{
	t_stack		*tmp;

	if (lst2 == NULL || *lst2 == NULL)
		return ;
	tmp = *lst2;
	ft_delete(lst2);
	ft_add(lst1, tmp);
	if ((*lst1)->before != NULL && (*lst1)->next != NULL)
		*lst1 = (*lst1)->before;
}

void			rotate_list_checker(t_stack **lst, int direction)
{
	if (*lst == NULL || (*lst)->before == NULL || (*lst)->next == NULL)
		return ;
	if (direction == 1)
		*lst = (*lst)->before;
	else
		*lst = (*lst)->next;
}
