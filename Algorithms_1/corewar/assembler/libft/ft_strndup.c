/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 06:30:27 by egenis            #+#    #+#             */
/*   Updated: 2018/10/01 06:30:29 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

char	*ft_strndup(const char *s1, size_t len)
{
	size_t	cntr;
	size_t	strlen;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	strlen = ft_strlen(s1);
	if (len > strlen)
		len = strlen;
	str = malloc(sizeof(char) * len + 1);
	cntr = 0;
	while (cntr < len)
	{
		str[cntr] = s1[cntr];
		++cntr;
	}
	str[cntr] = '\0';
	return (str);
}
