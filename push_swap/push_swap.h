/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:18:15 by djeon             #+#    #+#             */
/*   Updated: 2021/05/28 22:06:27 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

typedef struct	s_stack
{
	int					data;
	int					rank;
	struct s_stack		*before;
	struct s_stack		*next;
}				t_stack;

void			print_list(t_stack *lst, int len);

void			ft_delete(t_stack **lst);
t_stack			*ft_new(int content);
void			ft_add(t_stack **lst, t_stack *new1);
t_stack			*ft_find_index(t_stack **lst, int index);
void			swap_list(t_stack **lst, char stack);
void			push_list(t_stack **lst1, t_stack **lst2, char stack);
void			rotate_list(t_stack **lst, int direction, char stack);
void			push_swap_sort_ab(t_stack **a_head, t_stack **b_head, int len);
void			push_swap_sort_ba(t_stack **b_head, t_stack **a_head, int len);
void			push_swap_sort_23(t_stack **lst, int len);
void			push_swap_sort_23_ba(t_stack **dst, t_stack **src, int len);
int				find_pivot(t_stack **lst, int len, int *pivot_1);

#endif
