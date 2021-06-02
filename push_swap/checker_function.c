/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:00:59 by djeon             #+#    #+#             */
/*   Updated: 2021/06/02 21:03:15 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			swap_list_checker(t_stack **lst)
{
	int			tmp;

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
	if ((*lst)->before == NULL || (*lst)->next == NULL)
		return ;
	if (direction == 1)
		*lst = (*lst)->before;
	else
		*lst = (*lst)->next;
}
