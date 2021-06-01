/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:56:11 by djeon             #+#    #+#             */
/*   Updated: 2021/06/01 13:54:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_sort_ba(t_stack **b_head, t_stack **a_head, int len, int *buffer)
{
	t_tmp			tmp;

	if (len == 0 || len == 1 || len == 2 || len == 3)
	{
		recursive_0123_ba(a_head, b_head, len, buffer);
		return ;
	}
	init_struct_tmp(&tmp, len);
	tmp.pivot = find_pivot(b_head, len);
	while (*b_head != NULL && len--)
	{
		pivot_condition_ba(a_head, b_head, &tmp, buffer);
		if (tmp.len_a == tmp.max_pa)
			break ;
	}
	reverse_rotate_ba(b_head, tmp, 'b', buffer);
	push_swap_sort_ab(a_head, b_head, tmp.len_a - tmp.back_a - tmp.not_back_a, buffer);
	reverse_rotate_ba(a_head, tmp, 'a', buffer);
	push_swap_sort_ab(a_head, b_head, tmp.back_a + tmp.not_back_a, buffer);
	push_swap_sort_ba(b_head, a_head, tmp.len_b, buffer);
}

void		push_swap_sort_ab(t_stack **a_head, t_stack **b_head, int len, int *buffer)
{
	t_tmp			tmp;

	if (len == 0 || len == 1 || len == 2 || len == 3)
	{
		recursive_0123_ab(a_head, len, buffer);
		return ;
	}
	init_struct_tmp(&tmp, len);
	tmp.pivot = find_pivot(a_head, len);
	while (*a_head != NULL && len--)
	{
		pivot_condition_ab(a_head, b_head, &tmp, buffer);
		if (tmp.len_b == tmp.max_pb)
			break ;
	}
	reverse_rotate_ab(a_head, b_head, tmp, buffer);
	push_swap_sort_ab(a_head, b_head, tmp.len_a, buffer);
	push_swap_sort_ba(b_head, a_head, tmp.back_b + tmp.not_back_b, buffer);
	push_swap_sort_ba(b_head, a_head, tmp.len_b - tmp.back_b - tmp.not_back_b, buffer);
}

int			main(int argc, char *argv[])
{
	t_stack			*a_head;
	t_stack			*b_head;
	char			*print[12];
	int				*buffer;

	a_head = NULL;
	b_head = NULL;
	if (!(buffer = (int*)malloc(sizeof(int))))
		return (0);
	*buffer = 0;
	argc = input_list(&a_head, argv, argc);
	push_swap_sort_ab(&a_head, &b_head, argc - 1, buffer);
//	t_stack *tmp = a_head;
//	print_list(tmp, 100);
	input_str(print);
	if (*buffer != 0)
		ft_putstr_fd(print[*buffer], 1);
	free(buffer);
	return (0);
}
