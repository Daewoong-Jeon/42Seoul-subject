/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:35:17 by djeon             #+#    #+#             */
/*   Updated: 2021/05/31 22:27:13 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			input_list(t_stack **a_head, char *argv[], int argc)
{
	t_stack			*tmp;
	char			**str_tmp;
	int				i;

	i = 0;
	if (argc > 1)
	{
		while (++i < argc)
		{
			tmp = ft_new(ft_atoi(argv[i]));
			ft_add(a_head, tmp);
		}
	}
	else
	{
		str_tmp = ft_split(argv[1], ' ');
		while (str_tmp[i] != NULL)
		{
			tmp = ft_new(ft_atoi(str_tmp[i++]));
			ft_add(a_head, tmp);
		}
		argc += (i - 1);
		free(str_tmp);
	}
	return (argc);
}

void		input_str(char **tmp)
{
	tmp[0] = NULL;
	tmp[1] = "sa\n";
	tmp[2] = "sb\n";
	tmp[3] = "ss\n";
	tmp[4] = "pa\n";
	tmp[5] = "pb\n";
	tmp[6] = "ra\n";
	tmp[7] = "rb\n";
	tmp[8] = "rr\n";
	tmp[9] = "rra\n";
	tmp[10] = "rrb\n";
	tmp[11] = "rrr\n";
}

void		print_instructions(int *buffer, char *str)
{
	char		*tmp[12];

	input_str(tmp);
	if (ft_strncmp("pa", str, 2) == 0)
	{
		if (*buffer != 0)
			ft_putstr_fd(tmp[*buffer], 1);
		*buffer = 4;
	}
	else if (ft_strncmp("pb", str, 2) == 0)
	{
		if (*buffer != 0)
			ft_putstr_fd(tmp[*buffer], 1);
		*buffer = 5;
	}
	else if (ft_strncmp("sa", str, 2) == 0)
	{
		if (*buffer != 0 && ft_strncmp("sb", tmp[*buffer], 2) == 0)
		{
			ft_putstr_fd(tmp[3], 1);
			*buffer = 0;
		}
		else
		{
			if (*buffer != 0)
				ft_putstr_fd(tmp[*buffer], 1);
			*buffer = 1;
		}
	}
	else if (ft_strncmp("sb", str, 2) == 0)
	{
		if (*buffer != 0 && ft_strncmp("sa", tmp[*buffer], 2) == 0)
		{
			ft_putstr_fd(tmp[3], 1);
			*buffer = 0;
		}
		else
		{
			if (*buffer != 0)
				ft_putstr_fd(tmp[*buffer], 1);
			*buffer = 2;
		}
	}
	else if (ft_strncmp("ra", str, 2) == 0)
	{
		if (*buffer != 0 && ft_strncmp("rb", tmp[*buffer], 2) == 0)
		{
			ft_putstr_fd(tmp[8], 1);
			*buffer = 0;
		}
		else
		{
			if (*buffer != 0)
				ft_putstr_fd(tmp[*buffer], 1);
			*buffer = 6;
		}
	}
	else if (ft_strncmp("rb", str, 2) == 0)
	{
		if (*buffer != 0 && ft_strncmp("ra", tmp[*buffer], 2) == 0)
		{
			ft_putstr_fd(tmp[8], 1);
			*buffer = 0;
		}
		else
		{
			if (*buffer != 0)
				ft_putstr_fd(tmp[*buffer], 1);
			*buffer = 7;
		}
	}
	else if (ft_strncmp("rra", str, 3) == 0)
	{
		if (*buffer != 0 && ft_strncmp("rrb", tmp[*buffer], 3) == 0)
		{
			ft_putstr_fd(tmp[11], 1);
			*buffer = 0;
		}
		else
		{
			if (*buffer != 0)
				ft_putstr_fd(tmp[*buffer], 1);
			*buffer = 9;
		}
	}
	else if (ft_strncmp("rrb", str, 3) == 0)
	{
		if (*buffer != 0 && ft_strncmp("rra", tmp[*buffer], 3) == 0)
		{
			ft_putstr_fd(tmp[11], 1);
			*buffer = 0;
		}
		else
		{
			if (*buffer != 0)
				ft_putstr_fd(tmp[*buffer], 1);
			*buffer = 10;
		}
	}	
	else if (ft_strncmp("rrr", str, 3) == 0)
	{
		if (*buffer != 0)
			ft_putstr_fd(tmp[*buffer], 1);
		*buffer = 11;
	}
}

int			check_sort(t_stack **lst, int len, char stack)
{
	t_stack		*tmp;

	tmp = *lst;
	while (tmp->next != *lst && len--)
	{
		if (stack == 'a' && tmp->data > tmp->next->data)
			return (0);
		else if (stack == 'b' && tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		ft_quick_sort(int *arr, int len)
{
	int			pivot;
	int			index_left;
	int			index_right;
	int			tmp;

	if (len == 0 || len == 1)
		return ;
	else if (len == 2)
	{
		if (arr[0] > arr[1])
		{
			tmp = arr[0];
			arr[0] = arr[1];
			arr[1] = tmp;
		}
		return ;
	}
	pivot = arr[len - 1];
	index_left = 0;
	index_right = len - 2;
	while (index_right >= index_left)
	{
		while (arr[index_left] < pivot)
			index_left++;
		while (arr[index_right] > pivot)
			index_right--;
		if (index_left < index_right)
		{
			tmp = arr[index_left];
			arr[index_left] = arr[index_right];
			arr[index_right] = tmp;
		}
	}
	tmp = arr[index_left];
	arr[index_left] = arr[len - 1];
	arr[len - 1] = tmp;
	ft_quick_sort(arr, index_left);
	ft_quick_sort(&arr[index_left], len - index_left);
}

t_pivot		find_pivot(t_stack **lst, int len)
{
	t_pivot		result;
	t_stack		*tmp;
	int			*arr;
	int			i;

	tmp = *lst;
	i = len + 1;
	if (!(arr = (int *)malloc(sizeof(int) * len)))
		exit(-1);
	while (--i)
	{
		arr[len - i] = tmp->data;
		tmp = tmp->next;
	}
	ft_quick_sort(arr, len);
	result.pivot_l = arr[len / 3];
	result.pivot_h = arr[len * 2 / 3];
	free(arr);
	return (result);
}

void		sort_23_ba(t_stack **dst, t_stack **src, int len, int *buffer)
{
	if (len == 3)
	{
		if ((*src)->data > (*src)->next->data && (*src)->next->data
				> (*src)->next->next->data && (*src)->data > (*src)->next->next->data)
		{
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
		else if ((*src)->data > (*src)->next->data && (*src)->next->data
					< (*src)->next->next->data && (*src)->data > (*src)->next->next->data)
		{
			push_list(dst, src, 'a', buffer);
			swap_list(src, 'b', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
		else if ((*src)->data < (*src)->next->data && (*src)->next->data
					> (*src)->next->next->data && (*src)->data > (*src)->next->next->data)
		{
			swap_list(src, 'b', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
		else if ((*src)->data > (*src)->next->data && (*src)->next->data
					< (*src)->next->next->data && (*src)->data < (*src)->next->next->data)
		{
			rotate_list(src, 1, 'b', 0, buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
		else if ((*src)->data < (*src)->next->data && (*src)->next->data
					> (*src)->next->next->data && (*src)->data < (*src)->next->next->data)
		{
			rotate_list(src, -1, 'b', 0, buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
		else if ((*src)->data < (*src)->next->data && (*src)->next->data
					< (*src)->next->next->data && (*src)->data < (*src)->next->next->data)
		{
			rotate_list(src, 1, 'b', 0, buffer);
			push_list(dst, src, 'a', buffer);
			swap_list(src, 'b', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
	}
	else if (len == 2)
	{
		if ((*src)->data > (*src)->next->data)
		{
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
		else
		{
			swap_list(src, 'b', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
	}
	else
		push_list(dst, src, 'a', buffer);
}

void		sort_23_ab(t_stack **lst, int len, int *buffer)
{
	if (len == 3)
	{
		if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data && (*lst)->data < (*lst)->next->next->data)
		{
			rotate_list(lst, 1, 'a', 0, buffer);
			swap_list(lst, 'a', buffer);
		}
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				< (*lst)->next->next->data && (*lst)->data < (*lst)->next->next->data)
			swap_list(lst, 'a', buffer);
		else if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data && (*lst)->data > (*lst)->next->next->data)
			rotate_list(lst, 1, 'a', 0, buffer);
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				< (*lst)->next->next->data && (*lst)->data > (*lst)->next->next->data)
			rotate_list(lst, -1, 'a', 0, buffer);
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data && (*lst)->data > (*lst)->next->next->data)
		{
			swap_list(lst, 'a', buffer);
			rotate_list(lst, 1, 'a', 0, buffer);
		}
	}
	else if (len == 2 && (*lst)->data > (*lst)->next->data)
		swap_list(lst, 'a', buffer);
}

void		sort_23_ba_fix(t_stack **dst, t_stack **src, int len, int *buffer)
{	
	if (len == 3)
	{
		if ((*src)->data > (*src)->next->data && (*src)->next->data
				> (*src)->next->next->data && (*src)->data > (*src)->next->next->data)
		{
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
		else if ((*src)->data > (*src)->next->data && (*src)->next->data
					< (*src)->next->next->data && (*src)->data > (*src)->next->next->data)
		{
			push_list(dst, src, 'a', buffer);
			swap_list(src, 'b', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
		else if ((*src)->data < (*src)->next->data && (*src)->next->data
					> (*src)->next->next->data && (*src)->data > (*src)->next->next->data)
		{
			swap_list(src, 'b', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
		else if ((*src)->data > (*src)->next->data && (*src)->next->data
					< (*src)->next->next->data && (*src)->data < (*src)->next->next->data)
		{
			rotate_list(src, -1, 'b', 0, buffer);
			swap_list(src, 'b', buffer);
			push_list(dst, src, 'a', buffer);
			rotate_list(src, 1, 'b', 0, buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
		else if ((*src)->data < (*src)->next->data && (*src)->next->data
					> (*src)->next->next->data && (*src)->data < (*src)->next->next->data)
		{
			swap_list(src, 'b', buffer);
			push_list(dst, src, 'a', buffer);
			swap_list(src, 'b', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
		else if ((*src)->data < (*src)->next->data && (*src)->next->data
					< (*src)->next->next->data && (*src)->data < (*src)->next->next->data)
		{
			rotate_list(src, -1, 'b', 0, buffer);
			swap_list(src, 'b', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
			rotate_list(src, 1, 'b', 0, buffer);
			push_list(dst, src, 'a', buffer);
		}
	}
	else if (len == 1)
		push_list(dst, src, 'a', buffer);
	else
	{
		if ((*src)->data > (*src)->next->data)
		{
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
		else
		{
			swap_list(src, 'b', buffer);
			push_list(dst, src, 'a', buffer);
			push_list(dst, src, 'a', buffer);
		}
	}
}

void		sort_23_ab_fix(t_stack **lst, int len, int *buffer)
{
	if (len == 3)
	{
		if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data && (*lst)->data < (*lst)->next->next->data)
		{
			rotate_list(lst, -1, 'a', 0, buffer);
			swap_list(lst, 'a', buffer);
			rotate_list(lst, 1, 'a', 0, buffer);
		}
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				< (*lst)->next->next->data && (*lst)->data < (*lst)->next->next->data)
			swap_list(lst, 'a', buffer);
		else if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data && (*lst)->data > (*lst)->next->next->data)
		{
			rotate_list(lst, -1, 'a', 0, buffer);
			swap_list(lst, 'a', buffer);
			rotate_list(lst, 1, 'a', 0, buffer);
			swap_list(lst, 'a', buffer);
		}
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				< (*lst)->next->next->data && (*lst)->data > (*lst)->next->next->data)
		{
			swap_list(lst, 'a', buffer);
			rotate_list(lst, -1, 'a', 0, buffer);
			swap_list(lst, 'a', buffer);
			rotate_list(lst, 1, 'a', 0, buffer);
		}
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data && (*lst)->data > (*lst)->next->next->data)
		{
			swap_list(lst, 'a', buffer);
			rotate_list(lst, -1, 'a', 0, buffer);
			swap_list(lst, 'a', buffer);
			rotate_list(lst, 1, 'a', 0, buffer);
			swap_list(lst, 'a', buffer);
		}
	}
	else if (len == 2 && (*lst)->data > (*lst)->next->data)
		swap_list(lst, 'a', buffer);
}
