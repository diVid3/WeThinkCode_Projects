/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:16:57 by egenis            #+#    #+#             */
/*   Updated: 2018/06/21 10:18:38 by egenis           ###   ########.fr       */
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
	ft_memdel((void **)(&cm->arr_l));
	//ft_memdel((void **)(&cm->old_store));
	if (!(cm->arr_l = ft_fd_to_line(fd)))
		return (NULL);
	if (!cm->read_1ce)
	{
		cm->last_nl = ft_strrchr(arr_l, '\n');
		cm->store = ft_strdup(last_nl + 1);
	}

}

int				ft_controller(int fd, char **line)
{
	static	t_c_mem		cm = {NULL, NULL, NULL, 0};

	arr_l = ft_fd_to_line(fd);
	last_nl = ft_strrchr(arr_l, '\n');
	if (last_nl)
		store = ft_strdup(arr_l + 1);

}

int				get_next_line(const int fd, char **line)
{

}
