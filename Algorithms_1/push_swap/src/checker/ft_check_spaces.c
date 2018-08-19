/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 06:24:23 by egenis            #+#    #+#             */
/*   Updated: 2018/08/19 09:42:40 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"

int				ft_check_spaces(const char *str)
{
	int		cntr;

	cntr = 0;
	while (str[cntr])
	{
		if (cntr == 0 && (str[cntr] == '+' || str[cntr] == '-'))
			++cntr;
		if (str[cntr] == '+' || str[cntr] == '-')
			if (!(str[cntr - 1] >= 9 && str[cntr - 1] <= 13) &&
				!(str[cntr - 1] == 32))
				return (-1);
		++cntr;
	}
	return (0);
}
