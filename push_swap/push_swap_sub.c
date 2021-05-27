/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:35:17 by djeon             #+#    #+#             */
/*   Updated: 2021/05/27 20:10:57 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_sort_23_ba(t_stack **dst, t_stack **src, int len)
{
	if (len == 3)
	{
		if ((*src)->data > (*src)->next->data && (*src)->next->data
				> (*src)->next->next->data)
		{
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
		}
		else if ((*src)->data > (*src)->next->data && (*src)->next->data
					< (*src)->next->next->data)
		{
			push_list(dst, src, 'a');
			swap_list(src, 'b');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
		}
		else if ((*src)->data < (*src)->next->data && (*src)->next->data
					> (*src)->next->next->data)
		{
			swap_list(src, 'b');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
		}
		else if ((*src)->data > (*src)->next->data && (*src)->next->data
					< (*src)->next->next->data)
		{
			rotate_list(src, -1, 'b');
			swap_list(src, 'b');
			push_list(dst, src, 'a');
			rotate_list(src, 1, 'b');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
		}
		else if ((*src)->data < (*src)->next->data && (*src)->next->data
					> (*src)->next->next->data)
		{
			swap_list(src, 'b');
			push_list(dst, src, 'a');
			swap_list(src, 'b');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
		}
		else if ((*src)->data < (*src)->next->data && (*src)->next->data
					< (*src)->next->next->data)
		{
			rotate_list(src, -1, 'b');
			swap_list(src, 'b');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
			rotate_list(src, 1, 'b');
			push_list(dst, src, 'a');
		}
	}
}

void		push_swap_sort_23(t_stack **lst, int len, char stack)
{
	if (len == 3)
	{
		if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data)
		{
			rotate_list(lst, -1, stack);
			swap_list(lst, stack);
			rotate_list(lst, 1, stack);
		}
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				< (*lst)->next->next->data)
			swap_list(lst, stack);
		else if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data)
		{
			rotate_list(lst, -1, stack);
			swap_list(lst, stack);
			rotate_list(lst, 1, stack);
			swap_list(lst, stack);
		}
		else if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data)
		{
			swap_list(lst, stack);
			rotate_list(lst, -1, stack);
			swap_list(lst, stack);
			rotate_list(lst, 1, stack);
		}
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data)
		{
			swap_list(lst, stack);
			rotate_list(lst, -1, stack);
			swap_list(lst, stack);
			rotate_list(lst, 1, stack);
			swap_list(lst, stack);
		}
	}
	else if (len == 2 && (*lst)->data > (*lst)->next->data)
		swap_list(lst, stack);
}
