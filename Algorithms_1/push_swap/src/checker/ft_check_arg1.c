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
//#include <stdio.h>

static int		ft_check_oprts(char *str)
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

/*
int		main(void)
{
	char		arr1[] = "+5 	-2   0 9	 -9749   ";
	char		arr2[] = "7439 		30848 	z";
	char		arr3[] = "	 +5		-34 		++2 ";
	char		arr4[] = "4089 		 --6";

	printf("ft_check_valid_ch for arr1 returns %d\n", ft_check_valid_ch(arr1));
	printf("ft_check_valid_ch for arr2 returns %d\n", ft_check_valid_ch(arr2));
	printf("ft_check_valid_ch for arr3 returns %d\n", ft_check_valid_ch(arr3));
	printf("ft_check_valid_ch for arr4 returns %d\n", ft_check_valid_ch(arr4));

	printf("\n");

	printf("ft_check_oprts for arr1 returns %d\n", ft_check_oprts(arr1));
	printf("ft_check_oprts for arr2 returns %d\n", ft_check_oprts(arr2));
	printf("ft_check_oprts for arr3 returns %d\n", ft_check_oprts(arr3));
	printf("ft_check_oprts for arr4 returns %d\n", ft_check_oprts(arr4));
	return (0);
}
*/