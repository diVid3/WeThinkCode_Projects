/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 08:26:40 by egenis            #+#    #+#             */
/*   Updated: 2018/07/11 08:37:56 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	brainf(int *cntr, char *str, char **ptr)
{
	while (str[*cntr])
	{

		++(*cntr);
	}
}

int		main(int ac, char **av)
{
	static unsigned char	arr[4096];
	unsigned int			cntr = 0;
	unsigned char			*ptr = arr;

	if (ac != 2)
		write(1, "\n", 1);
	if (ac != 2)
		return (0);
	while (av[1][cntr])
	{
		if (av[1][cntr] == '>')
			++ptr;
		if (av[1][cntr] == '<')
			--ptr;
		if (av[1][cntr] == '+')
			++(*ptr);
		if (av[1][cntr] == '-')
			--(*ptr);
		if (av[1][cntr] == '.')
			write(1, ptr, 1);
		if (av[1][cntr] == '[' && *ptr)
			brainf(&cntr, av[1], &ptr);
		++cntr;
	}
	return (0);
}
