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

void	save_input(t_data *d, int fd)
{
	char		*line;
	int			read_b;

	read_b = 1;
	while (read_b)
	{
		read_b = get_next_line(fd, &line);
		input_add_node_end(&(d->input), line);
	}
}

void	get_header(t_data *d, int fd)
{
	t_input		*tmp;

	tmp = d->input;
}

void	get_input(t_data *d, int ac, char **av)
{
	int		fd;

	if (ac == 1)
		quit(d, 1);
	if (has_ext(av[1]) == 0)
		fd = open(ft_strjoin(av[1], ".s"), O_RDONLY);
	else
		fd = open(av[1], O_RDONLY);
	if (fd == -1)
		quit(d, 2);
	save_input(d, fd);
	get_header(d, fd);
	//get_ops();
}
