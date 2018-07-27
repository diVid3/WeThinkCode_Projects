/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nxt_num_adrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 08:20:14 by egenis            #+#    #+#             */
/*   Updated: 2018/07/24 17:36:22 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"
//#include <stdio.h>

static void		ft_reset(_Bool *wrd_first, int *cntr)
{
	*wrd_first = 0;
	*cntr = 0;
}

char		*ft_nxt_num_adrs(char *s, _Bool reset)
{
	static int		cntr;
	static _Bool	wrd_first;
	char			*num;

	num = NULL;
	if (reset)
	{
		ft_reset(&wrd_first, &cntr);
		return (num);
	}
	if ((*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')) && !wrd_first)
	{
		while (((s[cntr] >= '0' && s[cntr] <= '9') || s[cntr] == '+' ||
				s[cntr] == '-') && s[cntr])
			++cntr;
		wrd_first = 1;
		return (s);
	}
	while (((s[cntr] >= 9 && s[cntr] <= 13) || s[cntr] == 32) && s[cntr])
		++cntr;
	num = s + cntr;
	while (((s[cntr] >= '0' && s[cntr] <= '9') || s[cntr] == '+' ||
			s[cntr] == '-') && s[cntr])
		++cntr;
	return (num);
}

/*
int		main(void)
{
	char	arr[] = "1 2 3 4 5";
	char	arr2[] = "+13 -7 +0 0 4";
	char	arr3[] = "";	

	printf("%s\n", ft_nxt_num_adrs(arr, 0));
	printf("%s\n", ft_nxt_num_adrs(arr, 0));
	printf("%s\n", ft_nxt_num_adrs(arr, 0));
	printf("%s\n", ft_nxt_num_adrs(arr, 0));
	printf("%s\n", ft_nxt_num_adrs(arr, 0));
	printf("%s\n", ft_nxt_num_adrs(arr, 0));

	ft_nxt_num_adrs(arr2, 1);

	printf("%s\n", ft_nxt_num_adrs(arr2, 0));
	printf("%s\n", ft_nxt_num_adrs(arr2, 0));
	printf("%s\n", ft_nxt_num_adrs(arr2, 0));
	printf("%s\n", ft_nxt_num_adrs(arr2, 0));
	printf("%s\n", ft_nxt_num_adrs(arr2, 0));
	printf("%s\n", ft_nxt_num_adrs(arr2, 0));

	ft_nxt_num_adrs(arr3, 1);

	printf("%s\n", ft_nxt_num_adrs(arr3, 0));

	return (0);
}