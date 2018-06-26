/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 07:09:30 by egenis            #+#    #+#             */
/*   Updated: 2018/06/26 18:30:40 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static	void	ft_build_line(int fd, t_gnl_mem *m)
{
	char		*tmp;
	char		*prev_arr_l;

	while (!ft_strchr(m->arr_l, '\n') && m->read_b)
	{
		prev_arr_l = m->arr_l;
		tmp = ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
		m->read_b = read(fd, tmp, BUFF_SIZE);
		m->arr_l = ft_strjoin(m->arr_l, tmp);
		ft_memdel((void **)(&prev_arr_l));
		ft_memdel((void **)(&tmp));
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl_mem	m = {NULL, NULL, 0, 0};

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (!m.arr_l)
		if (!(m.arr_l = ft_memalloc(sizeof(char) * BUFF_SIZE + 1))
			|| ((m.read_b = read(fd, m.arr_l, BUFF_SIZE)) == -1))
			return (-1);
	if (!ft_strchr(m.arr_l, '\n') && m.read_b)
		ft_build_line(fd, &m);
	*line = ft_strsub(m.arr_l, 0, ft_strclen(m.arr_l, '\n'));
	m.prev_arr_l = m.arr_l;
	if (m.read_b)
	{
		m.arr_l = ft_strdup(ft_strchr(m.arr_l, '\n') + 1);
		ft_memdel((void **)(&m.prev_arr_l));
		return (1);
	}
	if (!m.read_b && !m.swtch && ft_strlen(*line))
	{
		m.swtch = 1;
		return (1);
	}
	//*line = ft_strdup("");
	return (0);
}

void			print_test(char *line)
{
	if (!line)
		printf("*line is NULL\n");
	else if (*line == '\0')
		printf("(empty-string)\n", NULL);
	else
		printf("%s\n", line);
}

int		main(int ac, char **av)
{
	int			fd;
	//int			ans;
	char		*line;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	//fd = 42;
	printf("ans == %d\n*line == %s\n", get_next_line(fd, &line), line);

	//while (get_next_line(fd, &line))
	//	ft_putendl(line);

	return (0);
}
