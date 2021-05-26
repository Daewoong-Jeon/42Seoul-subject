/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:24:56 by mac               #+#    #+#             */
/*   Updated: 2020/12/20 18:28:23 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		valid_flag(const char format, int *ret)
{
	if (!(format == ' ' || format == '-' || format == '0' || format == '.'
				|| (format >= '0' && format <= '9')))
		*ret = -1;
}

int			hexa_num(unsigned long long input)
{
	int			i;

	i = 0;
	if (input == 0)
		i++;
	while (input != 0)
	{
		input /= 16;
		i++;
	}
	return (i);
}

void		print_nbr_flag_sub(t_list *tmp, int *num, int *length_flag,
		long long result)
{
	tmp->pad = ' ';
	if (tmp->flag2 / 100 == 1 && tmp->length == 0)
		tmp->pad = '0';
	if (tmp->length >= *num)
	{
		*length_flag = 1;
		if (result < 0)
			*num = tmp->length + 1;
		else
			*num = tmp->length;
	}
	if (result == 0 && tmp->flag % 10 == 1 && tmp->length == 0
			&& tmp->star_mark == 0)
		*num = 0;
}

void		print_str_flag_minus(t_list tmp, int num, char *result,
		int length_flag)
{
	if (tmp.flag / 100 == 1)
	{
		while ((tmp.length > num++) && (tmp.type == 'x' || tmp.type == 'X'))
			write(1, "0", 1);
		ft_putstr(result);
		while (tmp.width - length_flag++ > 0)
			write(1, &tmp.pad, 1);
	}
	else
	{
		while (tmp.width - length_flag++ > 0)
			write(1, &tmp.pad, 1);
		while ((tmp.length > num++) && (tmp.type == 'x' || tmp.type == 'X'))
			write(1, "0", 1);
		ft_putstr(result);
	}
}

void		to_hexa_sub(t_list tmp1, char *result, int i,
		unsigned long long input)
{
	char		*match;

	if (tmp1.type == 'x' || tmp1.type == 'p')
		match = "0123456789abcdef";
	else
		match = "0123456789ABCDEF";
	if (tmp1.type == 'p')
	{
		result[0] = '0';
		result[1] = 'x';
	}
	result[i] = '\0';
	if (input == 0)
	{
		if ((tmp1.type == 'p' && (tmp1.flag % 10 == 0 || tmp1.star == 0))
				|| tmp1.type == 'x' || tmp1.type == 'X')
			result[i - 1] = '0';
		else if (tmp1.type == 'p' && (tmp1.width_index == 0 || tmp1.length > 0))
			result[i - 1] = '0';
	}
	while (input != 0)
	{
		result[i-- - 1] = match[input % 16];
		input /= 16;
	}
}
