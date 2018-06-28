/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 06:27:40 by egenis            #+#    #+#             */
/*   Updated: 2018/06/28 16:40:48 by egenis           ###   ########.fr       */
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

static int			build_str(int fd, t_mem *m)
{
	char		*tmp;
	char		*prev_str;

	while (m->str && !ft_strchr(m->str, '\n') && m->read_b)
	{
		prev_str = m->str;
		if (!(tmp = ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
			return (-1);
		if ((m->read_b = read(fd, tmp, BUFF_SIZE)) == -1)
			return (-1);
		m->str = ft_strjoin(m->str, tmp);
		if (*prev_str != '\0')
			ft_memdel((void **)(&prev_str));
		ft_memdel((void **)(&tmp));
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_mem	m = {"", NULL, -1, 1};

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (m.prev_fd != fd)
		m.str = "";
	if (m.prev_fd != fd)
		m.read_b = 1;
	m.prev_fd = fd;
	if (m.str && !ft_strchr(m.str, '\n') && m.read_b)
		if ((build_str(fd, &m)) == -1)
			return (-1);
	*line = ft_strsub(m.str, 0, ft_strclen(m.str, '\n'));
	m.prev_str = m.str;
	if (m.str && ft_strchr(m.str, '\n')) // Fixes segfault.
		m.str = ft_strdup(ft_strchr(m.str, '\n') + 1);
	//ft_memdel((void **)(&m.prev_str));
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

	//while (get_next_line(fd, &line))
	//{
	//	ft_putendl(line);
	//	free(line);
	//}

	for (int i = 0; i < 50; i++)
	{
		printf("\n");
		printf("--------------------------------------------------------------\n");
		ans = get_next_line(fd, &line);
		print_test(line);
		printf("ans == %d\n", ans);
		printf("--------------------------------------------------------------\n");
	}

	//sleep(5);

	/*
	printf("\n");
	printf("--------------------------------------------------------------\n");
	ans = get_next_line(fd, &line);
	print_test(line);
	printf("ans == %d\n", ans);
	printf("--------------------------------------------------------------\n");

	printf("\n");
	printf("--------------------------------------------------------------\n");
	ans = get_next_line(fd, &line);
	print_test(line);
	printf("ans == %d\n", ans);
	printf("--------------------------------------------------------------\n");
	
	printf("\n");
	printf("--------------------------------------------------------------\n");
	ans = get_next_line(fd, &line);
	print_test(line);
	printf("ans == %d\n", ans);
	printf("--------------------------------------------------------------\n");

	printf("\n");
	printf("--------------------------------------------------------------\n");
	ans = get_next_line(fd, &line);
	print_test(line);
	printf("ans == %d\n", ans);
	printf("--------------------------------------------------------------\n");

	printf("\n");
	printf("--------------------------------------------------------------\n");
	ans = get_next_line(fd, &line);
	print_test(line);
	printf("ans == %d\n", ans);
	printf("--------------------------------------------------------------\n");

	printf("\n");
	printf("--------------------------------------------------------------\n");
	ans = get_next_line(fd, &line);
	print_test(line);
	printf("ans == %d\n", ans);
	printf("--------------------------------------------------------------\n");

	printf("\n");
	printf("--------------------------------------------------------------\n");
	ans = get_next_line(fd, &line);
	print_test(line);
	printf("ans == %d\n", ans);
	printf("--------------------------------------------------------------\n");
	*/

	printf("\n");
	return (0);
}
