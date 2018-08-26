/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 06:42:01 by egenis            #+#    #+#             */
/*   Updated: 2018/08/24 07:39:36 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		get_input(t_data *d)
{
	int			read_b;
	char		*line;

	read_b = 1;
	while (read_b)
	{
		read_b = get_next_line(0, &line);
		if (d->read_ants == 0 && is_ants(line))
			get_ants(d, line);
		else if (d->read_start == 0 && is_start(line))
			get_start(d, line);
		else if (d->read_end == 0 && is_end(line))
			get_end(d, line);
		else if (d->read_rooms == 0 && is_room(line))
			get_room(d, line);
		else if (d->read_links == 0 && is_link(line))
			get_link(d, line);
		else if (is_comment(line))
			continue ;
		else if (is_command(line))
			continue ;
		else
			quit(d, 1);
		input_add_node_end(&(d->input), line);
	}
}
