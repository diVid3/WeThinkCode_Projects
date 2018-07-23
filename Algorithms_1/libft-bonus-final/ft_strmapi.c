/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:56:43 by egenis            #+#    #+#             */
/*   Updated: 2018/05/31 16:21:05 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			str_len;
	size_t			cntr;
	unsigned int	i;
	char			*newstr;

	if (s && f)
	{
		str_len = ft_strlen(s);
		cntr = 0;
		i = 0;
		newstr = ft_strnew(str_len);
		if (!newstr)
			return (NULL);
		while (newstr && s[cntr])
		{
			newstr[cntr] = (*f)(i, s[cntr]);
			++cntr;
			++i;
		}
		return (newstr);
	}
	return (NULL);
}
