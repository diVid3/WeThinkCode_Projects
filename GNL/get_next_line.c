/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:16:57 by egenis            #+#    #+#             */
/*   Updated: 2018/06/19 18:41:03 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	char	*ft_fd_to_line(int fd)
{
	t_ac_mem		mem;

	mem.nl_found = 0;
	mem.spd = 2;
	if (!(mem.arr_f = ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);
	mem.read_b = read(fd, arr_f, BUFF_SIZE);
	while (mem.nl_found == 0 && !(mem.read_b < BUFF_SIZE))
	{
		mem.free = mem.arr_f;
		mem.tmp = ft_memalloc(sizeof(char) * (BUFF_SIZE * mem.spd) + 1);
		mem.cntr = 0;
		while (mem.cntr < mem.spd)
		{
			mem.read_b = read(fd, tmp, BUFF_SIZE);
			++mem.cntr;
		}
		mem.arr_f = ft_strjoin(mem.arr_f, mem.tmp);
		mem.nl_found = *(ft_strchr(mem.tmp, '\n'));
		ft_memdel((void **)(&mem.free));
		ft_memdel((void **)(&mem.tmp));
		mem.spd *= mem.spd;
	}
	return (mem.arr_f);
}

int				get_next_line(const int fd, char **line)
{
	static	char	*arr_f = NULL;
	static	char	*last_nl = NULL;
	static	char	*store = NULL;

	arr_f = ft_fd_to_line(fd);
	last_nl = ft_strrchr(arr_f, '\n');
	store = ft_strdup(last_nl + 1);
}
