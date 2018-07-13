/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:55:00 by egenis            #+#    #+#             */
/*   Updated: 2018/07/13 17:07:02 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include <stdio.h>

static	void	ft_del_matrix_nul(void **arr)
{
	size_t		cntr;

	if (!arr)
		return ;
	cntr = 0;
	while (arr[cntr])
	{
		free(arr[cntr]);
		arr[cntr] = NULL;
		++cntr;
	}
	free(arr);
	arr = NULL;
	return ;
}

int				ft_verify_player_num(char *line)
{
}

int				ft_get_player_num(t_input *data)
{
	int			ans;
	char		*line;
	char		**arr;

	if ((ans = get_next_line(0, &line)) == 0)
		ft_memdel((void **)(&line));
	if (ans <= 0)
		return (-1);
	arr = ft_strsplit(line, ' ');
}

int				ft_get_input(void)
{
	static t_input		data;
}

int		main(void)
{
	return (0);
}
