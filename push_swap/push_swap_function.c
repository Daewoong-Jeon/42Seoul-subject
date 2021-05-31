/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 22:22:07 by djeon             #+#    #+#             */
/*   Updated: 2021/05/31 21:52:16 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			rotate_list_sametime(t_stack **a, t_stack **b, int len_1, int len_2, int *buffer)
{
	int			com_len_1;
	int			com_len_2;
	int			len_tmp;

	com_len_1 = ft_listsize(*a);
	com_len_2 = ft_listsize(*b);
	if (len_1 == com_len_1 || len_2 == com_len_2)
	{
		len_tmp = len_1;
		while (com_len_1 > len_tmp && len_tmp--)
			rotate_list(a, 1, 'a', 0, buffer);
		len_tmp = len_2;
		while (com_len_2 > len_tmp && len_tmp--)
			rotate_list(b, 1, 'b', 0, buffer);
	}
	else
	{
		if (len_1 > len_2)
		{
			len_tmp = len_1 - len_2;
			while (len_2--)
			{
				rotate_list(a, 1, 'a', 1, buffer);
				rotate_list(b, 1, 'b', 1, buffer);
				print_instructions(buffer, "rrr\n");
			}
			while (len_tmp--)
				rotate_list(a, 1, 'a', 0, buffer);
		}
		else
		{
			len_tmp = len_2 - len_1;
			while (len_1--)
			{
				rotate_list(a, 1, 'a', 1, buffer);
				rotate_list(b, 1, 'b', 1, buffer);
				print_instructions(buffer, "rrr\n");
			}
			while (len_tmp--)
				rotate_list(b, 1, 'b', 0, buffer);
		}
	}
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

void			rotate_list(t_stack **lst, int direction, char stack, int same, int *buffer)
{
	if ((*lst)->before == NULL || (*lst)->next == NULL)
		return ;
	if (direction == 1)
	{
		*lst = (*lst)->before;
		if (stack == 'a' && same == 0)
			print_instructions(buffer, "rra\n");
		else if (same == 0)
			print_instructions(buffer, "rrb\n");
	}
	else
	{
		*lst = (*lst)->next;
		if (stack == 'a' && same == 0)
			print_instructions(buffer, "ra\n");
		else if (same == 0)
			print_instructions(buffer, "rb\n");
	}
}
