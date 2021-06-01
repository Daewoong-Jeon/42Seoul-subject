/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_23_ba_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:27:45 by mac               #+#    #+#             */
/*   Updated: 2021/06/01 15:47:03 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_23_ba_fix_sub3(t_stack **dst, t_stack **src, int *buffer,
		int *flag)
{
	if ((*src)->data < (*src)->next->data && (*src)->next->data
				> (*src)->next->next->data && (*src)->data
				< (*src)->next->next->data)
	{
		swap_list(src, 'b', buffer);
		push_list(dst, src, 'a', buffer);
		swap_list(src, 'b', buffer);
		push_list(dst, src, 'a', buffer);
		push_list(dst, src, 'a', buffer);
		*flag = 1;
	}
	else if ((*src)->data < (*src)->next->data && (*src)->next->data
				< (*src)->next->next->data && (*src)->data
				< (*src)->next->next->data)
	{
		rotate_list(src, -1, 'b', buffer);
		swap_list(src, 'b', buffer);
		push_list(dst, src, 'a', buffer);
		push_list(dst, src, 'a', buffer);
		rotate_list(src, 1, 'b', buffer);
		push_list(dst, src, 'a', buffer);
		*flag = 1;
	}
}

void		sort_23_ba_fix_sub2(t_stack **dst, t_stack **src, int *buffer,
		int *flag)
{
	if ((*src)->data < (*src)->next->data && (*src)->next->data
				> (*src)->next->next->data && (*src)->data
				> (*src)->next->next->data)
	{
		swap_list(src, 'b', buffer);
		push_list(dst, src, 'a', buffer);
		push_list(dst, src, 'a', buffer);
		push_list(dst, src, 'a', buffer);
		*flag = 1;
	}
	else if ((*src)->data > (*src)->next->data && (*src)->next->data
				< (*src)->next->next->data && (*src)->data
				< (*src)->next->next->data)
	{
		rotate_list(src, -1, 'b', buffer);
		swap_list(src, 'b', buffer);
		push_list(dst, src, 'a', buffer);
		rotate_list(src, 1, 'b', buffer);
		push_list(dst, src, 'a', buffer);
		push_list(dst, src, 'a', buffer);
		*flag = 1;
	}
}

void		sort_23_ba_fix_sub1(t_stack **dst, t_stack **src, int *buffer,
		int *flag)
{
	if ((*src)->data > (*src)->next->data && (*src)->next->data
			> (*src)->next->next->data && (*src)->data
			> (*src)->next->next->data)
	{
		push_list(dst, src, 'a', buffer);
		push_list(dst, src, 'a', buffer);
		push_list(dst, src, 'a', buffer);
		*flag = 1;
	}
	else if ((*src)->data > (*src)->next->data && (*src)->next->data
				< (*src)->next->next->data && (*src)->data
				> (*src)->next->next->data)
	{
		push_list(dst, src, 'a', buffer);
		swap_list(src, 'b', buffer);
		push_list(dst, src, 'a', buffer);
		push_list(dst, src, 'a', buffer);
		*flag = 1;
	}
}

void		sort_23_ba_fix_sub(t_stack **dst, t_stack **src, int *buffer)
{
	int			flag;

	flag = 0;
	if (flag == 0)
		sort_23_ba_fix_sub1(dst, src, buffer, &flag);
	if (flag == 0)
		sort_23_ba_fix_sub2(dst, src, buffer, &flag);
	if (flag == 0)
		sort_23_ba_fix_sub3(dst, src, buffer, &flag);
}

void		sort_23_ba_fix(t_stack **dst, t_stack **src, int len, int *buffer)
{
	if (len == 3)
		sort_23_ba_fix_sub(dst, src, buffer);
	else if (len == 1)
		push_list(dst, src, 'a', buffer);
	else
	{
		if ((*src)->data > (*src)->next->data)
		{
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
		else
		{
			swap_list(src, 'b', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
	}
}
