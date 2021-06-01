/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 22:22:07 by djeon             #+#    #+#             */
/*   Updated: 2021/06/01 17:49:47 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			reverse_rotate_ba(t_stack **lst, t_tmp tmp, char stack, int *buffer)
{
	int			len;
	int			stack_size;

	stack_size = ft_listsize(*lst);
	if (stack == 'a')
	{
		len = tmp.back_a;
		while (stack_size > tmp.back_a && len--)
			rotate_list(lst, 1, stack, buffer);
	}
	else if (stack == 'b')
	{
		len = tmp.len_b;
		while (stack_size > tmp.len_b && len--)
			rotate_list(lst, 1, stack, buffer);
	}
}

void			reverse_rotate_ab(t_stack **a, t_stack **b, t_tmp tmp, int *buffer)
{
	t_stack		**stack_tmp;
	char		stack;
	int			len_1;
	int			len_2;
	int			len_tmp;

	len_1 = tmp.back_b;
	len_2 = tmp.len_a;
	stack = 'b';
	stack_tmp = b;
	if (tmp.len_a > tmp.back_b)
	{
		len_1 = tmp.len_a;
		len_2 = tmp.back_b;
		stack = 'a';
		stack_tmp = a;
	}
	len_tmp = len_1 - len_2;
	while (len_2--)
	{
		rotate_list(a, 1, 'a', buffer);
		rotate_list(b, 1, 'b', buffer);
	}
	while (len_tmp--)
		rotate_list(stack_tmp, 1, stack, buffer);
}

void			swap_list(t_stack **lst, char stack, int *buffer)
{
	int			tmp;

	tmp = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data = tmp;
	if (stack == 'a')
		print_instructions(buffer, "sa\n");
	else
		print_instructions(buffer, "sb\n");
}

void			push_list(t_stack **lst1, t_stack **lst2, char stack, int *buffer)
{
	t_stack		*tmp;

	if (lst2 == NULL || *lst2 == NULL)
		return ;
	tmp = *lst2;
	ft_delete(lst2);
	ft_add(lst1, tmp);
	if ((*lst1)->before != NULL && (*lst1)->next != NULL)
		*lst1 = (*lst1)->before;
	if (stack == 'a')
		print_instructions(buffer, "pa\n");
	else
		print_instructions(buffer, "pb\n");
}

void			rotate_list(t_stack **lst, int direction, char stack, int *buffer)
{
	if ((*lst)->before == NULL || (*lst)->next == NULL)
		return ;
	if (direction == 1)
	{
		*lst = (*lst)->before;
		if (stack == 'a')
			print_instructions(buffer, "rra\n");
		else
			print_instructions(buffer, "rrb\n");
	}
	else
	{
		*lst = (*lst)->next;
		if (stack == 'a')
			print_instructions(buffer, "ra\n");
		else
			print_instructions(buffer, "rb\n");
	}
}
