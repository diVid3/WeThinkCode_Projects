/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 06:27:40 by egenis            #+#    #+#             */
/*   Updated: 2018/06/29 12:20:08 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void			print_test(char *line)
{
	if (!line)
		printf("*line is NULL\n");
	else if (*line == '\0')
		printf("(empty-string)\n", NULL);
	else
		printf("%s\n", line);
}

static int			build_arr(int fd, t_mem *m)
{
	char		*tmp;
	char		*prev_arr;

	if (!m->read_b)
		m->swtch = 0;
	if (!m->arr)
	{
		if (!(m->arr = ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
			return (-1);
		if ((m->read_b = read(fd, m->arr, BUFF_SIZE)) == -1)
			return (-1);
	}
	while (m->arr && !ft_strchr(m->arr, '\n') && m->read_b)
	{
		if (!(tmp = ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
			return (-1);
		if ((m->read_b = read(fd, tmp, BUFF_SIZE)) == -1)
			return (-1);
		prev_arr = m->arr;
		m->arr = ft_strjoin(m->arr, tmp);
		ft_memdel((void **)(&prev_arr));
		ft_memdel((void **)(&tmp));
	}
	return (0);
}

static void			ft_reset(int fd, t_mem *m)
{
	if (m->prev_fd != fd)
	{
		m->arr = NULL;
		m->read_b = 1;
		m->swtch = 1;
	}
	return ;
}

int					get_next_line(const int fd, char **line)
{
	static	t_mem	m = {NULL, NULL, -1, 1, 1};

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	ft_reset(fd, &m);
	m.prev_fd = fd;
	if ((build_arr(fd, &m)) == -1)
		return (-1);
	if (m.swtch)
		*line = ft_strsub(m.arr, 0, ft_strclen(m.arr, '\n'));
	else
		*line = ft_strsub(m.arr, 0, 0);
	if (m.arr && ft_strchr(m.arr, '\n'))
	{
		m.prev_arr = m.arr;
		m.arr = ft_strdup(ft_strchr(m.arr, '\n') + 1);
		ft_memdel((void **)(&m.prev_arr));
	}
	if (!m.read_b && !ft_strlen(*line))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int			fd;
	int			ans;
	char		*line;

	(void)ac;
	fd = open(av[1], O_RDONLY);

	for (int i = 0; i < 200000; i++)
	{
		printf("\n");
		printf("--------------------------------------------------------------\n");
		ans = get_next_line(fd, &line);
		print_test(line);
		printf("ans == %d\n", ans);
		printf("--------------------------------------------------------------\n");
	}

	printf("\n");
	return (0);
}
