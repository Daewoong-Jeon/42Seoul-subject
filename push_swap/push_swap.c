/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:56:11 by djeon             #+#    #+#             */
/*   Updated: 2021/06/07 11:50:14 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_sort_ba(t_stack **b_head, t_stack **a_head, int len,
		int *buffer)
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
	push_swap_sort_ab(a_head, b_head, tmp.len_a - tmp.back_a - tmp.not_back_a,
			buffer);
	reverse_rotate_ba(a_head, tmp, 'a', buffer);
	push_swap_sort_ab(a_head, b_head, tmp.back_a + tmp.not_back_a, buffer);
	push_swap_sort_ba(b_head, a_head, tmp.len_b, buffer);
}

void		push_swap_sort_ab(t_stack **a_head, t_stack **b_head, int len,
		int *buffer)
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
	push_swap_sort_ba(b_head, a_head, tmp.len_b - tmp.back_b - tmp.not_back_b,
			buffer);
}

void		push_swap_sort_45(t_stack **a_head, t_stack **b_head, int len,
		int *buffer)
{
	t_stack			*tmp;
	int				num_pa;
	int				tmp_int;
	int				index;

	num_pa = len - 3;
	while (--len >= 3)
		push_list(b_head, a_head, 'b', buffer);
	sort_23_ab(a_head, 3, buffer);
	len = 0;
	while (num_pa--)
	{
		tmp = *a_head;
		index = 0;
		tmp_int = 0;
		while (tmp_int++ < 3 + len)
		{
			if ((*b_head)->data < tmp->data)
				break ;
			tmp = tmp->next;
			index++;
		}
		len++;
		push_swap_sort_45_sub(a_head, b_head, index, buffer);
	}
}

void		push_swap_sort(t_stack **a_head, t_stack **b_head, int len,
		int *buffer)
{
	if (len >= 4 && len <= 5)
		push_swap_sort_45(a_head, b_head, len, buffer);
	else
		push_swap_sort_ab(a_head, b_head, len, buffer);
}

int			main(int argc, char *argv[])
{
	t_stack			*a_head;
	t_stack			*b_head;
	char			*print[12];
	int				*buffer;

	a_head = NULL;
	b_head = NULL;
	if (argc == 1)
		return (0);
	if (!(buffer = (int*)malloc(sizeof(int))))
		return (0);
	*buffer = 0;
	if ((argc = input_list(&a_head, argv, argc)) == -1)
		return (0);
	if (check_sort(a_head, argc - 1) != -1)
		return (0);
	push_swap_sort(&a_head, &b_head, argc - 1, buffer);
	input_str(print);
	if (*buffer != 0)
		ft_putstr_fd(print[*buffer], 1);
	free(buffer);
	return (0);
}
