/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:31:50 by egenis            #+#    #+#             */
/*   Updated: 2018/07/24 08:31:01 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"

static int		ft_check_operators(char *str)
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
	return (0);
}

static int		ft_check_valid_ch(char *str)
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

int				ft_check_arg1(char *str)
{

}
