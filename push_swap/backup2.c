/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:03:49 by mac               #+#    #+#             */
/*   Updated: 2021/05/28 16:44:09 by djeon            ###   ########.fr       */
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
	printf("-----------------------b to a-------------------------\n");
	printf("len : %d, pivot1 : %d, pivot2 : %d\n", len, pivot_1, pivot_2);
	t_stack *tmp = *a_head;
	printf("stack a : ");
	print_list(tmp, 100);
	tmp = *b_head;
	printf("stack b : ");
	print_list(tmp, 100);
	while (len--)
	{
		if (pivot_1 > (*b_head)->data)
		{
			if (*b_head != NULL)
				sum_a += (*b_head)->data;
			rotate_list(b_head, -1, 'b');
			len_b++;
		}
		else
		{
			if (pivot_2 <= (*b_head)->data)
			{
				if (*b_head != NULL)
					sum_c += (*b_head)->data;
				push_list(a_head, b_head, 'a');
			}
			else
			{
				if (*b_head != NULL)
					sum_b += (*b_head)->data;
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
	tmp = *a_head;
	printf("stack a : ");
	print_list(tmp, 100);
	tmp = *b_head;
	printf("stack b : ");
	print_list(tmp, 100);
	printf("len_a : %d, len_b : %d, back_b : %d\n", len_a, len_b, back_a);
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
	printf("-----------------------a to b-------------------------\n");
	printf("len : %d, pivot1 : %d, pivot2 : %d\n", len, pivot_1, pivot_2);
	t_stack *tmp = *a_head;
	printf("stack a : ");
	print_list(tmp, 100);
	tmp = *b_head;
	printf("stack b : ");
	print_list(tmp, 100);
	while (len--)
	{
		printf("data : %d\n", (*a_head)->data);
		if (pivot_2 < (*a_head)->data)
		{
			if (*a_head != NULL)
			{
				sum_c += (*a_head)->data;
				printf("sum_c : %lld, (*a_head)->data : %d\n", sum_c, (*a_head)->data);
			}
			rotate_list(a_head, -1, 'a');
			len_a++;
		}
		else
		{
			if (pivot_1 >= (*a_head)->data)
			{
				if (*a_head != NULL)
					sum_a += (*a_head)->data;
				push_list(b_head, a_head, 'b');
			}
			else
			{
				if (*a_head != NULL)
					sum_b += (*a_head)->data;
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
	tmp = *a_head;
	printf("stack a : ");
	print_list(tmp, 100);
	tmp = *b_head;
	printf("stack b : ");
	print_list(tmp, 100);
	printf("len_a : %d, len_b : %d, back_b : %d\n", len_a, len_b, back_b);
	printf("sum_a : %lld, sum_b : %lld, sum_c : %lld\n", sum_a, sum_b, sum_c);
	push_swap_sort_ab(a_head, b_head, len_a, sum_c);
//	push_swap_sort_ba(b_head, a_head, back_b, sum_b);
//	push_swap_sort_ba(b_head, a_head, len_b - back_b, sum_a);
}

int			main(int argc, char *argv[])
{
	t_stack			*a_head;
	t_stack			*b_head;
	t_stack			*tmp;
	int				i;
	long long		sum;
	char			**str_tmp;

	i = 0;
	sum = 0;
	b_head = NULL;
	printf("argc : %d\n", argc);
	if (argc > 2)
	{
		while (++i < argc)
		{
			tmp = ft_new(ft_atoi(argv[i]));
			sum += tmp->data;
			ft_add(&a_head, tmp);
		}
	}
//	else if (argc == 2)
	else
	{
		str_tmp = ft_split(argv[1], ' ');
		while (str_tmp[i] != NULL)
		{
			tmp = ft_new(ft_atoi(str_tmp[i++]));
			sum += tmp->data;
			ft_add(&a_head, tmp);
		}
		argc += (i - 1);
	}
//	else
//		printf("nothing at input\n");
	printf("%d\n", argc);
	push_swap_sort_ab(&a_head, &b_head, argc - 1, sum);
	printf("------------result-------------\n");
	tmp = a_head;
	print_list(tmp, argc);
	tmp = b_head;
	print_list(tmp, argc);
	return (0);
}
