/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:58:21 by egenis            #+#    #+#             */
/*   Updated: 2018/06/05 10:01:11 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	cntr;

	cntr = 0;
	ft_bzero(dst, len);
	while (cntr < len && src[cntr])
	{
		dst[cntr] = src[cntr];
		++cntr;
	}
	return (dst);
}
