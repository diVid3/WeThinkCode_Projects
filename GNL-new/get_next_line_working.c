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
		if (*mem.free)
			ft_memdel((void **)(&mem.free));
		ft_memdel((void **)(&mem.tmp));
		mem.spd *= mem.spd;
	}
	return (arr_l);
}

int		get_next_line(const int fd, char **line)
{
	static t_gl_mem		gm = {"", NULL, NULL, 0, BUFF_SIZE, 1, 0, 0};

	ft_memdel((void **)(&gm.prev_line));
	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	gm.nl_found = (ft_strchr(gm.arr_l, '\n') == NULL) ? 0 : 1;
	if (!gm.nl_found && gm.read_b == BUFF_SIZE)
		gm.arr_l = ft_fd_to_line(fd, gm.arr_l, &gm);
	*line = ft_strsub(gm.arr_l, 0, ft_strclen(gm.arr_l, '\n'));
	gm.prev_line = *line;
	if (gm.arr_l && ft_strchr(gm.arr_l, '\n'))
	{
		gm.p_arr_l = gm.arr_l;
		gm.arr_l = ft_strdup(ft_strchr(gm.arr_l, '\n') + 1);
		ft_memdel((void **)(&gm.p_arr_l));
	}
	if (gm.arr_l && !(*gm.arr_l) && !gm.swtch)
	{
		gm.ret_val = 0;
		gm.swtch = 1;
		return (1);
	}
	return (gm.ret_val);
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
