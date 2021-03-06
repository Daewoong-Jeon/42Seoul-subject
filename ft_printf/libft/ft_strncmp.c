/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 21:12:18 by djeon             #+#    #+#             */
/*   Updated: 2020/07/08 12:22:49 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while (t1[i] != '\0' && t2[i] != '\0' && i < n)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		else
			i++;
	}
	if (t1[i] != '\0' && i < n)
		return (t1[i]);
	if (t2[i] != '\0' && i < n)
		return (-t2[i]);
	return (0);
}
