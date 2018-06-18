/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:10:51 by egenis            #+#    #+#             */
/*   Updated: 2018/05/25 12:00:15 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	strlen;
	size_t	cntr;

	strlen = ft_strlen(src);
	cntr = 0;
	while (cntr < strlen)
	{
		dst[cntr] = src[cntr];
		++cntr;
	}
	dst[cntr] = '\0';
	return (dst);
}
