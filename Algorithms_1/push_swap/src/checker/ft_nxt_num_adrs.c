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
#include <stdio.h>

static void		ft_reset(_Bool *wrd_first, int *cntr)
{
	*wrd_first = 0;
	*cntr = 0;
}

char		*ft_nxt_num_adrs(char *s)
{
	static int		cntr;
	static _Bool	wrd_first;
	static char		*s_old;
	char			*num;

	num = NULL;
	if (s != s_old || !(*s))
		ft_reset(&wrd_first, &cntr);
	if ((*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')) && !wrd_first)
	{
		while (((s[cntr] >= '0' && s[cntr] <= '9') || s[cntr] == '+' ||
				s[cntr] == '-') && s[cntr])
			++cntr;
		wrd_first = 1;
		s_old = s;
		return (s);
	}
	while (((s[cntr] >= 9 && s[cntr] <= 13) || s[cntr] == 32) && s[cntr])
		++cntr;
	num = s + cntr;
	while (((s[cntr] >= '0' && s[cntr] <= '9') || s[cntr] == '+' ||
			s[cntr] == '-') && s[cntr])
		++cntr;
	s_old = s;
	return (num);
}

int		main(void)
{
	char	arr[] = "+413 +251    2 488 1		2 +3 -1";
	//char	arr2[] = "0353133 +85721 -15616 0 16 3 9		93";
	char	*str = arr;
	//for (int i = 0; i < 8; ++i)
	//{
	//	str = ft_nxt_num_adrs(str);
	//	printf("%s\n", str);
	//}
	
	return (0);
}
