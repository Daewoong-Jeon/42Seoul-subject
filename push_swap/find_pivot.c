/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:48:32 by djeon             #+#    #+#             */
/*   Updated: 2021/06/01 17:48:35 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_arr(int *arr, int index_1, int index_2)
{
	int			tmp;

	tmp = arr[index_1];
	arr[index_1] = arr[index_2];
	arr[index_2] = tmp;
}

void		ft_quick_sort(int *arr, int len)
{
	int			pivot;
	int			index_left;
	int			index_right;

	if (len == 0 || len == 1 || len == 2)
	{
		if (len == 2 && arr[0] > arr[1])
			swap_arr(arr, 0, 1);
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
			swap_arr(arr, index_left, index_right);
	}
	swap_arr(arr, index_left, len - 1);
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
		exit(-1);
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
