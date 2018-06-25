/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 07:09:30 by egenis            #+#    #+#             */
/*   Updated: 2018/06/25 13:49:38 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static	void	ft_build_line(int fd, t_gnl_mem *m)
{
	char		*tmp;
	char		*prev;

	while (!ft_strchr(m->arr_l, '\n') && m->read_b)
	{
		prev = m->arr_l;
		tmp = ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
		m->read_b = read(fd, tmp, BUFF_SIZE);
		m->arr_l = ft_strjoin(m->arr_l, tmp);
		ft_memdel((void **)(&prev));
		ft_memdel((void **)(&tmp));
	}
}

int				get_next_line(const int fd, char **line)
{
	t_gnl_mem		m = {NULL, NULL, NULL, 0};

	ft_memdel((void **)(&m.prev_l));
	if (!m.arr_l)
	{
		if(!(m.arr_l = ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
			return (-1);
		m.read_b = read(fd, m.arr_l, BUFF_SIZE);
	}
	if (!ft_strchr(m.arr_l, '\n') && m.read_b)
		ft_build_line(fd, &m);
	*line = ft_strsub(m.arr_l, 0, ft_strclen(m.arr_l, '\n'));
	m.prev_l = *line;
	m.prev_arr_l = m.arr_l;
	m.arr_l = ft_strdup(ft_strchr(m.arr_l, '\n') + 1);
	ft_memdel((void **)(&m.prev_arr_l));
	return (1);
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
	int			ans;
	char		**line;

	(void)ac;
	line = malloc(sizeof(void *));
	fd = open(av[1], O_RDONLY);

	printf("\n");
	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("\n");
	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("\n");
	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("\n");
	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("\n");
	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("\n");
	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("\n");
	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("\n");
	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	//sleep(60);

	return (0);
}
