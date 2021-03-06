/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 21:04:33 by djeon             #+#    #+#             */
/*   Updated: 2020/12/19 02:45:54 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_info **lst, t_info *new1)
{
	if (lst == NULL || new1 == NULL)
		return ;
	new1->next = *lst;
	*lst = new1;
}
