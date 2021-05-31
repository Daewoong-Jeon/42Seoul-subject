/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:18:15 by djeon             #+#    #+#             */
/*   Updated: 2021/05/31 22:14:30 by djeon            ###   ########.fr       */
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

typedef struct	s_pivot
{
	int					pivot_l;
	int					pivot_h;
}				t_pivot;

void			print_list(t_stack *lst, int len);

void			ft_delete(t_stack **lst);
t_stack			*ft_new(int content);
void			ft_add(t_stack **lst, t_stack *new1);
int				ft_listsize(t_stack *lst);
t_stack			*ft_find_index(t_stack **lst, int index);
void			swap_list(t_stack **lst, char stack, int *buffer);
void			push_list(t_stack **lst1, t_stack **lst2, char stack, int *buffer);
void			rotate_list(t_stack **lst, int direction, char stack, int same, int *buffer);
void			rotate_list_sametime(t_stack **a, t_stack **b, int len_1, int len_2, int *buffer);
void			push_swap_sort_ab(t_stack **a_head, t_stack **b_head, int len, int *buffer);
void			push_swap_sort_ba(t_stack **b_head, t_stack **a_head, int len, int *buffer);
void			sort_23_ab_fix(t_stack **lst, int len, int *buffer);
void			sort_23_ba_fix(t_stack **dst, t_stack **src, int len, int *buffer);
void			sort_23_ba(t_stack **dst, t_stack **src, int len, int *buffer);
void			sort_23_ab(t_stack **lst, int len, int *buffer);
t_pivot			find_pivot(t_stack **lst, int len);
int				check_sort(t_stack **lst, int len, char stack);
void			print_instructions(int *buffer, char *str);
void			input_str(char **tmp);
int				input_list(t_stack **a_head, char *argv[], int len);

#endif
