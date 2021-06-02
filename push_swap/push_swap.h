/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:18:15 by djeon             #+#    #+#             */
/*   Updated: 2021/06/03 01:58:56 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

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

typedef struct	s_tmp
{
	int					len_a;
	int					len_b;
	int					back_a;
	int					back_b;
	int					max_pa;
	int					max_pb;
	int					flag_ra;
	int					flag_rb;
	int					not_back_a;
	int					not_back_b;
	t_pivot				pivot;
}				t_tmp;

void			print_list(t_stack *lst, int len);

// list_function.c
void			ft_delete(t_stack **lst);
t_stack			*ft_new(int content);
void			ft_add(t_stack **lst, t_stack *new1);
int				ft_listsize(t_stack *lst);
// push_swap_function.c
void			swap_list(t_stack **lst, char stack, int *buffer);
void			push_list(t_stack **lst1, t_stack **lst2, char stack,
				int *buffer);
void			rotate_list(t_stack **lst, int direction, char stack,
				int *buffer);
void			reverse_rotate_ab(t_stack **a, t_stack **b, t_tmp tmp,
				int *buffer);
void			reverse_rotate_ba(t_stack **lst, t_tmp tmp, char stack,
				int *buffer);
// push_swap.c
void			push_swap_sort_ab(t_stack **a_head, t_stack **b_head, int len,
				int *buffer);
void			push_swap_sort_ba(t_stack **b_head, t_stack **a_head, int len,
				int *buffer);
// sort_23_ab.c
void			sort_23_ab_fix(t_stack **lst, int len, int *buffer);
void			sort_23_ab(t_stack **lst, int len, int *buffer);
// sort_23_ba_sub.c
void			sort_23_ba_fix(t_stack **dst, t_stack **src, int len,
				int *buffer);
// sort_23_ba.c
void			sort_23_ba(t_stack **dst, t_stack **src, int len, int *buffer);
// find_pivot.c
t_pivot			find_pivot(t_stack **lst, int len);
// print_instructions.c
void			print_instructions(int *buffer, char *str);
void			input_str(char **tmp);
// push_swap_sub.c
int				input_list(t_stack **a_head, char *argv[], int len);
void			push_swap_sort_45_sub(t_stack **a_head, t_stack **b_head,
				int index, int *buffer);
// sort_sub.c
void			init_struct_tmp(t_tmp *input, int len);
void			pivot_condition_ab(t_stack **a_head, t_stack **b_head,
				t_tmp *tmp, int *buffer);
void			pivot_condition_ba(t_stack **a_head, t_stack **b_head,
				t_tmp *tmp, int *buffer);
void			recursive_0123_ba(t_stack **a_head, t_stack **b_head,
				int len, int *buffer);
void			recursive_0123_ab(t_stack **a_head, int len, int *buffer);
// checker_sub.c
void			swap_list_checker(t_stack **lst);
void			push_list_checker(t_stack **lst1, t_stack **lst2);
void			rotate_list_checker(t_stack **lst, int direction);
int				sort(t_stack **a_head, t_stack **b_head, char *line);

#endif
