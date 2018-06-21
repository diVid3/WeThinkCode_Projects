/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:16:57 by egenis            #+#    #+#             */
/*   Updated: 2018/06/21 18:21:09 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	char	*ft_fd_to_line(int fd)
{
	t_ac_mem		mem;

	mem.nl_found = 0;
	mem.spd = 2;
	if (!(mem.arr_l = ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);
	mem.read_b = read(fd, arr_l, BUFF_SIZE);
	while (mem.nl_found == 0 && mem.read_b == BUFF_SIZE)
	{
		mem.free = mem.arr_l;
		mem.tmp = ft_memalloc(sizeof(char) * (BUFF_SIZE * mem.spd) + 1);
		mem.cntr = 0;
		while (mem.cntr < mem.spd)
		{
			mem.read_b = read(fd, tmp + (mem.read_b * mem.cntr), BUFF_SIZE);
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

static	char	*ft_prep_arr(int fd, t_c_mem *cm)
{
	char		*tmp;

	ft_memdel((void **)(&cm->arr_l));
	if (!(cm->arr_l = ft_fd_to_line(fd)))
		return (NULL);
	if(!(cm->last_nl = ft_strrchr(arr_l, '\n')))
		tmp = ft_strsub(cm->arr_l, 0, 0);
	else
		tmp = ft_strdup(cm->last_nl + 1);
	if (cm->last_nl)
		*(cm->last_nl + 1) = '\0';
	if (!cm->read_1ce)
	{
		cm->store = tmp;
		cm->read_1ce = 1;
		return (arr_l);
	}
	else
	{
		cm->arr_l = ft_strjoin(cm->store, cm->arr_l);
		ft_memdel((void **)(&cm->store));
		cm->store = tmp;
		return (arr_l);
	}
	return (NULL);
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

static	int		ft_set_line(char **line, t_c_mem *cm)
{
	if (*(cm->arr_l + cm->pos) == '\n' &&
			*(cm->arr_l + cm->pos - 1) == '\n' && cm->pos > 0)
	{
		*line = ft_strsub(cm->arr_l, 0, 0);
		++cm->pos;
		cm->prev_line = *line;
		return (1);
	}
	if (*(cm->arr_l) == '\n' && cm->pos == 0)
	{
		*line = ft_strsub(cm->arr_l, 0, 0);
		++cm->pos;
		cm->prev_line = *line;
		return (1);
	}
	if (*(cm->arr_l + cm->pos) != '\n' &&
			*(cm->arr_l + cm->pos) != '\0')
	{

	}

}

int				ft_controller(int fd, char **line)
{
	static	t_c_mem		cm = {NULL, NULL, NULL, NULL, 0, 0, 0};

}

int				get_next_line(const int fd, char **line)
{

}
