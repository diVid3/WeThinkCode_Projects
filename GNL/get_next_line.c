/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:21:07 by egenis            #+#    #+#             */
/*   Updated: 2018/06/15 14:28:52 by egenis           ###   ########.fr       */
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

static	char	*ft_arr_to_line(char *arr_final, size_t offset)
{
	size_t		cntr;
	size_t		line_len;
	char		*line;

	
}

int				get_next_line(const int fd, char **line)
{
	size_t		cntr;
	char		*arr;

	(void)line;
	cntr = 0;
	arr = ft_file_to_arr(fd);
	while (arr[cntr])
	{

	}
	return (1);
}

int	main(int ac, char **av)
{
	int			fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	printf("%s", ft_file_to_arr(fd));
	return (0);
}
