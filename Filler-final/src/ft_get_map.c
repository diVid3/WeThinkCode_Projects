/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 09:53:33 by egenis            #+#    #+#             */
/*   Updated: 2018/07/17 06:57:30 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static	int		ft_verify_top_ruler(char *line)
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

static	int		ft_verify_map_row(t_input *data, char **line)
{
	char		**arr;
	int			cntr;

	if (ft_count_words(*line, ' ') != 2)
		return (0);
	arr = ft_strsplit(*line, ' ');
	if (ft_strlen(arr[1]) != (size_t)data->mp_cls)
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
	ft_memdel((void **)(line));
	*line = arr[1];
	ft_del_matrix((void **)arr, 1);
	return (1);
}

int				ft_get_map(t_input *data)
{
	char		*line;
	int			cntr;

	if ((!data->mp_rws || !data->mp_cls) || (data->mp_rws == 1 &&
			data->mp_cls == 1))
		return (-1);
	if (get_next_line(0, &line) <= 0)
		return (-1);
	if (ft_verify_top_ruler(line) == 0)
		return (-1);
	data->mp = ft_alloc_mat_rows(data->mp_rws);
	cntr = 0;
	while (cntr < data->mp_rws)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		if (ft_verify_map_row(data, &line) == 0)
			return (-1);
		data->mp[cntr] = line;
		++cntr;
	}
	return (0);
}
