/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:51:00 by djeon             #+#    #+#             */
/*   Updated: 2021/06/01 17:51:02 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		recursive_0123_ab(t_stack **a_head, int len, int *buffer)
{
	if (len == 2 || len == 3)
	{
		if (len == ft_listsize(*a_head))
			sort_23_ab(a_head, len, buffer);
		else
			sort_23_ab_fix(a_head, len, buffer);
	}
}

void		recursive_0123_ba(t_stack **a_head, t_stack **b_head, int len, int *buffer)
{
	if (len == 2 || len == 3)
	{
		if (len == ft_listsize(*b_head))
			sort_23_ba(a_head, b_head, len, buffer);
		else
			sort_23_ba_fix(a_head, b_head, len, buffer);
	}
	else if (len == 1)
		push_list(a_head, b_head, 'a', buffer);
}

void		pivot_condition_ba(t_stack **a_head, t_stack **b_head, t_tmp *tmp, int *buffer)
{
	if (tmp->pivot.pivot_l > (*b_head)->data)
	{
		rotate_list(b_head, -1, 'b', buffer);
		tmp->len_b++;
	}
	else
	{
		if (tmp->pivot.pivot_h <= (*b_head)->data)
			push_list(a_head, b_head, 'a', buffer);
		else if (tmp->flag_ra == 1 && tmp->pivot.pivot_h > (*b_head)->data)
		{
			push_list(a_head, b_head, 'a', buffer);
			rotate_list(a_head, -1, 'a', buffer);
			tmp->back_a++;
		}
		else if (tmp->flag_ra == 0 && tmp->pivot.pivot_h > (*b_head)->data)
		{
			push_list(a_head, b_head, 'a', buffer);
			tmp->not_back_a++;
		}
		tmp->len_a++;
	}
	if (tmp->len_a - tmp->back_a == tmp->max_pa)
		tmp->flag_ra = 0;
}

void		pivot_condition_ab(t_stack **a_head, t_stack **b_head, t_tmp *tmp, int *buffer)
{
	if (tmp->pivot.pivot_h < (*a_head)->data)
	{
		rotate_list(a_head, -1, 'a', buffer);
		tmp->len_a++;
	}
	else
	{
		if (tmp->pivot.pivot_l >= (*a_head)->data)
			push_list(b_head, a_head, 'b', buffer);
		else if (tmp->flag_rb == 1 && tmp->pivot.pivot_l < (*a_head)->data)
		{
			push_list(b_head, a_head, 'b', buffer);
			rotate_list(b_head, -1, 'b', buffer);
			tmp->back_b++;
		}
		else if (tmp->flag_rb == 0 && tmp->pivot.pivot_l < (*a_head)->data)
		{
			push_list(b_head, a_head, 'b', buffer);
			tmp->not_back_b++;
		}
		tmp->len_b++;
	}
	if (tmp->len_b - tmp->back_b == tmp->max_pb)
		tmp->flag_rb = 0;
}

void		init_struct_tmp(t_tmp *input, int len)
{
	input->len_a = 0;
	input->len_b = 0;
	input->back_a = 0;
	input->back_b = 0;
	input->max_pa = (len / 3 + 1) * 2 + 1;
	input->max_pb = (len / 3 + 1) * 2 + 1;
	input->flag_ra = 1;
	input->flag_rb = 1;
	input->not_back_a = 0;
	input->not_back_b = 0;
}
