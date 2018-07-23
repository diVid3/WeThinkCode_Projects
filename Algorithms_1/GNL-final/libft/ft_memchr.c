/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:11:47 by egenis            #+#    #+#             */
/*   Updated: 2018/06/04 11:24:44 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		cntr;
	t_uchar		ch;
	t_uchar		*ptr;

	cntr = 0;
	ch = (t_uchar)c;
	ptr = (t_uchar *)s;
	while (cntr < n)
	{
		if (ptr[cntr] == ch)
			return (ptr + cntr);
		++cntr;
	}
	return (NULL);
}
