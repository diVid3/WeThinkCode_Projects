/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_plyr_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:24:13 by egenis            #+#    #+#             */
/*   Updated: 2018/07/09 15:18:08 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include <fcntl.h>
#include <stdio.h>

int			ft_get_plyr_num(t_data *data)
{
	char		*line;
	char		*p_num_addr;

	if ((get_next_line(0, &line)) == -1)
		return (-1);
	if ((p_num_addr = ft_strstr(line, "p1")) == NULL)
		if ((p_num_addr = ft_strstr(line, "p2")) == NULL)
			return (-1);
	p_num_addr += 1;
	data->plyr_num = ft_atoi(p_num_addr);
	ft_memdel((void **)(&line));
	return (0);
}


int		main(void)
{
	static t_data	data;
	int		ans = ft_get_plyr_num(&data);
	printf("data->plyr_num is %d\n", data.plyr_num);
	return (ans);
}
