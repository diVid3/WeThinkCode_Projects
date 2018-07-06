/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:43:10 by egenis            #+#    #+#             */
/*   Updated: 2018/07/06 12:49:17 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

unsigned int	ft_num_size(unsigned int duration)
{
	unsigned int	cntr;

	if (duration == 0)
		return (1);
	if (duration < 0)
		duration *= -1;
	cntr = 0;
	while (duration > 0)
	{
		duration /= 10;
		++cntr;
	}
	return (cntr);
}

/*
char			*moment(unsigned int duration)
{
	if (duration < 60)
}
*/

int		main(int ac, char **av)
{
	(void)ac;
	unsigned int	num = atoi(av[1]);
	printf("num size for %d is %d\n", num, ft_num_size(num));
	return (0);
}
