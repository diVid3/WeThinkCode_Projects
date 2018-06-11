/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:44:33 by egenis            #+#    #+#             */
/*   Updated: 2018/05/31 16:21:01 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	str_len;
	size_t	cntr;
	char	*newstr;

	if (s && f)
	{
		str_len = ft_strlen(s);
		cntr = 0;
		newstr = ft_strnew(str_len);
		if (!newstr)
			return (NULL);
		while (newstr && s[cntr])
		{
			newstr[cntr] = (*f)(s[cntr]);
			++cntr;
		}
		return (newstr);
	}
	return (NULL);
}
