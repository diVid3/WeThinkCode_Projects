/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:03:10 by egenis            #+#    #+#             */
/*   Updated: 2018/05/25 08:50:38 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		cntr;

	cntr = 0;
	while (s[cntr] != (char)c && s[cntr])
		++cntr;
	return (s[cntr] == (char)c ? (char *)(&(s[cntr])) : NULL);
}
