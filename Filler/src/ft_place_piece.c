/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:06:10 by egenis            #+#    #+#             */
/*   Updated: 2018/07/17 15:21:17 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include <stdio.h>

static void		ft_no_moves(void)
{
	ft_putnbr(0);
	ft_putchar(' ');
	ft_putnbr(0);
	ft_putchar('\n');
}

static void		ft_print_move(int row, int col)
{
	ft_putnbr(row);
	ft_putchar(' ');
	ft_putnbr(col);
	ft_putchar('\n');
}

void			ft_place_piece(t_input *data)
{
	int			row;
	int			col;
	int			rating;
	t_move		*moves;

	moves = ft_make_move_list(data);
	//sleep(1);
	if (moves == NULL)
		ft_no_moves();
	if (moves == NULL)
		return ;
	ft_rate_moves(data, moves);
	rating = moves->rating;
	//dprintf(2, "rating is %d\n", rating);
	while (moves)
	{
		if (moves->rating <= rating)
		{
			row = moves->row;
			col = moves->col;
			rating = moves->rating;
			//dprintf(2, "rating is %d\n", rating);
		}
		moves = moves->next;
	}
	ft_print_move(row, col);
	ft_free_list(moves);
}
