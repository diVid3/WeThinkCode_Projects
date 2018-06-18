/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:28:06 by egenis            #+#    #+#             */
/*   Updated: 2018/06/05 06:22:45 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cntr;
	size_t	cntr2;
	size_t	dst_len;
	size_t	src_len;

	cntr = 0;
	cntr2 = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	while (dst[cntr])
		++cntr;
	while (src[cntr2] && cntr2 < dstsize - dst_len - 1)
	{
		dst[cntr] = src[cntr2];
		++cntr;
		++cntr2;
	}
	dst[cntr] = '\0';
	return (dst_len + src_len);
}
