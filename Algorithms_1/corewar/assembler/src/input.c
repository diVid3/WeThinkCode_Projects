/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 10:12:36 by egenis            #+#    #+#             */
/*   Updated: 2018/09/12 10:12:37 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

int			check_ext(char *file)
{
	int		cntr;

	cntr = -1;
	while (file[++cntr])
		;
	--cntr;
	if (file[cntr] == 's' && file[cntr - 1] == '.')
		return (1);
	return (0);
}

void		get_input(int ac, char **av)
{
	int		fd;

	if (check_ext(av[1]) == 0)
		fd = open(ft_strjoin(av[1], ".s"), O_RDONLY);
	else
		fd = open(av[1], O_RDONLY);
	if (fd == -1)
		quit(1)
}
