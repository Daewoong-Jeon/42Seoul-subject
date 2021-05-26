/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:31:04 by mac               #+#    #+#             */
/*   Updated: 2020/12/19 02:26:58 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_int(t_list tmp, va_list tmp1, char format, int *ret)
{
	long long	result;
	int			num;

	tmp.type = format;
	result = va_arg(tmp1, int);
	num = check_num(result);
	if ((tmp.flag / 100 == 1 && tmp.flag2 / 100 == 1) ||
			(tmp.flag % 10 == 1 && tmp.star_mark == 0))
		tmp.flag2 -= 100;
	if (tmp.special == 1 && tmp.star_mark != 1)
		tmp.length = num;
	print_nbr_flag(tmp, result, num, ret);
}

void		print_char_sub(t_list tmp, char result, char pad)
{
	if (tmp.flag / 100 == 1)
	{
		write(1, &result, 1);
		while (tmp.width-- - 1 > 0)
			write(1, &pad, 1);
	}
	else
	{
		while (tmp.width-- - 1 > 0)
			write(1, &pad, 1);
		write(1, &result, 1);
	}
}

void		print_char(t_list tmp, va_list tmp1, char format, int *ret)
{
	char		result;
	char		pad;

	tmp.type = format;
	pad = ' ';
	if (tmp.width > 0)
		*ret += tmp.width;
	else
		*ret += 1;
	if (format == 'c')
		result = va_arg(tmp1, int);
	else
		result = '%';
	if (tmp.flag2 / 100 == 1)
		pad = '0';
	print_char_sub(tmp, result, pad);
}

void		print_str(t_list tmp, va_list tmp1, char format, int *ret)
{
	char		*result;
	int			num;

	tmp.type = format;
	result = va_arg(tmp1, char*);
	if (tmp.flag % 10 == 1 && tmp.star_mark == 0 && tmp.length == 0)
		result = "\0";
	if (result == NULL)
		result = "(null)";
	num = ft_strlen(result);
	if (tmp.special == 1)
		tmp.length = num;
	print_str_flag_sub(tmp, result, num, ret);
}
