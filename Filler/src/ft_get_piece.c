/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 13:24:07 by egenis            #+#    #+#             */
/*   Updated: 2018/07/15 14:16:14 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include <stdio.h>

/*
static	int		ft_verify_piece_row(t_input *data, char **line)
{
	char		**arr;
	int			cntr;

	if (ft_count_words(*line, ' ') != 1)
		return (0);
	arr = ft_strsplit(*line, ' ');
	if (ft_strlen(arr[0]) != (size_t)data->piece_cols)
		return (0);
	cntr = 0;
	while (arr[0][cntr])
	{
		if (arr[0][cntr] != '.')
			if (arr[0][cntr] != '*')
				return (0);
		++cntr;
	}
	ft_memdel((void **)(&line));
	*line = arr[0];
	return (1);
}
*/

static	int		ft_verify_piece_row(t_input *data, char **line)
{
	int			cntr;

	if (ft_count_words(*line, ' ') != 1)
		return (0);
	if (ft_strlen(*line) != (size_t)data->piece_cols)
		return (0);
	cntr = 0;
	while ((*line)[cntr])
	{
		if ((*line)[cntr] != '.')
			if ((*line)[cntr] != '*')
				return (0);
		++cntr;
	}
	return (1);
}

void			print_arr2d(char **arr, size_t rows)
{
	size_t		cntr;

	cntr = 0;
	while (arr[cntr] && cntr < rows)
	{
		printf("%s\n", arr[cntr]);
		++cntr;
	}
	return ;
}

int				ft_get_piece(t_input *data)
{
	char		*line;
	int			cntr;

	if (!data->piece_rows || !data->piece_cols)
		return (-1);
	data->piece = ft_alloc_mat_rows(data->piece_rows);
	cntr = 0;
	while (cntr < data->piece_rows)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		//printf("Fail here 0?\n");
		if (ft_verify_piece_row(data, &line) == 0)
			return (-1);
		//printf("Fail here 1?\n");
		data->piece[cntr] = line;
		++cntr;
	}
	print_arr2d(data->piece, (size_t)data->piece_rows);
	return (0);
}

int		main(void)
{
	static t_input		data;
	int					ans;

	data.piece_rows = 4;
	data.piece_cols = 7;
	ans = ft_get_piece(&data);
	printf("ft_get_piece() returned %d\n", ans);
	return (0);
}
