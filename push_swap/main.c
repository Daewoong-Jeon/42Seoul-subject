/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:03:49 by mac               #+#    #+#             */
/*   Updated: 2021/05/30 23:46:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_sort_ba(t_stack **b_head, t_stack **a_head, int len)
{
	t_pivot			pivot;
	int				back_a;
	int				len_a;
	int				len_b;

//	printf("-----------------------b to a-------------------------\n");
	if (len == 0 || len == 1 ||  len == 2 || len == 3)
	{
		if (len == 1 || len == 2 || len == 3)
			push_swap_sort_23_ba(a_head, b_head, len);
		return ;
	}
	len_a = 0;
	len_b = 0;
	back_a = 0;
	pivot = find_pivot(b_head, len);
//	printf("len : %d, pivot1 : %d, pivot2 : %d\n", len, pivot.pivot_l, pivot.pivot_h);
//	t_stack *tmp = *a_head;
//	printf("stack a : ");
//	print_list(tmp, 100);
//	tmp = *b_head;
//	printf("stack b : ");
//	print_list(tmp, 100);
	while (*b_head != NULL && len--)
	{
		if (pivot.pivot_l > (*b_head)->data)
		{
			rotate_list(b_head, -1, 'b');
			len_b++;
		}
		else
		{
			if (pivot.pivot_h <= (*b_head)->data)
				push_list(a_head, b_head, 'a');
			else
			{
				push_list(a_head, b_head, 'a');
				rotate_list(a_head, -1, 'a');
				back_a++;
			}
			len_a++;
		}
	}
	len = len_b;
	while (len--)
		rotate_list(b_head, 1, 'b');
//	printf("len_a : %d, len_b : %d, back_a : %d\n", len_a, len_b, back_a);
	push_swap_sort_ab(a_head, b_head, len_a - back_a);
	len = back_a;
	while (len--)
		rotate_list(a_head, 1, 'a');
//	tmp = *a_head;
//	printf("stack a : ");
//	print_list(tmp, 100);
//	tmp = *b_head;
//	printf("stack b : ");
//	print_list(tmp, 100);
	push_swap_sort_ab(a_head, b_head, back_a);
	push_swap_sort_ba(b_head, a_head, len_b);
}

void		push_swap_sort_ab(t_stack **a_head, t_stack **b_head, int len)
{
	t_pivot			pivot;
	int				back_b;
	int				len_a;
	int				len_b;

//	printf("-----------------------a to b-------------------------\n");
	if (len == 0 || len == 1 || len == 2 || len == 3)
	{
		if (len == 2 || len == 3)
			push_swap_sort_23(a_head, len);
		return ;
	}
	len_a = 0;
	len_b = 0;
	back_b = 0;
	pivot = find_pivot(a_head, len);
//	printf("len : %d, pivot1 : %d, pivot2 : %d\n", len, pivot.pivot_l, pivot.pivot_h);
//	t_stack *tmp = *a_head;
//	printf("stack a : ");
//	print_list(tmp, 100);
//	tmp = *b_head;
//	printf("stack b : ");
//	print_list(tmp, 100);
	while (*a_head != NULL && len--)
	{
		if (pivot.pivot_h < (*a_head)->data)
		{
			rotate_list(a_head, -1, 'a');
			len_a++;
		}
		else
		{
			if (pivot.pivot_l >= (*a_head)->data)
				push_list(b_head, a_head, 'b');
			else
			{
				push_list(b_head, a_head, 'b');
				rotate_list(b_head, -1, 'b');
				back_b++;
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
//	tmp = *a_head;
//	printf("stack a : ");
//	print_list(tmp, 100);
//	tmp = *b_head;
//	printf("stack b : ");
//	print_list(tmp, 100);
//	printf("len_a : %d, len_b : %d, back_b : %d\n", len_a, len_b, back_b);
	push_swap_sort_ab(a_head, b_head, len_a);
	push_swap_sort_ba(b_head, a_head, back_b);
	push_swap_sort_ba(b_head, a_head, len_b - back_b);
}

int			main(int argc, char *argv[])
{
	t_stack			*a_head;
	t_stack			*b_head;
	t_stack			*tmp;
	int				i;

	i = 0;
	b_head = NULL;
	a_head = NULL;
	if (argc >= 2)
	{
		while (++i < argc)
		{
			tmp = ft_new(ft_atoi(argv[i]));
			ft_add(&a_head, tmp);
		}
		if (argc >= 3)
			push_swap_sort_ab(&a_head, &b_head, argc - 1);
	}
	else
		printf("nothing at input\n");
//	printf("------------result-------------\n");
//	tmp = a_head;
//	print_list(tmp, 100);
//	tmp = b_head;
//	print_list(tmp, 100);
	return (0);
}
