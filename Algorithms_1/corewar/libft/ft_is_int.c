/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:58:08 by egenis            #+#    #+#             */
/*   Updated: 2018/08/24 11:58:09 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			ft_is_int(const char *num_adrs)
{
	int		cntr;
	int		len;
	long	num;

	if (num_adrs == NULL)
		return (0);
	cntr = 0;
	if (num_adrs[cntr] == '+' || num_adrs[cntr] == '-')
		++cntr;
	len = 0;
	while (num_adrs[cntr] == '0')
		++cntr;
	while (num_adrs[cntr] && !((num_adrs[cntr] >= 9 && num_adrs[cntr] <= 13) ||
			(num_adrs[cntr] == 32)))
	{
		if (num_adrs[cntr] >= '0' && num_adrs[cntr] <= '9')
			++len;
		++cntr;
	}
	if (len > 10)
		return (0);
	num = ft_atol(num_adrs);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}
