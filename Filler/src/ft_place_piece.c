/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:06:10 by egenis            #+#    #+#             */
/*   Updated: 2018/07/16 11:18:04 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static _Bool	ft_can_place(t_input *data, int map_row, int map_col)
{
}

static void		ft_add_node(t_move **head, int map_row, int map_col)
{
}

static void		ft_make_move_list(t_input *data)
{
	t_move		*head;
	size_t		cntr_row;
	size_t		cntr_col;

	head = NULL;
	cntr_row = 0;
	while (cntr_row < data->map_rows)
	{
		cntr_col = 0;
		while (cntr_col < data->map_cols)
		{
			if (ft_can_place(data, cntr_row, cntr_col) == 0)
				continue;
			else
				ft_add_node(&head, cntr_row, cntr_col);
			++cntr_col
		}
		++cntr_row;
	}
}

void			ft_place_piece()
{
}
