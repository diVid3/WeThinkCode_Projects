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
		if (ft_verify_piece_row(data, &line) == 0)
			return (-1);
		data->piece[cntr] = line;
		++cntr;
	}
	return (0);
}

/*
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
*/
