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
	printf("This only got run once!\n");
	return (arr_final);
}

/*
static	char	*ft_get_line(char *arr_f, size_t offset)
{
	size_t				line_len;
	char				*line;

	line_len = ft_strclen(arr_f + cntr, '\n');
	*line = ft_strsub(arr_f + cntr, 0, line_len);
}
*/

int				get_next_line(const int fd, char **line)
{
	static char			*arr_f = NULL;
	static char			*prev_line = NULL;
	static size_t		arr_f_len = 0;
	static size_t		offset = 0;
	static _Bool		file_built = 0;
	size_t				line_len;

	if (!file_built)
		arr_f = ft_file_to_arr(fd);
	if (!file_built)
		file_built = 1;
	if (prev_line)
		free(prev_line);
	line_len = ft_strclen(arr_f + offset, '\n');
	*line = ft_strsub(arr_f + offset, 0, line_len);
	prev_line = *line;
	if (line_len == 0 && offset < arr_f_len)
		++offset;
	else
		offset += line_len;
	return (1);
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
	printf("%s", *line);
	return (0);
}
