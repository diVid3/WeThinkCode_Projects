/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:41:32 by egenis            #+#    #+#             */
/*   Updated: 2018/07/16 16:18:42 by egenis           ###   ########.fr       */
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

/*
void			print_arr2d(char **arr, size_t rows)
{
	size_t		cntr;

	cntr = 0;
	while (arr[cntr] && cntr < rows)
	{
		printf("%s\n", arr[cntr]);
		++cntr;
	}
	return ;
}

int		main(void)
{
	static t_input	data;
	int				ans;

	ans = ft_get_input(&data);
	printf("ft_get_input() returned %d\n", ans);
	if (ans == -1)
		return (0);
	if (ans == 2)
		return (0);
	printf("player_num is %d\n", data.player_num);
	printf("map_rows is %d\n", data.map_rows);
	printf("map_cols is %d\n", data.map_cols);
	print_arr2d(data.map, (size_t)data.map_rows);
	printf("piece_rows is %d\n", data.piece_rows);
	printf("piece_cols is %d\n", data.piece_cols);
	print_arr2d(data.piece, (size_t)data.piece_rows);
	sleep(60);
	return (0);
}
*/
