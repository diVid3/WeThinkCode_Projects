/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:06:10 by egenis            #+#    #+#             */
/*   Updated: 2018/07/17 17:24:47 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static void		ft_no_moves(void)
{
	ft_putnbr(0);
	ft_putchar(' ');
	ft_putnbr(0);
	ft_putchar('\n');
}

static void		ft_print_move(t_move *move)
{
	ft_putnbr(move->row);
	ft_putchar(' ');
	ft_putnbr(move->col);
	ft_putchar('\n');
}

static t_move	*ft_optimal_move(t_move *head)
{
	t_move		*tmp;
	t_move		*opt_move;
	int			rating;

	tmp = head;
	opt_move = tmp;
	rating = 2147483647;
	while (tmp)
	{
		if (tmp->rating < rating)
		{
			opt_move = tmp;
			rating = tmp->rating;
		}
		tmp = tmp->next;
	}
	return (opt_move);
}

void			ft_place_piece(t_input *data)
{
	t_move		*moves;
	t_move		*opt_move;

	moves = ft_make_move_list(data);
	if (moves == NULL)
		ft_no_moves();
	if (moves == NULL)
		return ;
	ft_rate_moves(data, moves);
	opt_move = ft_optimal_move(moves);
	ft_print_move(opt_move);
	ft_free_list(moves);
}
