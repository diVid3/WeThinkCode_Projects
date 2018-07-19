/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:42:28 by egenis            #+#    #+#             */
/*   Updated: 2018/05/28 11:10:30 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	cntr;
	t_uchar *src_cpy;
	t_uchar *dst_cpy;

	cntr = 0;
	src_cpy = (t_uchar *)src;
	dst_cpy = (t_uchar *)dst;
	if (dst < src)
		while (cntr < len)
		{
			dst_cpy[cntr] = src_cpy[cntr];
			++cntr;
		}
	else
		while (cntr < len)
		{
			dst_cpy[(len - 1) - cntr] = src_cpy[(len - 1) - cntr];
			++cntr;
		}
	return (dst);
}
