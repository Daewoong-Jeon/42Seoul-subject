/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:21:23 by djeon             #+#    #+#             */
/*   Updated: 2021/05/26 17:08:48 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void		ft_quick_sort_ab(t_stack **lst1, t_stack **lst2, int len, int pivot)
//{
//	t_stack			*head_1;
//	t_stack			*head_2;
//	int				sum_1;
//	int				sum_2;
//	int				len_1;
//	int				len_2;
//
//	sum_1 = 0;
//	sum_2 = 0;
//	len_1 = 0;
//	len_2 = 0;
//	printf("(*lst)->data : %d, len : %d, pivot : %d\n", (*lst1)->data, len, pivot);
//	print_list(*lst1, 10);
//	while (len--)
//	{
//		if (pivot >= (*lst1)->data)
//		{
//			sum_2 += (*lst1)->data;
//			len_2++;
//			push_list(lst2, lst1);
//			ft_putstr_fd("pb\n", 1);
//		}
//		else
//		{
//			sum_1 += (*lst1)->data;
//			len_1++;
//			rotate_list(lst1, -1);
//			ft_putstr_fd("ra\n", 1);
//		}
//	}
//	len = len_1;
//	while (len--)
//	{
//		rotate_list(lst1, 1);
//		ft_putstr_fd("rra\n", 1);
//	}
//	head_2 = *lst1;
//	while (*lst2)
//	{
//		push_list(lst1, lst2);
//		ft_putstr_fd("pa\n", 1);
//	}
//	head_1 = *lst1;
//	print_list(*lst1, 10);
//	if (len_2 != 0 && len_2 != 1)
//		ft_quick_sort_ab(&head_1, lst2, len_2, sum_2 / len_2);
//	if (len_1 != 0 && len_1 != 1)
//		ft_quick_sort_ab(&head_2, lst2, len_1, sum_1 / len_1);
//}
//
//void		push_swap_sort(t_stack **a_head, t_stack **b_head, int len, int pivot)
//{
//	ft_quick_sort_ab(a_head, b_head, len, pivot);
//}

void		push_swap_sort(t_stack **a_head, t_stack **b_head, int len)
{
	int				pivot_1;
	int				pivot_2;
	int				back_a;
	int				back_b;
	int				len_a;
	int				len_b;

	if (len == 0 || len == 1)
		return ;
	len_a = 0;
	len_b = 0;
	back_b = 0;
	if ((*a_head)->data <= (*a_head)->before->data)
	{
		pivot_1 = (*a_head)->data;
		pivot_2 = (*a_head)->before->data;
	}
	else
	{
		pivot_2 = (*a_head)->data;
		pivot_1 = (*a_head)->before->data;
	}
	t_stack *tmp = *a_head;
	print_list(tmp, 20);
	printf("len : %d, pivot1 : %d, pivot2 : %d\n", len, pivot_1, pivot_2);
	while (len--)
	{
		printf("(*a_head)->data : %d\n", (*a_head)->data);
		if (pivot_2 < (*a_head)->data)
		{
			rotate_list(a_head, -1);
			len_a++;
		}
		else
		{
			if (pivot_1 >= (*a_head)->data)
				push_list(b_head, a_head);
			else
			{
				push_list(b_head, a_head);
				rotate_list(b_head, -1);
				back_b++;
			}
			len_b++;
		}
		if (a_head != NULL && (*a_head)->next != NULL)
			*a_head = (*a_head)->next;
	}
	printf("test\n");
	back_a = len_a;
	while (back_a--)
		rotate_list(a_head, 1);
	while (back_b--)
		rotate_list(a_head, 1);
	push_swap_sort(a_head, b_head, len_a);
//	push_swap_sort(b_head, a_head, len_b);
}

int			main(int argc, char *argv[])
{
	t_stack			*a_head;
	t_stack			*b_head;
	t_stack			*tmp;
	int				i;
//	int				sum;

	i = 0;
//	sum = 0;
	b_head = NULL;
	if (argc >= 2)
	{
		while (++i < argc)
		{
			tmp = ft_new(ft_atoi(argv[i]));
//			sum += tmp->data;
			ft_add(&a_head, tmp);
		}
//		if (argc >= 3)
//			push_swap_sort(&a_head, &b_head, argc - 1, sum / (argc - 1));
//		a_head = a_head->before;
		if (argc >= 3)
			push_swap_sort(&a_head, &b_head, argc - 1);
		tmp = a_head;
		print_list(tmp, 22);
	}
	else
		printf("nothing at input\n");
	return (0);
}
