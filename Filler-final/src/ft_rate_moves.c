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

static void		ft_rate_move_p1(t_input *d, t_move *n)
{
	int			rating;
	int			rw;
	int			cl;
	t_midpos	p_mid;

	p_mid = ft_optmze(d, n);
	rw = 0;
	while (rw < d->mp_rws)
	{
		cl = 0;
		while (cl < d->mp_cls)
		{
			if (d->mp[rw][cl] == 'x' || d->mp[rw][cl] == 'X')
				rating = ((p_mid.rw - rw) * (p_mid.rw - rw)) +
						((p_mid.cl - cl) * (p_mid.cl - cl));
			if (rating < n->rating)
				n->rating = rating;
			++cl;
		}
		++rw;
	}
	return ;
}

static void		ft_rate_move_p2(t_input *d, t_move *n)
{
	int			rating;
	int			rw;
	int			cl;
	t_midpos	p_mid;

	p_mid = ft_optmze(d, n);
	rw = 0;
	while (rw < d->mp_rws)
	{
		cl = 0;
		while (cl < d->mp_cls)
		{
			if (d->mp[rw][cl] == 'o' || d->mp[rw][cl] == 'O')
				rating = ((p_mid.rw - rw) * (p_mid.rw - rw)) +
						((p_mid.cl - cl) * (p_mid.cl - cl));
			if (rating < n->rating)
				n->rating = rating;
			++cl;
		}
		++rw;
	}
	return ;
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
