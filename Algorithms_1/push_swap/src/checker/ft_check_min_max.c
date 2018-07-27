/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_min_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 06:26:16 by egenis            #+#    #+#             */
/*   Updated: 2018/07/25 07:52:14 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"
//#include <stdio.h>

/*
long	ft_atol(const char *str)
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
*/

static int		ft_check_int_len(long nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr *= -1;
	while (nbr >= 1)
	{
		++len;
		nbr /= 10;
	}
	return (len);
}

int				ft_check_min_max(char *num_adrs)
{
	long	num;

	num = ft_atol(num_adrs);
	if (ft_check_int_len(num) > 10)
		return (-1);
	if (num > 2147483647 || num < -2147483648)
		return (-1);
	return (0);
}

/*
int		main(void)
{
	//long test = -2147483648;
	//printf("len for %d is %d\n", test, ft_check_int_len(test));
	char *str = "125243463464356345";
	printf("exceed min/max for %s is %d\n", str, ft_check_min_max(str));
	return (0);
}
*/
