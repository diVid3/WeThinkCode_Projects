/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:14:21 by egenis            #+#    #+#             */
/*   Updated: 2018/05/25 08:48:35 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	nul_pos;
	int		s2_cntr;
	size_t	num_count;

	nul_pos = ft_strlen(s1);
	s2_cntr = 0;
	num_count = 0;
	while (s2[s2_cntr] && num_count < n)
	{
		s1[nul_pos] = s2[s2_cntr];
		++nul_pos;
		++s2_cntr;
		++num_count;
	}
	s1[nul_pos] = '\0';
	return (s1);
}
