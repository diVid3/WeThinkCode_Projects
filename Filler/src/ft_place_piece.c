/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:06:10 by egenis            #+#    #+#             */
/*   Updated: 2018/07/17 13:43:02 by egenis           ###   ########.fr       */
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
	t_move		*move;

	move = ft_make_move_list(data);
	sleep(1);
	if (move == NULL)
		ft_no_moves();
	if (move == NULL)
		return ;
	row = move->row;
	col = move->col;
	rating = move->rating;
	while (move)
	{
		if (move->rating <= rating)
		{
			row = move->row;
			col = move->col;
			rating = move->rating;
		}
		move = move->next;
	}
	ft_print_move(row, col);
	ft_free_list(move);
}
