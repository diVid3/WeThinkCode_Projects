/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:41:32 by egenis            #+#    #+#             */
/*   Updated: 2018/07/17 07:01:11 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int				ft_get_input(t_input *data)
{
	int			ans_g_m_s;

	if (!data->read_1st)
		if (ft_get_player_num(data) == -1)
			return (-1);
	if (!data->read_1st)
		data->read_1st = 1;
	ans_g_m_s = ft_get_map_size(data);
	if (ans_g_m_s == -1)
		return (-1);
	if (ans_g_m_s == 2)
		return (2);
	if (ft_get_map(data) == -1)
		return (-1);
	if (ft_get_piece_size(data) == -1)
		return (-1);
	if (ft_get_piece(data) == -1)
		return (-1);
	return (0);
}
