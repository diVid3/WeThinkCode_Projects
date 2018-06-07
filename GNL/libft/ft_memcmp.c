/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:36:15 by egenis            #+#    #+#             */
/*   Updated: 2018/05/28 13:08:22 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cntr;
	t_uchar	*s1_cpy;
	t_uchar	*s2_cpy;

	cntr = 0;
	s1_cpy = (t_uchar *)s1;
	s2_cpy = (t_uchar *)s2;
	if (n == 0)
		return (0);
	while (cntr < n && s1_cpy[cntr] == s2_cpy[cntr])
		++cntr;
	if (cntr == n)
		--cntr;
	return (s1_cpy[cntr] - s2_cpy[cntr]);
}
