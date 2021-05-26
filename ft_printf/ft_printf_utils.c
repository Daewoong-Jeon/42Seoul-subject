/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:06:59 by mac               #+#    #+#             */
/*   Updated: 2020/12/20 18:28:35 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_(t_list *tmp, int *index, int *i)
{
	*index = 0;
	*i = 0;
	tmp->flag = 0;
	tmp->flag2 = 0;
	tmp->width = 0;
	tmp->length = 0;
	tmp->type = 0;
	tmp->pad = 0;
	tmp->special = 0;
	tmp->star = 0;
	tmp->star_mark = 0;
	tmp->width_index = 0;
	tmp->p_size = 0;
	tmp->str = 0;
}

void		print_mark(long long *n)
{
	write(1, "-", 1);
	*n *= -1;
}

int			check_num(long long num)
{
	int			result;
	long long	index;

	index = 1;
	result = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		result++;
		num *= -1;
	}
	while (num / index > 0)
	{
		result++;
		index *= 10;
	}
	return (result);
}

void		ft_putnbr(t_list tmp, long long n, int length_flag)
{
	int			num;

	num = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n == 0 && tmp.flag % 10 == 1 && tmp.length == 0 && tmp.star_mark == 0)
		return ;
	if (length_flag == 1)
	{
		num = check_num(n);
		while (tmp.length-- > num)
			write(1, "0", 1);
		length_flag = 0;
	}
	if (n >= 10)
		ft_putnbr(tmp, n / 10, length_flag);
	write(1, &"0123456789"[n % 10], 1);
}

void		index_and_structure(const char format, t_list *tmp, int *index, int *ret)
{
	if (format == ' ')
		write(1, " ", 1);
	if (format == '-' && tmp->flag / 100 != 1 && tmp->flag % 10 == 0)
		tmp->flag += 100;
	else if (format == '-' && tmp->flag % 10 == 1)
		tmp->star_mark = 1;
	if (format == '0' && *index == 0 && tmp->flag % 10 == 0)
		tmp->flag2 = 100;
	if (format == '.')
	{
		tmp->flag += 1;
		tmp->width = *index;
		*index = 0;
	}
	if (format >= '0' && format <= '9')
	{
		if (tmp->flag % 10 != 1 && ((tmp->flag / 10) % 10 != 1))
			tmp->flag += 10;
		*index = (*index * 10) + format - '0';
		if (tmp->flag % 10 == 0)
			tmp->width_index = 1;
		else
			tmp->length_index = 1;
	}
	valid_flag(format, ret);
}
