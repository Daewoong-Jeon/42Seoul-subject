/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_23_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:50:08 by djeon             #+#    #+#             */
/*   Updated: 2021/06/01 17:50:22 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_23_ab_fix_sub(t_stack **lst, int *buffer)
{
	if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				< (*lst)->next->next->data && (*lst)->data
				< (*lst)->next->next->data)
		swap_list(lst, 'a', buffer);
	else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
			< (*lst)->next->next->data && (*lst)->data
			> (*lst)->next->next->data)
	{
		swap_list(lst, 'a', buffer);
		rotate_list(lst, -1, 'a', buffer);
		swap_list(lst, 'a', buffer);
		rotate_list(lst, 1, 'a', buffer);
	}
	else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
			> (*lst)->next->next->data && (*lst)->data
			> (*lst)->next->next->data)
	{
		swap_list(lst, 'a', buffer);
		rotate_list(lst, -1, 'a', buffer);
		swap_list(lst, 'a', buffer);
		rotate_list(lst, 1, 'a', buffer);
		swap_list(lst, 'a', buffer);
	}
}

void		sort_23_ab_fix(t_stack **lst, int len, int *buffer)
{
	if (len == 3)
	{
		if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data && (*lst)->data
				< (*lst)->next->next->data)
		{
			rotate_list(lst, -1, 'a', buffer);
			swap_list(lst, 'a', buffer);
			rotate_list(lst, 1, 'a', buffer);
		}
		else if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data && (*lst)->data
				> (*lst)->next->next->data)
		{
			rotate_list(lst, -1, 'a', buffer);
			swap_list(lst, 'a', buffer);
			rotate_list(lst, 1, 'a', buffer);
			swap_list(lst, 'a', buffer);
		}
		sort_23_ab_fix_sub(lst, buffer);
	}
	else if (len == 2 && (*lst)->data > (*lst)->next->data)
		swap_list(lst, 'a', buffer);
}

void		sort_23_ab_sub(t_stack **lst, int *buffer)
{
	if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
			> (*lst)->next->next->data && (*lst)->data
			> (*lst)->next->next->data)
		rotate_list(lst, 1, 'a', buffer);
	else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
			< (*lst)->next->next->data && (*lst)->data
			> (*lst)->next->next->data)
		rotate_list(lst, -1, 'a', buffer);
	else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
			> (*lst)->next->next->data && (*lst)->data
			> (*lst)->next->next->data)
	{
		swap_list(lst, 'a', buffer);
		rotate_list(lst, 1, 'a', buffer);
	}
}

void		sort_23_ab(t_stack **lst, int len, int *buffer)
{
	if (len == 3)
	{
		if ((*lst)->data < (*lst)->next->data && (*lst)->next->data
				> (*lst)->next->next->data && (*lst)->data
				< (*lst)->next->next->data)
		{
			rotate_list(lst, 1, 'a', buffer);
			swap_list(lst, 'a', buffer);
		}
		else if ((*lst)->data > (*lst)->next->data && (*lst)->next->data
				< (*lst)->next->next->data && (*lst)->data
				< (*lst)->next->next->data)
			swap_list(lst, 'a', buffer);
		sort_23_ab_sub(lst, buffer);
	}
	else if (len == 2 && (*lst)->data > (*lst)->next->data)
		swap_list(lst, 'a', buffer);
}
