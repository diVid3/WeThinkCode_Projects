/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 09:53:33 by egenis            #+#    #+#             */
/*   Updated: 2018/07/15 10:40:42 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include <stdio.h>

static	int		verify_top_ruler(char *line)
{
	char		**arr;
	size_t		cntr;

	if (ft_count_words(line, ' ') != 1)
		return (0);
	arr = ft_strsplit(line, ' ');
	cntr = 0;
	while (arr[0][cntr])
	{
		if (!(arr[0][cntr] >= '0' && arr[0][cntr] <= '9'))
			return (0);
		++cntr;
	}
	ft_memdel((void **)(&line));
	ft_del_matrix((void **)arr, 1);
	return (1);
}

static	int		verify_map_row(t_input *data, char *line)
{
	char		**arr;
	size_t		cntr;

	if (ft_count_words(line, ' ') != 2)
		return (0);
	arr = ft_strsplit(line, ' ');
	if (ft_strlen(arr[1]) != data->map_cols)
		return (0);
	cntr = 0;
	while (arr[1][cntr])
	{
		if (arr[1][cntr] != '.')
			if (arr[1][cntr] != 'o')
				if (arr[1][cntr] != 'O')
					if (arr[1][cntr] != 'x')
						if (arr[1][cntr] != 'X')
							return (0);
		++cntr;
	}
	ft_memdel((void **)(&line));
	return (1);
}

int				get_map(t_input *data)
{
	char		*line
	char		**arr;
	size_t		cntr;

	if ((!data->map_rows || !data->map_cols) || (data->map_rows == 1 &&
			data->map_cols == 1))
		return (-1);
	if (get_next_line(0, &line) <= 0)
		return (-1);
	if (verify_top_ruler(line) == 0)
		return (-1);
	arr = ft_alloc_mat_rows(data->map_rows);
	cntr = 0;
	while (cntr < data->map_rows)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		++cntr;
	}
	return (0);
}

int 	main(void)
{
}
