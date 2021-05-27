/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <djeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:18:44 by djeon             #+#    #+#             */
/*   Updated: 2021/05/26 21:34:52 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_list(t_stack *lst, int len)
{
	if (lst == NULL)
		return ;
	while (len--)
	{
		printf("%d ", lst->data);
		if (lst->next != NULL)
			lst = lst->next;
	}
	printf("\n");
}
