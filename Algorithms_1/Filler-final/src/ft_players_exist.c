/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_players_exist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:52:16 by egenis            #+#    #+#             */
/*   Updated: 2018/07/20 10:53:10 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static _Bool	ft_check_p1(t_input *data)
{
	_Bool		ans;
	int			cntr_rw;
	int			cntr_cl;

	ans = 0;
	cntr_rw = 0;
	while (cntr_rw < data->mp_rws)
	{
		cntr_cl = 0;
		while (cntr_cl < data->mp_cls)
		{
			if (data->mp[cntr_rw][cntr_cl] == 'o' ||
				data->mp[cntr_rw][cntr_cl] == 'O')
			{
				ans = 1;
				return (ans);
			}
			++cntr_cl;
		}
		++cntr_rw;
	}
	return (ans);
}

static _Bool	ft_check_p2(t_input *data)
{
	_Bool		ans;
	int			cntr_rw;
	int			cntr_cl;

	ans = 0;
	cntr_rw = 0;
	while (cntr_rw < data->mp_rws)
	{
		cntr_cl = 0;
		while (cntr_cl < data->mp_cls)
		{
			if (data->mp[cntr_rw][cntr_cl] == 'x' ||
				data->mp[cntr_rw][cntr_cl] == 'X')
			{
				ans = 1;
				return (ans);
			}
			++cntr_cl;
		}
		++cntr_rw;
	}
	return (ans);
}

int				ft_players_exist(t_input *data)
{
	int			ans;

	ans = -1;
	if (ft_check_p1(data) && ft_check_p2(data))
		ans = 0;
	return (ans);
}
