/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:08:56 by mac               #+#    #+#             */
/*   Updated: 2020/12/19 02:48:24 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_info		*ft_lstnew(void *content)
{
	t_info	*result;

	if (!(result = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}
