/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 08:14:43 by egenis            #+#    #+#             */
/*   Updated: 2018/07/24 08:28:56 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"

long	ft_atoi_l(const char *str)
{
	long	ans;
	long	sign;
	size_t	num_cnt;

	ans = 0;
	sign = 1;
	num_cnt = 0;
	while (((*str >= 9 && *str <= 13) || *str == 32) && *str)
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str == 0)
		++str;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		ans = (ans * 10) + (*str++ - 48);
		if (num_cnt > 18)
			return (sign == -1 ? 0 : -1);
		++num_cnt;
	}
	return (ans * sign);
}
