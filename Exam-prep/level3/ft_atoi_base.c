/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 06:19:27 by egenis            #+#    #+#             */
/*   Updated: 2018/07/04 08:10:26 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	size_t	cntr;

	cntr = 0;
	while (str[cntr])
		++cntr;
	return (cntr);
}

int		ft_calc_multiplier(int strlen, int cntr)
{
	int				cntr;

	cntr = 0;
	while (
}

// Temporarily made this for hex, will adjust later.
int ft_atoi_base(const char *str, int str_base)
{
	//char c[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'a', 'b', 'c', 'd', 'e', 'f'};
	int		ans;
	int		tmp;
	int		cntr;

	ans = 0;
	tmp = 0;
	cntr = ft_strlen(str);
	while (cntr > 0)
	{
		//while (cntr2 < cntr3)
		//{
		//	tmp *= 16;
		//	++cntr2;
		//}
		if (str[cntr] >= '0' && str[cntr] <= '9')
			tmp = str[cntr] - 48;
		if (str[cntr] >= 'A' && str[cntr] <= 'F')
			tmp = str[cntr] - 55;
		if (str[cntr] >= 'a' && str[cntr] <= 'f')
			tmp = str[cntr] - 87;
		ans += tmp;
		--cntr;
		//++cntr3;
	}
}

int main(void)
{
	return (0);
}
