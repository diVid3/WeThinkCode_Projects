/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:16:54 by egenis            #+#    #+#             */
/*   Updated: 2018/07/17 08:20:08 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static _Bool	ft_out_of_bounds(t_input *data, int map_row, int map_col)
{
	if (map_row + data->p_rws > data->mp_rws ||
		map_col + data->p_cls > data->mp_cls)
		return (0);
	return (1);
}

_Bool	ft_can_place_p1(t_input *d, int m_rw, int m_cl)
{
	int		p_rw;
	int		p_cl;

	d->overlaps = 0;
	if (ft_out_of_bounds(d, m_rw, m_cl) == 0)
		return (0);
	p_rw = 0;
	while (p_rw < d->p_rws)
	{
		p_cl = 0;
		while (p_cl < d->p_cls)
		{
			if ((d->mp[m_rw + p_rw][m_cl + p_cl] == 'x' ||
				d->mp[m_rw + p_rw][m_cl + p_cl] == 'X') &&
				d->p[p_rw][p_cl] == '*')
				return (0);
			if ((d->mp[m_rw + p_rw][m_cl + p_cl] == 'o' ||
				d->mp[m_rw + p_rw][m_cl + p_cl] == 'O') &&
				d->p[p_rw][p_cl] == '*')
				++d->overlaps;
			++p_cl;
		}
		++p_rw;
	}
	return ((d->overlaps == 1) ? 1 : 0);
}

_Bool	ft_can_place_p2(t_input *d, int m_rw, int m_cl)
{
	int		p_rw;
	int		p_cl;

	d->overlaps = 0;
	if (ft_out_of_bounds(d, m_rw, m_cl) == 0)
		return (0);
	p_rw = 0;
	while (p_rw < d->p_rws)
	{
		p_cl = 0;
		while (p_cl < d->p_cls)
		{
			if ((d->mp[m_rw + p_rw][m_cl + p_cl] == 'o' ||
				d->mp[m_rw + p_rw][m_cl + p_cl] == 'O') &&
				d->p[p_rw][p_cl] == '*')
				return (0);
			if ((d->mp[m_rw + p_rw][m_cl + p_cl] == 'x' ||
				d->mp[m_rw + p_rw][m_cl + p_cl] == 'X') &&
				d->p[p_rw][p_cl] == '*')
				++d->overlaps;
			++p_cl;
		}
		++p_rw;
	}
	return ((d->overlaps == 1) ? 1 : 0);
}
