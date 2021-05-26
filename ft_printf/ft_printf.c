/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:24:51 by mac               #+#    #+#             */
/*   Updated: 2020/12/20 18:25:35 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_argument(const char *format, va_list tmp1, t_list tmp,
		int *result)
{
	if (*result == -1)
		return ;
	if (format[0] == 'd' || format[0] == 'i')
		print_int(tmp, tmp1, format[0], result);
	else if (format[0] == 'c' || format[0] == '%')
	{
		if (format[0] == '%' && tmp.flag / 100 == 1)
			tmp.flag2 = 0;
		print_char(tmp, tmp1, format[0], result);
	}
	else if (format[0] == 's')
		print_str(tmp, tmp1, format[0], result);
	else if (format[0] == 'p')
		print_add(tmp, tmp1, format[0], result);
	else if (format[0] == 'x' || format[0] == 'X')
		print_hexa(tmp, tmp1, format[0], result);
	else if (format[0] == 'o')
		print_octal(tmp, tmp1, format[0], result);
	else if (format[0] == 'u')
		print_unsigned(tmp, tmp1, format[0], result);
	else
		*result = -1;
}

void		check_flag_sub(t_list *tmp, int index, char str)
{
	if (tmp->flag % 10 == 1 && tmp->star_mark == 0)
		tmp->length = index;
	else if (tmp->star_mark == 0)
		tmp->width = index;
	if (tmp->flag % 10 == 1 && str == '-' && tmp->length > 0
			&& tmp->star_mark == 1)
		tmp->special = 1;
}

int			check_flag(const char *format, va_list tmp1, int *result)
{
	int			i;
	int			j;
	int			index;
	char		*str;
	t_list		tmp;

	str = "\0";
	init_(&tmp, &index, &i);
	while (!((format[++i] >= 'a' && format[i] <= 'z') || format[i] == '%'
				|| (format[i] >= 'A' && format[i] <= 'Z') || format[i] == '\0'))
		if (format[i] == '*')
		{
			str = ft_itoa(va_arg(tmp1, int));
			j = -1;
			tmp.star = 1;
			while (str[++j] != '\0')
				index_and_structure(str[j], &tmp, &index, result);
			tmp.str = str[0];
			free(str);
		}
		else
			index_and_structure(format[i], &tmp, &index, result);
	check_flag_sub(&tmp, index, tmp.str);
	parse_argument(&format[i], tmp1, tmp, result);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			flag;
	int			i;
	int			result;

	result = 0;
	va_start(ap, format);
	i = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			flag = check_flag(&format[i], ap, &result);
			i += flag;
		}
		else
		{
			write(1, &format[i], 1);
			result++;
		}
		if (result == -1)
			return (-1);
	}
	va_end(ap);
	return (result);
}
