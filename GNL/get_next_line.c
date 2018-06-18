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

static	char	*ft_fd_to_arr(int fd)
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
	return (arr_final);
}

static	int		ft_set_line(char **line, t_mem *mem)
{
	if (*(mem->arr_f + mem->offset) == '\n' &&
		*(mem->arr_f + mem->offset - 1) == '\n' && mem->offset > 0)
	{
		*line = ft_strsub(mem->arr_f, 0, 0);
		++mem->offset;
		mem->prev_line = *line;
		return (1);
	}
	if (*(mem->arr_f) == '\n' && mem->offset == 0)
	{
		*line = ft_strsub(mem->arr_f, 0, 0);
		++mem->offset;
		mem->prev_line = *line;
		return (1);
	}
	if (*(mem->arr_f + mem->offset) != '\n' &&
		*(mem->arr_f + mem->offset) != '\0')
	{
		mem->line_len = ft_strclen(mem->arr_f + mem->offset, '\n');
		*line = ft_strsub(mem->arr_f + mem->offset, 0, mem->line_len);
		mem->offset += mem->line_len + 1;
		mem->prev_line = *line;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_mem	mem = {NULL, NULL, 0, 0, 0};
	int				ans;

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (!mem.arr_built)
		mem.arr_f = ft_fd_to_arr(fd);
	if (!mem.arr_built)
		mem.arr_built = 1;
	if (!mem.arr_f)
		return (-1);
	*line = NULL;
	ft_memdel((void **)(&mem.prev_line));
	ans = ft_set_line(line, &mem);
	if (!ans)
	{
		ft_memdel((void **)(line));
		ft_memdel((void **)(&mem.arr_f));
		return (0);
	}
	return (1);
}

void			print_test(char *line)
{
	if (!line)
		printf("*line is NULL\n");
	else if (*line == '\0')
		printf("%s\n", NULL);
	else
		printf("%s\n", line);
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
	print_test(*line);

	ans = get_next_line(fd, line);
	print_test(*line);

	ans = get_next_line(fd, line);
	print_test(*line);

	ans = get_next_line(fd, line);
	print_test(*line);

	ans = get_next_line(fd, line);
	print_test(*line);

	ans = get_next_line(fd, line);
	print_test(*line);

	ans = get_next_line(fd, line);
	print_test(*line);

	ans = get_next_line(fd, line);
	print_test(*line);

	ans = get_next_line(fd, line);
	print_test(*line);

	ans = get_next_line(fd, line);
	print_test(*line);
	printf("last ans == %d\n", ans);

	sleep(60);

	return (0);
}