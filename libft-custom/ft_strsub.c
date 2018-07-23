/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:16:16 by egenis            #+#    #+#             */
/*   Updated: 2018/06/02 11:56:13 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	cntr;
	char	*newstr;

	newstr = NULL;
	if (s)
	{
		cntr = 0;
		newstr = ft_strnew(len);
		if (!newstr)
			return (NULL);
		while (s[start] && cntr < len)
		{
			newstr[cntr] = s[start];
			++cntr;
			++start;
		}
	}
	return (newstr);
}
