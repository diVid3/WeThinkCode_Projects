/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:21:07 by egenis            #+#    #+#             */
/*   Updated: 2018/06/16 15:38:04 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static	char	*ft_file_to_arr(int fd)
{
	char		*arr_tmp;
	char		*arr_final;
	char		*free_me;
	ssize_t		read_bytes;
	t_accel		ac = {2, 0};

	if (!(arr_final = ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
			return (NULL);
	read_bytes = read(fd, arr_final, BUFF_SIZE);
	while (read_bytes > 0 && !(read_bytes < BUFF_SIZE))
	{
		free_me = arr_final;
		arr_tmp = ft_memalloc(sizeof(char) * (BUFF_SIZE * ac.spd) + 1);
		ac.cntr = 0;
		while (ac.cntr < ac.spd)
		{
			read_bytes = read(fd, arr_tmp + (read_bytes * ac.cntr), BUFF_SIZE);
			++ac.cntr;
		}
		arr_final = ft_strjoin(arr_final, arr_tmp);
		ft_memdel((void **)(&free_me));
		ft_memdel((void **)(&arr_tmp));
		ac.spd *= ac.spd;
	}
	printf("\nThis only ran once!\n\n");
	return (arr_final);
}

/*
static	char	*ft_set_line(t_mem *mem)
{
}
*/

int				get_next_line(const int fd, char **line)
{
	static t_mem	mem = {NULL, NULL, 0, 0};
	size_t			line_len;

	//printf("\n");
	if (!mem.arr_built)
		mem.arr_f = ft_file_to_arr(fd);
	if (!mem.arr_built)
		mem.arr_built = 1;
	ft_memdel((void **)(&mem.prev_line));
	if (*(mem.arr_f + mem.offset) == '\n' &&
		*(mem.arr_f + mem.offset - 1) == '\n' && mem.offset > 0)
	{
		printf("Back newline activates\n");
		*line = NULL;
		++mem.offset;
		printf("-------------------------------------------------------\n");
		printf("mem.offset        == %zu\n", mem.offset - 1);
		printf("line              == %s\n", *line);
		printf("-------------------------------------------------------\n");
		printf("\n");
		mem.prev_line = *line;
		return (1);
	}
	if (*(mem.arr_f) == '\n' && mem.offset == 0)
	{
		*line = NULL;
		printf("First newline activates\n");
		++mem.offset;
		printf("-------------------------------------------------------\n");
		printf("mem.offset        == %zu\n", mem.offset - 1);
		printf("line              == %s\n", *line);
		printf("-------------------------------------------------------\n");
		printf("\n");
		mem.prev_line = *line;
		return (1);
	}
	if (*(mem.arr_f + mem.offset) != '\n' && *(mem.arr_f + mem.offset) != '\0')
	{
		printf("Normal char activates\n");
		line_len = ft_strclen(mem.arr_f + mem.offset, '\n');
		*line = ft_strsub(mem.arr_f + mem.offset, 0, line_len);
		mem.offset += line_len + 1;
		printf("-------------------------------------------------------\n");
		printf("mem.offset        == %zu\n", mem.offset - 1);
		printf("line              == %s\n", *line);
		printf("Current norm char == %d\n", *(mem.arr_f + mem.offset));
		printf("-------------------------------------------------------\n");
		printf("\n");
		mem.prev_line = *line;
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int			fd;
	int			ans;
	char		**line;

	(void)ac;
	line = malloc(sizeof(void *));
	fd = open(av[1], O_RDONLY);
	ans = get_next_line(fd, line);
	ans = get_next_line(fd, line);
	ans = get_next_line(fd, line);
	ans = get_next_line(fd, line);
	ans = get_next_line(fd, line);
	ans = get_next_line(fd, line);
	ans = get_next_line(fd, line);
	return (0);
}