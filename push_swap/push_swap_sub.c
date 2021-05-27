/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:35:17 by djeon             #+#    #+#             */
/*   Updated: 2021/05/28 01:07:09 by mac              ###   ########.fr       */
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
	else
	{
		if ((*src)->data > (*src)->next->data)
		{
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
		}
		else
		{
			swap_list(src, 'b');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
		}
	}
}

void		push_swap_sort_23(t_stack **lst, int len)
{
	if (len == 3)
	{
		if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data)
		{
			rotate_list(lst, -1, 'a');
			swap_list(lst, 'a');
			rotate_list(lst, 1, 'a');
		}
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				< (*lst)->next->next->data)
			swap_list(lst, 'a');
		else if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data)
		{
			rotate_list(lst, -1, 'a');
			swap_list(lst, 'a');
			rotate_list(lst, 1, 'a');
			swap_list(lst, 'a');
		}
		else if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data)
		{
			swap_list(lst, 'a');
			rotate_list(lst, -1, 'a');
			swap_list(lst, 'a');
			rotate_list(lst, 1, 'a');
		}
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data)
		{
			swap_list(lst, 'a');
			rotate_list(lst, -1, 'a');
			swap_list(lst, 'a');
			rotate_list(lst, 1, 'a');
			swap_list(lst, 'a');
		}
	}
	else if (len == 2 && (*lst)->data > (*lst)->next->data)
		swap_list(lst, 'a');
}
