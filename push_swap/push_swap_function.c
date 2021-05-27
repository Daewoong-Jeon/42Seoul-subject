/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 22:22:07 by djeon             #+#    #+#             */
/*   Updated: 2021/05/27 18:00:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			swap_list(t_stack **lst, char stack)
{
	int			tmp;

	tmp = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data = tmp;
	if (stack == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void			push_list(t_stack **lst1, t_stack **lst2, char stack)
{
	t_stack		*tmp;

	if (lst2 == NULL || *lst2 == NULL)
		return ;
	tmp = *lst2;
	ft_delete(lst2);
	ft_add(lst1, tmp);
	if ((*lst1)->before != NULL && (*lst1)->next != NULL)
		*lst1 = (*lst1)->before;
	if (stack == 'a')
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

void			rotate_list(t_stack **lst, int direction, char stack)
{
	if ((*lst)->before == NULL || (*lst)->next == NULL)
		return ;
	if (direction == 1)
	{
		*lst = (*lst)->before;
		if (stack == 'a')
			ft_putstr_fd("rra\n", 1);
		else
			ft_putstr_fd("rrb\n", 1);
	}
	else
	{
		*lst = (*lst)->next;
		if (stack == 'a')
			ft_putstr_fd("ra\n", 1);
		else
			ft_putstr_fd("rb\n", 1);
	}
}
