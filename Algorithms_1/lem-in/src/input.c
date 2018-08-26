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

// Order needs major updates.

void		get_ants(t_data *d, char *line)
{

	//d->ants = ft_atoi(line);
	//d->read_ants = 1;
}

void		get_room(t_data *d, char *line)
{
	char			**arr;

	if (d->read_ants == 0)
		d->read_ants = 1;
	arr = ft_strsplit(line, ' ');
	room_add_node_end(&(d->room), arr[0], 0, 0);
	ft_del_matrix((void **)(arr), 3);
}


void		get_input(t_data *d)
{
	int			read_b;
	char		*line;

	get_ants(d);
	read_b = 1;
	while (read_b)
	{
		read_b = get_next_line(0, &line);
		//if (d->read_ants == 0 && is_ants(line))
		//	get_ants(d, line);
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
