/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:16:57 by egenis            #+#    #+#             */
/*   Updated: 2018/06/21 18:22:23 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static	char	*ft_fd_to_line(int fd, t_c_mem *cm)
{
	t_ac_mem		mem;

	mem.nl_found = 0;
	mem.spd = 2;
	if (!(mem.arr_l = ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);
	cm->read_b = read(fd, mem.arr_l, BUFF_SIZE);
	while (mem.nl_found == 0 && cm->read_b == BUFF_SIZE)
	{
		mem.free = mem.arr_l;
		mem.tmp = ft_memalloc(sizeof(char) * (BUFF_SIZE * mem.spd) + 1);
		mem.cntr = 0;
		while (mem.cntr < mem.spd && mem.tmp)
		{
			cm->read_b = read(fd, mem.tmp + (cm->read_b * mem.cntr), BUFF_SIZE);
			++mem.cntr;
		}
		mem.arr_l = ft_strjoin(mem.arr_l, mem.tmp);
		mem.nl_found = *(ft_strchr(mem.tmp, '\n'));
		ft_memdel((void **)(&mem.free));
		ft_memdel((void **)(&mem.tmp));
		mem.spd *= mem.spd;
	}
	return (mem.arr_l);
}

static	int		ft_prep_arr_l(int fd, t_c_mem *cm)
{
	char		*old_store;
	char		*free_me;

	old_store = cm->store;
	if (!(cm->arr_l = ft_fd_to_line(fd, cm)))
		return (-1);
	if (!cm->read_b)
		ft_memdel((void **)(&cm->arr_l));
	if (!cm->read_b)
		return (0);
	if(!(cm->last_nl = ft_strrchr(cm->arr_l, '\n')))
		cm->store = ft_strsub(cm->arr_l, 0, 0);
	else
		cm->store = ft_strdup(cm->last_nl + 1);
	if (cm->last_nl)
		*(cm->last_nl + 1) = '\0';
	if (old_store)
	{
		free_me = cm->arr_l;
		cm->arr_l = ft_strjoin(old_store, cm->arr_l);
		ft_memdel((void **)(&free_me));
		ft_memdel((void **)(&old_store));
	}
	return (1);
}

static	int		ft_set_line(char **line, t_c_mem *cm)
{
	if (*(cm->arr_l + cm->pos) == '\n' && cm->pos > 0)
	{
		if (*(cm->arr_l + cm->pos - 1) == '\n')
		{
			*line = ft_strsub(cm->arr_l, 0, 0);
			++cm->pos;
			return (1);
		}
		++cm->pos;
	}
	if (*(cm->arr_l) == '\n' && cm->pos == 0)
	{
		*line = ft_strsub(cm->arr_l, 0, 0);
		++cm->pos;
		return (1);
	}
	if (*(cm->arr_l + cm->pos) != '\n' && *(cm->arr_l + cm->pos) != '\0')
	{
		cm->line_len = ft_strclen(cm->arr_l + cm->pos, '\n');
		*line = ft_strsub(cm->arr_l + cm->pos, 0, cm->line_len);
		cm->pos += cm->line_len;
		return (1);
	}
	return (0);
}

static	int		ft_controller(int fd, char **line)
{
	static	t_c_mem	cm = {NULL, NULL, NULL, NULL, 0, 0, 0, 0};
	int				ans_pa;
	int				ans_sl;

	ft_memdel((void **)(&cm.prev_l));
	ft_memdel((void **)(&cm.arr_l));
	ans_pa = ft_prep_arr_l(fd, &cm);
	if (ans_pa == 0 || ans_pa == -1)
		ft_memdel((void **)(&cm.store));
	if (ans_pa == 0 || ans_pa == -1)
		return (ans_pa);
	ans_sl = ft_set_line(line, &cm);
	cm.prev_l = *line;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int		ans_c;

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	ans_c = ft_controller(fd, line);
	if (ans_c == 0 || ans_c == -1)
		return (ans_c);
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

	printf("\n");
	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	printf("---------------------------------------------------------------\n");
	ans = get_next_line(fd, line);
	print_test(*line);
	printf("last ans == %d\n", ans);
	printf("---------------------------------------------------------------\n");
	printf("\n");

	return (0);
}