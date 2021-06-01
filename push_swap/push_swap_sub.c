/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:35:17 by djeon             #+#    #+#             */
/*   Updated: 2021/06/01 14:58:22 by mac              ###   ########.fr       */
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
