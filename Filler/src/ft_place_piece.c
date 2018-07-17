/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:06:10 by egenis            #+#    #+#             */
/*   Updated: 2018/07/17 08:26:44 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include <stdio.h>

void			ft_place_piece(t_input *data)
{
	t_move		*move;

	move = ft_make_move_list(data);
	//sleep(1);
	if (move)
	{
		dprintf(2, "First avaiable move is row -- %d ", move->row);
		ft_putnbr(move->row);
	}
	else
		ft_putnbr(0);
	ft_putchar(' ');
	if (move)
	{
		dprintf(2, "col -- %d\n", move->col);
		ft_putnbr(move->col);
	}
	else
		ft_putnbr(0);
	ft_putchar('\n');
	ft_free_list(move);
}
