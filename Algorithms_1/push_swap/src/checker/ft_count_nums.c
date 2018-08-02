/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:55:18 by egenis            #+#    #+#             */
/*   Updated: 2018/08/02 13:56:11 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"

int				ft_count_nums(const char *str)
{
	int		cntr;
	int		num_cnt;
	_Bool	swtch;

	cntr = 0;
	num_cnt = 0;
	swtch = 0;
	while (str[cntr])
	{
		if ((str[cntr] == '+' || str[cntr] == '-' || (str[cntr] >= '0' &&
			str[cntr] <= '9')) && !swtch)
		{
			++num_cnt;
			swtch = 1;
		}
		if ((str[cntr] >= 9 && str[cntr] <= 13) || str[cntr] == 32)
			swtch = 0;
		++cntr;
	}
	return (num_cnt);
}
