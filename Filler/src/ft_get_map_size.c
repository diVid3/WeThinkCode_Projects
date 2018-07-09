/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:01:52 by egenis            #+#    #+#             */
/*   Updated: 2018/07/09 16:52:47 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include <fcntl.h>
#include <stdio.h>

static char	*ft_get_size_addr(char	*line, _Bool mode)
{
	if (!line)
		return (NULL);
	while (*line && !(*line >= '0' && *line <= '9'))
		++line;
	while (*line && (*line >= '0' && *line <= '9') && mode)
		++line;
	while (*line && !(*line >= '0' && *line <= '9') && mode)
		++line;
	if (*line == '\0')
		return (NULL);
	return (line);
}

int			ft_get_map_size(t_data *data)
{
	char	*line;
	char	*size_addr;

	if ((get_next_line(0, &line)) == -1)
		return (-1);
	if ((size_addr = ft_get_size_addr(line, 0)) == NULL)
		return (-1);
	data->map_rws = ft_atoi(size_addr);
	if ((size_addr = ft_get_size_addr(line, 1)) == NULL)
	{
		data->map_rws = 0;
		return (-1);
	}
	data->map_cls = ft_atoi(size_addr);
	ft_memdel((void **)(&line));
	return (0);
}

/*
int		main(void)
{
	static t_data	data;
	int				ans = ft_get_plyr_num(&data);
	int				ans2 = ft_get_map_size(&data);
	printf("data.map_rws = %d && data.map_cls = %d\n", data.map_rws, data.map_cls);
	(void)ans;
	(void)ans2;
	return (0);
}
*/
