/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:31:34 by egenis            #+#    #+#             */
/*   Updated: 2018/09/11 07:31:36 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	quit(t_data *d, int err_msg)
{
	exit(0);
}

int		main(int ac, char **av)
{
	static t_data		d;

	get_input(ac, av);
	make_champ();
	quit(d, 0);
}

/*
int		main(int ac, char **av)
{
	char *str = ft_strnew(1);
	int fd = open(av[1], O_RDONLY);
	size_t i = 0;
	while (read(fd, str, 1))
		i++;
	lseek(fd, 0, SEEK_SET);
	free(str);
	str = ft_strnew(i);
	read(fd, str, i);
	ft_putendl("\033[34m;This is the file:\033[0m");
	ft_putendl(str);
	return (0);
}
*/
