/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:25:36 by mac               #+#    #+#             */
/*   Updated: 2020/12/20 18:26:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include "./libft/libft.h"

typedef struct		s_list
{
	int				flag;
	int				flag2;
	int				width;
	int				length;
	char			type;
	char			pad;
	char			str;
	int				special;
	int				star;
	int				star_mark;
	int				width_index;
	int				length_index;
	int				p_size;
}					t_list;

int					ft_printf(const char *format, ...);
int					check_flag(const char *format, va_list tmp1, int *result);
void				check_flag_sub(t_list *tmp, int index, char str);
void				parse_argument(const char *format, va_list tmp1,
		t_list tmp, int *result);
int					check_num(long long num);
void				print_mark(long long *n);
void				ft_putnbr(t_list tmp, long long n, int length_flag);
void				init_(t_list *tmp, int *index, int *i);
char				*to_octal(unsigned long long input);
char				*to_hexa(unsigned long long input, t_list tmp1);
void				to_hexa_sub(t_list tmp1, char *result, int i,
		unsigned long long input);
int					hexa_num(unsigned long long input);
void				print_str_flag(t_list tmp, char *result, int num, int *ret);
void				print_str_flag_sub(t_list tmp, char *result, int num,
		int *ret);
void				print_str_flag_minus(t_list tmp, int num, char *result,
		int length_flag);
void				print_nbr_flag(t_list tmp, long long result, int num,
		int *ret);
void				print_nbr_flag_sub(t_list *tmp, int *num,
		int *length_flag, long long result);
void				index_and_structure(const char format, t_list *tmp,
		int *index, int *ret);
void				valid_flag(const char format, int *ret);
void				print_int(t_list tmp, va_list tmp1, char format, int *ret);
void				print_char(t_list tmp, va_list tmp1, char format, int *ret);
void				print_char_sub(t_list tmp, char result, char pad);
void				print_str(t_list tmp, va_list tmp1, char format, int *ret);
void				print_add(t_list tmp, va_list tmp1, char format, int *ret);
void				print_hexa(t_list tmp, va_list tmp1, char format, int *ret);
void				print_octal(t_list tmp, va_list tmp1, char format,
		int *ret);
void				print_unsigned(t_list tmp, va_list tmp1, char format,
		int *ret);

#endif
