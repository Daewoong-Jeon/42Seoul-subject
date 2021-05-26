/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:21:23 by djeon             #+#    #+#             */
/*   Updated: 2021/05/25 20:36:47 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_quick_sort_ab(t_stack **lst1, t_stack **lst2, int len, int pivot)
{
	t_stack			*head_1;
	t_stack			*head_2;
	int				sum_1;
	int				sum_2;
	int				len_1;
	int				len_2;

	sum_1 = 0;
	sum_2 = 0;
	len_1 = 0;
	len_2 = 0;
	printf("(*lst)->data : %d, len : %d, pivot : %d\n", (*lst1)->data, len, pivot);
	print_list(*lst1, 10);
	while (len--)
	{
		if (pivot >= (*lst1)->data)
		{
			sum_2 += (*lst1)->data;
			len_2++;
			push_list(lst2, lst1);
			ft_putstr_fd("pb\n", 1);
		}
		else
		{
			sum_1 += (*lst1)->data;
			len_1++;
			rotate_list(lst1, -1);
			ft_putstr_fd("ra\n", 1);
		}
	}
	len = len_1;
	while (len--)
	{
		rotate_list(lst1, 1);
		ft_putstr_fd("rra\n", 1);
	}
	head_2 = *lst1;
	while (*lst2)
	{
		push_list(lst1, lst2);
		ft_putstr_fd("pa\n", 1);
	}
	head_1 = *lst1;
	print_list(*lst1, 10);
	if (len_2 != 0 && len_2 != 1)
		ft_quick_sort_ab(&head_1, lst2, len_2, sum_2 / len_2);
	if (len_1 != 0 && len_1 != 1)
		ft_quick_sort_ab(&head_2, lst2, len_1, sum_1 / len_1);
}

void		push_swap_sort(t_stack **a_head, t_stack **b_head, int len, int pivot)
{
	ft_quick_sort_ab(a_head, b_head, len, pivot);
}

int			main(int argc, char *argv[])
{
	t_stack			*a_head;
	t_stack			*b_head;
	t_stack			*tmp;
	int				i;
	int				sum;

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
			push_swap_sort(&a_head, &b_head, argc - 1, sum / (argc - 1));
		a_head = a_head->before;
		tmp = a_head;
		print_list(tmp, 22);
		tmp = a_head;
	}
	else
		printf("nothing at input\n");
	return (0);
}
