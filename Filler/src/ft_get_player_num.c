/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 09:51:13 by egenis            #+#    #+#             */
/*   Updated: 2018/07/15 09:51:22 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include <stdio.h>

int				ft_get_player_num(t_input *data)
{
	char		*line;
	char		**arr;

	if (get_next_line(0, &line) <= 0)
		return (-1);
	if (ft_count_words(line, ' ') != 5)
		return (-1);
	arr = ft_strsplit(line, ' ');
	if (ft_strcmp(arr[0], "$$$") != 0)
		return (-1);
	if (ft_strcmp(arr[1], "exec") != 0)
		return (-1);
	if (ft_strcmp(arr[2], "p1") != 0)
		if (ft_strcmp(arr[2], "p2") != 0)
			return (-1);
	data->player_num = ft_atoi(&arr[2][1]);
	ft_memdel((void **)(&line));
	ft_del_matrix((void **)arr, 5);
	return (0);
}

int		main(void)
{
	static t_input	data;
	int				ans;

	ans = ft_get_player_num(&data);
	printf("ans returned %d\nplayer_num is %d\n", ans, data.player_num);
	return (0);
}
