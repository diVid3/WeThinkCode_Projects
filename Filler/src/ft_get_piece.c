/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 13:24:07 by egenis            #+#    #+#             */
/*   Updated: 2018/07/17 07:00:12 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static	int		ft_verify_piece_row(t_input *data, char **line)
{
	int			cntr;

	if (ft_count_words(*line, ' ') != 1)
		return (0);
	if (ft_strlen(*line) != (size_t)data->p_cls)
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

	if (!data->p_rws || !data->p_cls)
		return (-1);
	data->p = ft_alloc_mat_rows(data->p_rws);
	cntr = 0;
	while (cntr < data->p_rws)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		if (ft_verify_piece_row(data, &line) == 0)
			return (-1);
		data->p[cntr] = line;
		++cntr;
	}
	return (0);
}
