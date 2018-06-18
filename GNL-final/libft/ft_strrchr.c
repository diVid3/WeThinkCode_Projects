/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:12:30 by egenis            #+#    #+#             */
/*   Updated: 2018/05/29 18:05:52 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	cntr;
	char	ch;
	char	*ptr;

	cntr = 0;
	ch = (char)c;
	ptr = NULL;
	while (s[cntr])
	{
		if (s[cntr] == ch)
			ptr = (char *)(&s[cntr]);
		++cntr;
	}
	if (s[cntr] == ch)
		ptr = (char *)(&s[cntr]);
	return (ptr);
}
