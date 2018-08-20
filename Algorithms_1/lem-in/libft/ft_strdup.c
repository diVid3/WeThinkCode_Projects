/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 10:02:43 by egenis            #+#    #+#             */
/*   Updated: 2018/05/28 13:56:32 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	cntr;
	size_t	strlen;
	char	*str_ptr;

	cntr = 0;
	strlen = ft_strlen(s1);
	str_ptr = (char *)malloc(sizeof(char) * strlen + 1);
	if (!(str_ptr))
		return (NULL);
	while (cntr < strlen)
	{
		str_ptr[cntr] = s1[cntr];
		++cntr;
	}
	str_ptr[cntr] = '\0';
	return (str_ptr);
}
