/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:53:21 by egenis            #+#    #+#             */
/*   Updated: 2018/07/09 17:31:19 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include <fcntl.h>
#include <stdio.h>

int			ft_get_map(t_data *data)
{
	char	*line;

	if ((get_next_line(0, &line)) == -1)
		return (-1);
	ft_memdel((void **)(&line));
	return (0);
}

int		main(void)
{
	return (0);
}
