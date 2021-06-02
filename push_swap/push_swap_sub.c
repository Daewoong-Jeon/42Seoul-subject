/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:35:17 by djeon             #+#    #+#             */
/*   Updated: 2021/06/02 15:50:07 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_strlen_2(char **str)
{
	int				result;

	result = 0;
	while (str[result] != 0)
		result++;
	return (result);
}

void		push_swap_sort_45_sub(t_stack **a_head, t_stack **b_head, int index,
		int *buffer)
{
	int				len;
	int				i;

	i = 0;
	len = ft_listsize(*a_head);
	if (len - index == 0 || len - index == 1)
	{
		if (len - index == 1)
			rotate_list(a_head, 1, 'a', buffer);
		push_list(a_head, b_head, 'a', buffer);
		rotate_list(a_head, -1, 'a', buffer);
		if (len - index == 1)
			rotate_list(a_head, -1, 'a', buffer);
	}
	else
	{
		while (i++ < index - 1)
			rotate_list(a_head, -1, 'a', buffer);
		push_list(a_head, b_head, 'a', buffer);
		if (index > 0)
			swap_list(a_head, 'a', buffer);
		while (--i)
			rotate_list(a_head, 1, 'a', buffer);
	}
}

int			check_dup(int **check_arr, int len, int arg)
{
	int				i;

	i = 0;
	check_arr[0][len] = arg;
	while (len--)
	{
		if (check_arr[0][len] == arg)
			return (-1);
	}
	return (0);
}

int			str_to_list(t_stack **lst, char **str, int size)
{
	t_stack			*tmp;
	int				*check_arr;
	int				i;
	int				j;
	long long		int_tmp;

	i = 0;
	if (!(check_arr = (int*)malloc(sizeof(int) * size)))
		return (-1);
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
			if (str[i][j] < '0' || str[i][j++] > '9')
				return (-1);
		int_tmp = ft_atoi(str[i]);
		if (int_tmp > 2147483647 || int_tmp < -2147483648)
			return (-1);
		tmp = ft_new(int_tmp);
		if (check_dup(&check_arr, i++, tmp->data) == -1)
			return (-1);
		ft_add(lst, tmp);
	}
	free(check_arr);
	return (i);
}

int			input_list(t_stack **a_head, char *argv[], int argc)
{
	char			**str_tmp;
	int				i;

	i = 0;
	if (argc > 2)
	{
		if (str_to_list(a_head, &argv[1], argc - 1) == -1)
		{
			ft_putstr_fd("ERROR\n", 1);
			return (-1);
		}
	}
	else
	{
		str_tmp = ft_split(argv[1], ' ');
		i = str_to_list(a_head, str_tmp, ft_strlen_2(str_tmp));
		if (i == -1 || i == 1)
		{
			ft_putstr_fd("ERROR\n", 1);
			return (-1);
		}
		argc += (i - 1);
		free(str_tmp);
	}
	return (argc);
}
