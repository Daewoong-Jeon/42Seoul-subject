/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:03:49 by mac               #+#    #+#             */
/*   Updated: 2021/05/28 01:22:05 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_sort_ba(t_stack **b_head, t_stack **a_head, int len, long long sum)
{
	int				pivot_1;
	int				pivot_2;
	int				back_a;
	int				len_a;
	int				len_b;
	long long		sum_a;
	long long		sum_b;
	long long		sum_c;

	if (len == 0 || len == 2 || len == 3)
	{
		if (len == 2 || len == 3)
			push_swap_sort_23_ba(a_head, b_head, len);
		return ;
	}
	sum_a = 0;
	sum_b = 0;
	sum_c = 0;
	len_a = 0;
	len_b = 0;
	back_a = 0;
	pivot_1 = (sum / len) * 2 / 3;
	pivot_2 = (sum / len) * 4 / 3;
	while (len--)
	{
		if (pivot_1 > (*b_head)->data)
		{
			rotate_list(b_head, -1, 'b');
			len_b++;
			if (*b_head != NULL)
				sum_a += (*b_head)->data;
		}
		else
		{
			if (pivot_2 <= (*b_head)->data)
			{
				push_list(a_head, b_head, 'a');
				if (*b_head != NULL)
					sum_c += (*b_head)->data;
			}
			else
			{
				push_list(a_head, b_head, 'a');
				rotate_list(a_head, -1, 'a');
				back_a++;
				if (*b_head != NULL)
					sum_b += (*b_head)->data;
			}
			len_a++;
		}
	}
	len = len_b;
	while (len--)
		rotate_list(b_head, 1, 'b');
	push_swap_sort_ab(a_head, b_head, len_a - back_a, sum_c);
	len = back_a;
	while (len--)
		rotate_list(a_head, 1, 'a');
	push_swap_sort_ab(a_head, b_head, back_a, sum_b);
	push_swap_sort_ba(b_head, a_head, len_b, sum_a);
}

void		push_swap_sort_ab(t_stack **a_head, t_stack **b_head, int len, long long sum)
{
	int				pivot_1;
	int				pivot_2;
	int				back_b;
	int				len_a;
	int				len_b;
	long long		sum_a;
	long long		sum_b;
	long long		sum_c;

	if (len == 0 || len == 1 || len == 2 || len == 3)
	{
		if (len == 2 || len == 3)
			push_swap_sort_23(a_head, len);
		return ;
	}
	sum_a = 0;
	sum_b = 0;
	sum_c = 0;
	len_a = 0;
	len_b = 0;
	back_b = 0;
	pivot_1 = (sum / len) * 2 / 3;
	pivot_2 = (sum / len) * 4 / 3;
	while (len--)
	{
		if (pivot_2 < (*a_head)->data)
		{
			rotate_list(a_head, -1, 'a');
			len_a++;
			if (*a_head != NULL)
				sum_c += (*a_head)->data;
		}
		else
		{
			if (pivot_1 >= (*a_head)->data)
			{
				push_list(b_head, a_head, 'b');
				if (*a_head != NULL)
					sum_a += (*a_head)->data;
			}
			else
			{
				push_list(b_head, a_head, 'b');
				rotate_list(b_head, -1, 'b');
				back_b++;
				if (*a_head != NULL)
					sum_b += (*a_head)->data;
			}
			len_b++;
		}
	}
	len = len_a;
	while (len--)
		rotate_list(a_head, 1, 'a');
	len = back_b;
	while (len--)
		rotate_list(b_head, 1, 'b');
	push_swap_sort_ab(a_head, b_head, len_a, sum_c);
	push_swap_sort_ba(b_head, a_head, back_b, sum_b);
	push_swap_sort_ba(b_head, a_head, len_b - back_b, sum_a);
}

int			main(int argc, char *argv[])
{
	t_stack			*a_head;
	t_stack			*b_head;
	t_stack			*tmp;
	int				i;
	long long		sum;

	i = 0;
	sum = 0;
	b_head = NULL;
	if (argc >= 2)
	{
		while (++i < argc)
		{
			tmp = ft_new(ft_atoi(argv[i]));
			sum += tmp->data;
			ft_add(&a_head, tmp);
		}
		if (argc >= 3)
			push_swap_sort_ab(&a_head, &b_head, argc - 1, sum);
	}
	else
		printf("nothing at input\n");
	return (0);
}
