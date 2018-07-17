/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rate_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:08:16 by egenis            #+#    #+#             */
/*   Updated: 2018/07/17 16:32:31 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include <stdio.h>

static t_star	ft_optmze_rating(t_input *d, t_move *n)
{
	t_star	star_pos;
	int		p_rw;
	int		p_cl;

	star_pos.rw = n->row;
	star_pos.cl = n->col;
	p_rw = 0;
	while (p_rw < d->p_rws)
	{
		p_cl = 0;
		while (p_cl < d->p_cls)
		{
			if (d->p[p_rw][p_cl] == '*')
			{
				star_pos.rw = n->row + p_rw;
				star_pos.cl = n->col + p_cl;
				return (star_pos);
			}
			++p_cl;
		}
		++p_rw;
	}
	return (star_pos);
}

static void		ft_rate_move_p1(t_input *d, t_move *n)
{
	int		rating;
	int		rw;
	int		cl;
	t_star	s_pos;

	s_pos = ft_optmze_rating(d, n);
	rw = 0;
	while (rw < d->mp_rws)
	{
		cl = 0;
		while (cl < d->mp_cls)
		{
			if (d->mp[rw][cl] == 'x' || d->mp[rw][cl] == 'X')
				rating = ((s_pos.rw - rw) * (s_pos.rw - rw)) +
						((s_pos.cl - cl) * (s_pos.cl - cl));
			if (rating < n->rating)
				n->rating = rating;
			//dprintf(2, "n->rating is %d\n", n->rating);
			++cl;
		}
		++rw;
	}
}

static void		ft_rate_move_p2(t_input *d, t_move *n)
{
	int		rating;
	int		rw;
	int		cl;
	t_star	s_pos;

	s_pos = ft_optmze_rating(d, n);
	rw = 0;
	while (rw < d->mp_rws)
	{
		cl = 0;
		while (cl < d->mp_cls)
		{
			if (d->mp[rw][cl] == 'o' || d->mp[rw][cl] == 'O')
				rating = ((s_pos.rw - rw) * (s_pos.rw - rw)) +
						((s_pos.cl - cl) * (s_pos.cl - cl));
			if (rating < n->rating)
				n->rating = rating;
			//dprintf(2, "n->rating is %d\n", n->rating);
			++cl;
		}
		++rw;
	}
}

void			ft_rate_moves(t_input *data, t_move *head)
{
	while (head)
	{
		if (data->player_num == 1)
			ft_rate_move_p1(data, head);
		if (data->player_num == 2)
			ft_rate_move_p2(data, head);
		head = head->next;
	}
	return ;
}
