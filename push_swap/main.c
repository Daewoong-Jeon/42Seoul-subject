/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:56:11 by djeon             #+#    #+#             */
/*   Updated: 2021/05/28 22:10:43 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_sort_ba(t_stack **b_head, t_stack **a_head, int len)
{
	int				pivot_1;
	int				pivot_2;
	int				back_a;
	int				len_a;
	int				len_b;

	if (len == 0 || len == 2 || len == 3)
	{
		if (len == 2 || len == 3)
			push_swap_sort_23_ba(a_head, b_head, len);
		return ;
	}
	len_a = 0;
	len_b = 0;
	back_a = 0;
//	printf("-----------------------b to a-------------------------\n");
//	printf("len : %d\n", len);
	pivot_2 = find_pivot(b_head, len, &pivot_1);
//	printf("pivot1 : %d, pivot2 : %d\n", pivot_1, pivot_2);
//	t_stack *tmp = *a_head;
//	printf("stack a : ");
//	print_list(tmp, 100);
//	tmp = *b_head;
//	printf("stack b : ");
//	print_list(tmp, 100);
	while (len--)
	{
		if (pivot_1 > (*b_head)->data)
		{
			rotate_list(b_head, -1, 'b');
			len_b++;
		}
		else
		{
			if (pivot_2 <= (*b_head)->data)
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
//	tmp = *a_head;
//	printf("stack a : ");
//	print_list(tmp, 100);
//	tmp = *b_head;
//	printf("stack b : ");
//	print_list(tmp, 100);
//	printf("len_a : %d, len_b : %d, back_b : %d\n", len_a, len_b, back_a);
//	printf("min_a : %d, min_b : %d, min_c : %d\n", min_a, min_b, min_c);
	push_swap_sort_ab(a_head, b_head, len_a - back_a);
	len = back_a;
	while (len--)
		rotate_list(a_head, 1, 'a');
	push_swap_sort_ab(a_head, b_head, back_a);
	push_swap_sort_ba(b_head, a_head, len_b);
}

void		push_swap_sort_ab(t_stack **a_head, t_stack **b_head, int len)
{
	int				pivot_1;
	int				pivot_2;
	int				back_b;
	int				len_a;
	int				len_b;

	if (len == 0 || len == 1 || len == 2 || len == 3)
	{
		if (len == 2 || len == 3)
			push_swap_sort_23(a_head, len);
		return ;
	}
	len_a = 0;
	len_b = 0;
	back_b = 0;
	printf("-----------------------a to b-------------------------\n");
	printf("len : %d\n", len);
	pivot_2 = find_pivot(a_head, len, &pivot_1);
	printf("pivot1 : %d, pivot2 : %d\n", pivot_1, pivot_2);
//	t_stack *tmp = *a_head;
//	printf("stack a : ");
//	print_list(tmp, 100);
//	tmp = *b_head;
//	printf("stack b : ");
//	print_list(tmp, 100);
	while (len--)
	{
		if (pivot_2 < (*a_head)->data)
		{
			rotate_list(a_head, -1, 'a');
			len_a++;
		}
		else
		{
			if (pivot_1 >= (*a_head)->data)
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
	char			**str_tmp;

	i = 0;
	b_head = NULL;
	printf("argc : %d\n", argc);
	if (argc > 2)
	{
		while (++i < argc)
		{
			tmp = ft_new(ft_atoi(argv[i]));
			ft_add(&a_head, tmp);
		}
	}
	else if (argc == 2)
	{
		str_tmp = ft_split(argv[1], ' ');
		while (str_tmp[i] != NULL)
		{
			tmp = ft_new(ft_atoi(str_tmp[i++]));
			ft_add(&a_head, tmp);
		}
		argc += (i - 1);
	}
	else
	{
		printf("nothing at input\n");
		return (-1);
	}
//	printf("%d\n", argc);
	push_swap_sort_ab(&a_head, &b_head, argc - 1);
//	printf("------------result-------------\n");
//	tmp = a_head;
//	print_list(tmp, argc);
//	tmp = b_head;
//	print_list(tmp, argc);
	return (0);
}
