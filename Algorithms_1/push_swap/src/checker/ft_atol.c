/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 06:26:37 by egenis            #+#    #+#             */
/*   Updated: 2018/07/25 06:26:39 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"
//#include <stdio.h>

long	ft_atol(char *str)
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

/*
int		main(void)
{
	char	arr1[] = "-21474836487439";

	printf("ft_atoi_l of arr1 is %ld\n", ft_atol(arr1));

	return (0);
}
*/
