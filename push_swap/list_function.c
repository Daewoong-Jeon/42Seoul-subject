/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:10:22 by djeon             #+#    #+#             */
/*   Updated: 2021/05/24 21:24:41 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_delete(t_stack **lst)
{
	t_stack		*tmp1;
	t_stack		*tmp2;

	if (lst == NULL || *lst == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		*lst = NULL;
		return ;
	}
	if ((*lst)->next == (*lst)->before)
	{
		tmp1 = (*lst)->next;
		tmp1->next = NULL;
		tmp1->before = NULL;
		*lst = tmp1;
	}
	else
	{
		tmp1 = (*lst)->before;
		tmp2 = (*lst)->next;
		tmp1->next = tmp2;
		tmp2->before = tmp1;
		*lst = tmp2;
	}
}

t_stack			*ft_new(int content)
{
	t_stack		*result;

	if (!(result = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	result->data = content;
	result->next = NULL;
	result->before = NULL;
	return (result);
}

void			ft_add(t_stack **lst, t_stack *new1)
{
	t_stack		*last;

	last = NULL;
	if (lst == NULL || new1 == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new1;
		(*lst)->next = NULL;
		(*lst)->before = NULL;
		return ;
	}
	if ((*lst)->before == NULL)
	{
		(*lst)->next = new1;
		new1->before = *lst;
	}
	else
	{
		last = (*lst)->before;
		new1->before = last;
		last->next = new1;
	}
	(*lst)->before = new1;
	new1->next = *lst;
}
