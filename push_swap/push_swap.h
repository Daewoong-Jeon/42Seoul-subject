/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:18:15 by djeon             #+#    #+#             */
/*   Updated: 2021/05/25 18:04:09 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

typedef struct	s_stack
{
	int					data;
	struct s_stack		*before;
	struct s_stack		*next;
}				t_stack;

void			print_list(t_stack *lst, int len);

void			ft_delete(t_stack **lst);
t_stack			*ft_new(int content);
void			ft_add(t_stack **lst, t_stack *new1);
void			swap_list(t_stack **lst);
void			push_list(t_stack **lst1, t_stack **lst2);
void			rotate_list(t_stack **lst, int direction);

#endif
