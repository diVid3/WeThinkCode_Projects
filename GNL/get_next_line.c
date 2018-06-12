/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:21:07 by egenis            #+#    #+#             */
/*   Updated: 2018/06/12 06:46:04 by egenis           ###   ########.fr       */
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
	size_t		multiplier;
	ssize_t		read_bytes;

	multiplier = BUFF_SIZE;
	if (!(arr_final = ft_memalloc(sizeof(char) * multiplier + 1)))
			return (NULL);
	read_bytes = read(fd, arr_final, multiplier);
	while (read_bytes > 0 && !(read_bytes < BUFF_SIZE))
	{
		free_me = arr_final;
		arr_tmp = ft_memalloc(sizeof(char) * multiplier + 1);
		read_bytes = read(fd, arr_tmp, multiplier);
		arr_final = ft_strjoin(arr_final, arr_tmp);
		ft_memdel((void **)(&free_me));
		ft_memdel((void **)(&arr_tmp));
		multiplier *= 2;
	}
	return (arr_final);
}

/*
static	char	**ft_split_file(char *str)
{
	char		**ar;

	ar = ft_strsplit(str, '\n');
	if (!ar)
		return (NULL);
}
*/

int				get_next_line(const int fd, char **line)
{
	char		*str;

	(void)line;
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	str = ft_file_to_arr(fd);
	printf("%s", str);
	return (1);
}

int	main(int ac, char **av)
{
	(void)ac;
	char		**line = NULL;
	int ans = get_next_line(open(av[1], O_RDONLY), line);
	(void)ans;
	return (0);
}
