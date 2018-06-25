/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 07:09:30 by egenis            #+#    #+#             */
/*   Updated: 2018/06/25 07:30:32 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static	char	*ft_fd_to_line(int fd, char *arr_l, t_gl_mem *gm)
{
	t_ac_mem		mem;

	mem.nl_found = 0;
	mem.spd = 2;
	while (mem.nl_found == 0 && gm->read_b == BUFF_SIZE)
	{
		mem.free = arr_l;
		mem.tmp = ft_memalloc(sizeof(char) * (BUFF_SIZE * mem.spd) + 1);
		mem.cntr = 0;
		while (mem.cntr < mem.spd && mem.tmp)
		{
			gm->read_b = read(fd, mem.tmp + (gm->read_b * mem.cntr), BUFF_SIZE);
			++mem.cntr;
		}
		arr_l = ft_strjoin(arr_l, mem.tmp);
		if (mem.tmp)
			mem.nl_found = (ft_strchr(mem.tmp, '\n') == NULL) ? 0 : 1;
		if (*arr_l)
			ft_memdel((void **)(&mem.free));
		ft_memdel((void **)(&mem.tmp));
		mem.spd *= mem.spd;
	}
	return (mem.arr_l);
}

int		get_next_line(const int fd, char **line);
{
	static t_mem	mem = {"", NULL, NULL, NULL, NULL, 1};

	while (!mem.nl_addr && mem.read_b)
	{
		mem.free_me = mem.arr;
		mem.tmp = ft_memalloc(sizeof(char) * BUFF_SIZE + 1)
		mem.read_b = read(fd, mem.tmp, BUFF_SIZE);
		mem.arr = ft_strjoin(mem.arr, mem.tmp);
		mem.nl_addr = ft_strchr(mem.arr, '\n');
		if (*mem.free_me)
			ft_memdel((void **)(&free_me));
		ft_memdel((void **)(&mem.tmp));
	}
	*line = ft_strsub(mem.arr, 0, ft_strclen(mem.arr, '\n'));
	mem.arr = (mem.nl_addr) ? ft_strdup(mem.nl_addr + 1) : mem.arr;
}

int		main(int ac, char **av)
{
	int			fd;
	int			ans;
	char		**line;

	(void)ac;
	line = malloc(sizeof(void *));
	fd = open(av[1], O_RDONLY);

	return (0);
}
