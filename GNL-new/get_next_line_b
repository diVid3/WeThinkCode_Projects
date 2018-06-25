/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 06:26:23 by egenis            #+#    #+#             */
/*   Updated: 2018/06/25 07:09:23 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static	char	*ft_fd_to_line(int fd, t_gl_mem *gm)
{
	t_ac_mem		mem;

	mem.nl_found = 0;
	mem.spd = 2;
	if (!(mem.arr_l = ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);
	gm->read_b = read(fd, mem.arr_l, BUFF_SIZE);
	while (mem.nl_found == 0 && gm->read_b == BUFF_SIZE)
	{
		mem.free = mem.arr_l;
		mem.tmp = ft_memalloc(sizeof(char) * (BUFF_SIZE * mem.spd) + 1);
		mem.cntr = 0;
		while (mem.cntr < mem.spd && mem.tmp)
		{
			gm->read_b = read(fd, mem.tmp + (gm->read_b * mem.cntr), BUFF_SIZE);
			++mem.cntr;
		}
		mem.arr_l = ft_strjoin(mem.arr_l, mem.tmp);
		if (mem.tmp)
			mem.nl_found = (ft_strchr(mem.tmp, '\n') == NULL) ? 0 : 1;
		ft_memdel((void **)(&mem.free));
		ft_memdel((void **)(&mem.tmp));
		mem.spd *= mem.spd;
	}
	return (mem.arr_l);
}

int				get_next_line(const int fd, char **line)
{
	static t_gl_mem		gm = {NULL, 0, 1};

	gm.arr_l = ft_fd_to_line(fd, &gm);
	gm.nl_pos = ft_strclen(gm.arr_l, '\n');
}

int		main(int ac, char **av)
{
	int			fd;
	int			ans;
	char		**line;

	(void)ac;
	line = malloc(sizeof(void *));
	fd = open(av[1], O_RDONLY);
}
