/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:21:07 by egenis            #+#    #+#             */
/*   Updated: 2018/06/14 08:43:52 by egenis           ###   ########.fr       */
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
	return (arr_final);
}

/*
static	int		ft_split_arr(int fd, t_mem *mem)
{
	char		*str;

	if (mem->prep_mem == 0)
	{
		str = ft_file_to_arr(fd);
		if (!str)
			return (-1);
		mem->arr = ft_strsplit(str, '\n');
		ft_memdel((void **)(&str));
		if (!mem->arr)
			return (-1);
		mem->prep_mem = 1;
	}
	return (1);
}

static	int		ft_split_arr(int fd, t_mem *mem)
{
	char		*str;

	if (!mem->build_mem)
	{
		str = ft_file_to_arr(fd);
		if (!str)
			return (-1);
		mem->build_mem = 1;
	}
	if (!mem->split_mem && str)
	{
		mem->arr = ft_strsplit(str);
		ft_memdel((void **)(&str));
		if (!mem->arr)
			return (-1);
		mem->split_mem = 1;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_mem	mem = {NULL, 0, 0};
	int				arr_split;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if ((arr_split = ft_split_arr(fd, &mem)) == -1)
		return (-1);
	//if (mem.line_cntr > 0)
	//	free((*mem.arr) + mem.line_cntr - 1);
	*line = *(mem.arr) + mem.line_cntr;
	//if (!(*line))
	//{
	//	free(mem.arr);
	//	mem.arr = NULL;
	//	return (0);
	//}
	++(mem.line_cntr);
	return (1);
}
*/

int	main(int ac, char **av)
{
	int			fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	printf("%s", ft_file_to_arr(fd));
	return (0);
}
