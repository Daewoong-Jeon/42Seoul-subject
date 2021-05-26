/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:37:01 by mac               #+#    #+#             */
/*   Updated: 2020/12/19 15:41:50 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_add(t_list tmp, va_list tmp1, char format, int *ret)
{
	unsigned long long		result;
	char					*result2;
	int						num;

	tmp.type = format;
	result = va_arg(tmp1, unsigned long long);
	result2 = to_hexa(result, tmp);
	if (result == 0 && tmp.flag % 10 == 1 && (tmp.length_index == 0 ||
				(tmp.length == 0 && tmp.star_mark == 0)))
		result2[2] = '\0';
	num = ft_strlen(result2);
	print_str_flag(tmp, result2, num, ret);
	free(result2);
}

void		print_hexa(t_list tmp, va_list tmp1, char format, int *ret)
{
	unsigned int			result;
	char					*result2;
	int						num;

	tmp.type = format;
	result = va_arg(tmp1, unsigned int);
	result2 = to_hexa(result, tmp);
	num = ft_strlen(result2);
	if ((tmp.flag / 100 == 1 && tmp.flag2 / 100 == 1) ||
			(tmp.flag % 10 == 1 && tmp.star_mark == 0))
		tmp.flag2 -= 100;
	print_str_flag(tmp, result2, num, ret);
	free(result2);
}

void		print_octal(t_list tmp, va_list tmp1, char format, int *ret)
{
	unsigned long long		result;
	char					*result2;
	int						num;

	tmp.type = format;
	result = va_arg(tmp1, unsigned long long);
	if (result == 0)
		result2 = "0";
	else
		result2 = to_octal(result);
	num = ft_strlen(result2);
	print_str_flag(tmp, result2, num, ret);
	if (result != 0)
		free(result2);
}

void		print_unsigned(t_list tmp, va_list tmp1, char format, int *ret)
{
	unsigned int	result;
	int				num;

	tmp.type = format;
	result = va_arg(tmp1, unsigned int);
	num = check_num(result);
	if ((tmp.flag / 100 == 1 && tmp.flag2 / 100 == 1) ||
			(tmp.flag % 10 == 1 && tmp.star_mark == 0))
		tmp.flag2 -= 100;
	print_nbr_flag(tmp, result, num, ret);
}
