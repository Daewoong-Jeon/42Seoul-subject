/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:56:11 by djeon             #+#    #+#             */
/*   Updated: 2021/05/31 22:28:07 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_sort_ba(t_stack **b_head, t_stack **a_head, int len, int *buffer)
{
	t_pivot			pivot;
	int				back_a;
	int				len_a;
	int				len_b;
	int				com_len;
	int				flag;
	int				tmp_a;

	if (len == 0 || len == 1 || len == 2 || len == 3)
	{
		if ((len == 2 || len == 3) && len != ft_listsize(*b_head))
			sort_23_ba_fix(a_head, b_head, len, buffer);
		else if (len == 2 || len == 3)
			sort_23_ba(a_head, b_head, len, buffer);
		else if (len == 1)
			push_list(a_head, b_head, 'a', buffer);
		return ;
	}
	if (check_sort(b_head, len, 'b'))
	{
		while (len--)
			push_list(a_head, b_head, 'a', buffer);
		return ;
	}
	len_a = 0;
	len_b = 0;
	back_a = 0;
	flag = 0;
	tmp_a = 0;
	com_len = (len / 3 + 1) * 2 + 1;
	pivot = find_pivot(b_head, len);
	while (*b_head != NULL && len--)
	{
		if (pivot.pivot_l > (*b_head)->data)
		{
			rotate_list(b_head, -1, 'b', 0, buffer);
			len_b++;
		}
		else
		{
			if (pivot.pivot_h <= (*b_head)->data)
				push_list(a_head, b_head, 'a', buffer);
			else if (flag == 1)
			{
				push_list(a_head, b_head, 'a', buffer);
				tmp_a++;
			}
			else
			{
				push_list(a_head, b_head, 'a', buffer);
				rotate_list(a_head, -1, 'a', 0, buffer);
				back_a++;
			}
			len_a++;
		}
		if (len_a - back_a == com_len)
			flag = 1;
		if (len_a == com_len)
			break ;
	}
	len = len_b;
	com_len = ft_listsize(*b_head);
	while (com_len > len && len--)
		rotate_list(b_head, 1, 'b', 0, buffer);
	push_swap_sort_ab(a_head, b_head, len_a - back_a - tmp_a, buffer);
	len = back_a;
	com_len = ft_listsize(*a_head);
	while (com_len > len && len--)
		rotate_list(a_head, 1, 'a', 0, buffer);
	push_swap_sort_ab(a_head, b_head, back_a + tmp_a, buffer);
	push_swap_sort_ba(b_head, a_head, len_b, buffer);
}

void		push_swap_sort_ab(t_stack **a_head, t_stack **b_head, int len, int *buffer)
{
	t_pivot			pivot;
	int				back_b;
	int				len_a;
	int				len_b;
	int				com_len;
	int				flag;
	int				tmp_b;

	if (len == 0 || len == 1 || len == 2 || len == 3)
	{
		if ((len == 2 || len == 3) && len != ft_listsize(*a_head))
			sort_23_ab_fix(a_head, len, buffer);
		else if (len == 2 || len == 3)
			sort_23_ab(a_head, len, buffer);
		return ;
	}
	if (check_sort(a_head, len, 'a'))
		return ;
	len_a = 0;
	len_b = 0;
	back_b = 0;
	flag = 0;
	tmp_b = 0;
	com_len = (len / 3 + 1) * 2 + 1;
	pivot = find_pivot(a_head, len);
	while (*a_head != NULL && len--)
	{
		if (pivot.pivot_h < (*a_head)->data)
		{
			rotate_list(a_head, -1, 'a', 0, buffer);
			len_a++;
		}
		else
		{
			if (pivot.pivot_l >= (*a_head)->data)
				push_list(b_head, a_head, 'b', buffer);
			else if (flag == 1)
			{
				push_list(b_head, a_head, 'b', buffer);
				tmp_b++;
			}
			else
			{
				push_list(b_head, a_head, 'b', buffer);
				rotate_list(b_head, -1, 'b', 0, buffer);
				back_b++;
			}
			len_b++;
		}
		if (len_b - back_b == com_len)
			flag = 1;
		if (len_b == com_len)
			break ;
	}
	rotate_list_sametime(a_head, b_head, len_a, back_b, buffer);
	push_swap_sort_ab(a_head, b_head, len_a, buffer);
	push_swap_sort_ba(b_head, a_head, back_b + tmp_b, buffer);
	push_swap_sort_ba(b_head, a_head, len_b - back_b - tmp_b, buffer);
}

int			main(int argc, char *argv[])
{
	t_stack			*a_head;
	t_stack			*b_head;
	char			*print[12];
	int				*buffer;

	a_head = NULL;
	b_head = NULL;
	buffer = (int*)malloc(sizeof(int));
	input_str(print);
	*buffer = 0;
	argc = input_list(&a_head, argv, argc);
	push_swap_sort_ab(&a_head, &b_head, argc - 1, buffer);
//	t_stack *tmp = a_head;
//	print_list(tmp, 100);
	if (*buffer != 0)
		ft_putstr_fd(print[*buffer], 1);
	free(buffer);
	return (0);
}
