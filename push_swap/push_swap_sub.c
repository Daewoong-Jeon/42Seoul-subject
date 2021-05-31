/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:35:17 by djeon             #+#    #+#             */
/*   Updated: 2021/05/30 23:44:53 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_quick_sort(int *arr, int len)
{
	int			pivot;
	int			index_left;
	int			index_right;
	int			tmp;

	if (len == 0 || len == 1)
		return ;
	else if (len == 2)
	{
		if (arr[0] > arr[1])
		{
			tmp = arr[0];
			arr[0] = arr[1];
			arr[1] = tmp;
		}
		return ;
	}
	pivot = arr[len - 1];
	index_left = 0;
	index_right = len - 2;
	while (index_right >= index_left)
	{
		while (arr[index_left] < pivot)
			index_left++;
		while (arr[index_right] > pivot)
			index_right--;
		if (index_left < index_right)
		{
			tmp = arr[index_left];
			arr[index_left] = arr[index_right];
			arr[index_right] = tmp;
		}
	}
	tmp = arr[index_left];
	arr[index_left] = arr[len - 1];
	arr[len - 1] = tmp;
	ft_quick_sort(arr, index_left);
	ft_quick_sort(&arr[index_left], len - index_left);
}

t_pivot		find_pivot(t_stack **lst, int len)
{
	t_pivot		result;
	t_stack		*tmp;
	int			*arr;
	int			i;

	tmp = *lst;
	i = len + 1;
	if (!(arr = (int *)malloc(sizeof(int) * len)))
		exit (-1);
	while (--i)
	{
		arr[len - i] = tmp->data;
		tmp = tmp->next;
	}
	ft_quick_sort(arr, len);
	result.pivot_l = arr[len / 3];
	result.pivot_h = arr[len * 2 / 3];
	free(arr);
	return (result);
}

void		push_swap_sort_23_ba(t_stack **dst, t_stack **src, int len)
{
	if (len == 3)
	{
		if ((*src)->data > (*src)->next->data && (*src)->next->data
				> (*src)->next->next->data && (*src)->data > (*src)->next->next->data)
		{
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
		}
		else if ((*src)->data > (*src)->next->data && (*src)->next->data
					< (*src)->next->next->data && (*src)->data > (*src)->next->next->data)
		{
			push_list(dst, src, 'a');
			swap_list(src, 'b');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
		}
		else if ((*src)->data < (*src)->next->data && (*src)->next->data
					> (*src)->next->next->data && (*src)->data > (*src)->next->next->data)
		{
			swap_list(src, 'b');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
		}
		else if ((*src)->data > (*src)->next->data && (*src)->next->data
					< (*src)->next->next->data && (*src)->data < (*src)->next->next->data)
		{
			rotate_list(src, -1, 'b');
			swap_list(src, 'b');
			push_list(dst, src, 'a');
			rotate_list(src, 1, 'b');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
		}
		else if ((*src)->data < (*src)->next->data && (*src)->next->data
					> (*src)->next->next->data && (*src)->data < (*src)->next->next->data)
		{
			swap_list(src, 'b');
			push_list(dst, src, 'a');
			swap_list(src, 'b');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
		}
		else if ((*src)->data < (*src)->next->data && (*src)->next->data
					< (*src)->next->next->data && (*src)->data < (*src)->next->next->data)
		{
			rotate_list(src, -1, 'b');
			swap_list(src, 'b');
			push_list(dst, src, 'a');
			push_list(dst, src, 'a');
			rotate_list(src, 1, 'b');
			push_list(dst, src, 'a');
		}
	}
	else if (len == 1)
		push_list(dst, src, 'a');
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
				> (*lst)->next->next->data && (*lst)->data < (*lst)->next->next->data)
		{
			rotate_list(lst, -1, 'a');
			swap_list(lst, 'a');
			rotate_list(lst, 1, 'a');
		}
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				< (*lst)->next->next->data && (*lst)->data < (*lst)->next->next->data)
			swap_list(lst, 'a');
		else if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data && (*lst)->data > (*lst)->next->next->data)
		{
			rotate_list(lst, -1, 'a');
			swap_list(lst, 'a');
			rotate_list(lst, 1, 'a');
			swap_list(lst, 'a');
		}
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				< (*lst)->next->next->data && (*lst)->data > (*lst)->next->next->data)
		{
			swap_list(lst, 'a');
			rotate_list(lst, -1, 'a');
			swap_list(lst, 'a');
			rotate_list(lst, 1, 'a');
		}
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data && (*lst)->data > (*lst)->next->next->data)
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
