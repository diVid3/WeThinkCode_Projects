/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:54:45 by egenis            #+#    #+#             */
/*   Updated: 2018/08/13 15:56:29 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap/push_swap.h"

static int		ft_check_oprts(const char *str)
{
	int		cntr;

	cntr = 0;
	while (str[cntr] && str[cntr + 1])
	{
		if (((str[cntr] == '+') || (str[cntr] == '-')) &&
			!(str[cntr + 1] >= '0' && str[cntr + 1] <= '9'))
			return (-1);
		++cntr;
	}
	if ((str[cntr] == '+' || str[cntr] == '-') && str[cntr + 1] == '\0')
		return (-1);
	return (0);
}

static int		ft_check_valid_ch(const char *str)
{
	int		cntr;

	cntr = 0;
	while (((str[cntr] >= 9 && str[cntr] <= 13) ||
			(str[cntr] >= '0' && str[cntr] <= '9') || str[cntr] == 32 ||
			str[cntr] == '+' || str[cntr] == '-') && str[cntr])
		++cntr;
	if (str[cntr] != '\0')
		return (-1);
	return (0);
}

/*
static int		ft_check_int_sizes(const char *str)
{
	int		num_count;
	char	*num_adrs;
	int		int_valid;

	num_count = ft_count_nums(str);
	if (num_count == 1)
		return (2);
	ft_nxt_num_adrs((char *)str, 1);
	while (num_count-- > 0)
	{
		num_adrs = ft_nxt_num_adrs((char *)str, 0);
		int_valid = ft_check_min_max(num_adrs);
		if (int_valid == -1)
			return (-1);
	}
	return (0);
}
*/

static int		ft_check_int_sizes(const char *str)
{
	int			cntr;
	int			num_count;
	char		*num_adrs;
	int			int_valid;
	
	cntr = 0;
	num_count = ft_count_nums(str);
	ft_nxt_num_adrs((char *)str, 1);
	while (cntr < num_count)
	{
		num_adrs = ft_nxt_num_adrs((char *)str, 0);
		int_valid = ft_check_min_max(num_adrs);
		if (int_valid == -1)
			return (-1);
		++cntr;
	}
	if (num_count == 1)
		return (2);
	return (0);
}

static int		ft_check_dups(const char *str)
{
	int		num_count;
	int		cntr;
	int		cntr2;
	long	*arr;

	ft_nxt_num_adrs((char *)str, 1);
	num_count = ft_count_nums(str);
	arr = malloc(sizeof(long) * num_count);
	cntr = -1;
	while (++cntr < num_count)
		arr[cntr] = ft_atol(ft_nxt_num_adrs((char *)str, 0));
	cntr = -1;
	while (++cntr < num_count)
	{
		cntr2 = cntr;
		while (++cntr2 < num_count)
			if (arr[cntr] == arr[cntr2])
			{
				ft_memdel((void **)(&arr));
				return (-1);
			}
	}
	ft_memdel((void **)(&arr));
	return (0);
}

int				ft_check_arg(const char *str)
{
	if (ft_check_valid_ch(str) == -1)
		return (-1);
	if (ft_check_oprts(str) == -1)
		return (-1);
	if (ft_check_spaces(str) == -1)
		return (-1);
	if (ft_check_int_sizes(str) == -1)
		return (-1);
	if (ft_check_int_sizes(str) == 2)
		return (2);
	if (ft_check_dups(str) == -1)
		return (-1);
	return (0);
}
