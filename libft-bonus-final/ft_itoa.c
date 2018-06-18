/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 07:09:58 by egenis            #+#    #+#             */
/*   Updated: 2018/06/04 15:26:43 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_num(int n)
{
	size_t	cntr;
	long	ans;

	cntr = 0;
	ans = n;
	if (ans < 0)
		ans *= -1;
	if (!ans)
		return (1);
	while (ans > 0)
	{
		ans /= 10;
		++cntr;
	}
	return (cntr);
}

static	int		ft_calc_divisor(int n)
{
	size_t	cntr;
	size_t	num_cnt;
	int		divisor;

	cntr = 0;
	num_cnt = ft_count_num(n);
	divisor = 1;
	while (num_cnt && cntr < num_cnt - 1)
	{
		divisor *= 10;
		++cntr;
	}
	return (divisor);
}

static	char	*ft_write_num(char *str, int n, int sign)
{
	long	tmp;
	size_t	cntr;
	int		divisor;
	int		ans;

	tmp = n;
	cntr = 0;
	divisor = ft_calc_divisor(n);
	if (sign < 0)
	{
		tmp *= -1;
		str[0] = '-';
		++cntr;
	}
	while (divisor > 0)
	{
		ans = tmp / divisor;
		str[cntr] = ans + 48;
		tmp = tmp - (ans * divisor);
		divisor /= 10;
		++cntr;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		sign;
	size_t	num_cnt;
	char	*str;

	sign = (n < 0) ? -1 : 1;
	num_cnt = ft_count_num(n);
	if (sign == -1)
		++num_cnt;
	str = ft_strnew(num_cnt);
	if (!str)
		return (NULL);
	if (str)
		str = ft_write_num(str, n, sign);
	return (str);
}
