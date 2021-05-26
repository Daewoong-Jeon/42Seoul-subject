/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:23:02 by mac               #+#    #+#             */
/*   Updated: 2020/12/19 15:41:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_nbr_flag(t_list tmp, long long result, int num, int *ret)
{
	int			length_flag;

	print_nbr_flag_sub(&tmp, &num, &length_flag, result);
	if (tmp.width > num)
		*ret += tmp.width;
	else
		*ret += num;
	if (tmp.flag / 100 == 1)
	{
		ft_putnbr(tmp, result, length_flag);
		while (tmp.width - num++ > 0)
			write(1, &tmp.pad, 1);
	}
	else
	{
		if (tmp.length == 0 && tmp.pad == '0' && result < 0)
			print_mark(&result);
		while (tmp.width - num++ > 0)
			write(1, &tmp.pad, 1);
		ft_putnbr(tmp, result, length_flag);
	}
}

void		print_str_flag(t_list tmp, char *result, int num, int *ret)
{
	int			length_flag;

	if (*result == '0' && tmp.length == 0 && tmp.flag % 10 == 1
			&& tmp.type != 'p' && tmp.star_mark == 0)
	{
		result[0] = '\0';
		num = 0;
	}
	length_flag = num;
	if ((tmp.length > num) && (tmp.type == 'x' || tmp.type == 'X'))
		length_flag = tmp.length;
	tmp.pad = ' ';
	if (tmp.width > length_flag)
		*ret += tmp.width;
	else
		*ret += length_flag;
	if (tmp.flag2 / 100 == 1 && tmp.length == 0 && tmp.flag / 100 == 0)
		tmp.pad = '0';
	print_str_flag_minus(tmp, num, result, length_flag);
}

void		print_str_flag_sub(t_list tmp, char *result, int num, int *ret)
{
	char		*result2;
	int			i;

	i = -1;
	if (tmp.length > 0 && tmp.length < num)
	{
		result2 = malloc(tmp.length + 1);
		while (++i < tmp.length)
			result2[i] = result[i];
		result2[i] = '\0';
		num = ft_strlen(result2);
		print_str_flag(tmp, result2, num, ret);
		free(result2);
	}
	else
		print_str_flag(tmp, result, num, ret);
}

char		*to_octal(unsigned long long input)
{
	char				*result;
	unsigned long long	tmp;
	int					i;

	i = 0;
	tmp = input;
	while (tmp != 0)
	{
		tmp /= 8;
		i++;
	}
	result = malloc(i + 1);
	result[i] = '\0';
	while (input != 0)
	{
		result[i-- - 1] = '0' + (input % 8);
		input /= 8;
	}
	return (result);
}

char		*to_hexa(unsigned long long input, t_list tmp1)
{
	char				*result;
	int					i;

	i = hexa_num(input);
	tmp1.p_size = i;
	if (tmp1.type == 'p')
		i += 2;
	if (tmp1.length > i - 2 && tmp1.type == 'p')
	{
		result = malloc(tmp1.length + 3);
		while (tmp1.length != i - 2)
			result[tmp1.length - (i++ - 2) + 1] = '0';
		if (tmp1.p_size - 3 > 0)
			i = i + (tmp1.p_size - 3);
	}
	else
		result = malloc(i + 1);
	to_hexa_sub(tmp1, result, i, input);
	return (result);
}
