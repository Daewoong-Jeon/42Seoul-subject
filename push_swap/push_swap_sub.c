/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:35:17 by djeon             #+#    #+#             */
/*   Updated: 2021/05/28 21:58:19 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_pivot(t_stack **lst, int len, int min, int *pivot_1)
{
	t_stack			*tmp;
	int				int_tmp;
	int				i;
	int				result;
	int				flag;
	int				num;

	i = 0;
	tmp = *lst;
	printf("hi\n");
	while (1)
	{
		flag = 0;
		num = len;
		while (num--)
		{
			if (flag == 0 && min < tmp->data)
			{
				int_tmp = tmp->data;
				flag = 1;
			}
			else if (flag == 1 && min < tmp->data && int_tmp > tmp->data)
				int_tmp = tmp->data;
			tmp = tmp->next;
		}
		min = int_tmp;
		i++;
		if (i == len / 3 || len == 1)
			*pivot_1 = min;
		if (i >= (len / 3) * 2 || len == 1)
		{
			result = min;
			break ;
		}
	}
	return (result);
}

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
