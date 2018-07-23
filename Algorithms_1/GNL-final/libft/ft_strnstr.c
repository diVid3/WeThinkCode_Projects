/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:32:39 by egenis            #+#    #+#             */
/*   Updated: 2018/06/06 16:36:27 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	_Bool	ft_matchline(const char *hay, const char *ndl)
{
	size_t	cntr;
	size_t	ndl_len;

	cntr = 0;
	ndl_len = ft_strlen(ndl);
	while (hay[cntr] == ndl[cntr] && hay[cntr] && ndl[cntr])
		++cntr;
	if (cntr == ndl_len)
		return (1);
	return (0);
}

char			*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t	cntr;
	size_t	ndl_len;
	_Bool	match;

	cntr = 0;
	ndl_len = ft_strlen(ndl);
	if (!(*ndl))
		return ((char *)hay);
	while (hay[cntr])
	{
		if (hay + ndl_len + cntr > hay + len)
			break ;
		match = ft_matchline(hay + cntr, ndl);
		if (match == 1)
			return ((char *)(hay + cntr));
		++cntr;
	}
	return (NULL);
}
