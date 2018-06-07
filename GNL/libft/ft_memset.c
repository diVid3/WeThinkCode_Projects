/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:28:46 by egenis            #+#    #+#             */
/*   Updated: 2018/05/25 08:51:23 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		cntr;

	cntr = 0;
	while (cntr < len)
	{
		((unsigned char *)b)[cntr] = (unsigned char)c;
		++cntr;
	}
	return (b);
}
