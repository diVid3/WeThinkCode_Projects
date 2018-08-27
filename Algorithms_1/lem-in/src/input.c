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

void		get_ants(t_data *d)
{
	int		read_b;
	char	*line;

	read_b = 1;
	while (read_b)
	{
		read_b = get_next_line(0, &line);
		input_add_node_end(&(d->input), line);
		if (is_comment(line))
			continue ;
		else if (is_rand_command(line))
			continue ;
		else if (is_ants(line))
		{
			d->ants = ft_atoi(line);
			d->read_ants = 1;
			return ;
		}
		else
			quit(d, 1);
	}
}

void		insert_room(t_data *d, char *line, int start, int end)
{
	char		**arr;

	arr = ft_strsplit(line, ' ');
	if (is_room_dup(d, arr[0]))
	{
		ft_del_matrix((void **)(arr), 3);
		quit(d, 1);
	}
	room_add_node_end(&(d->room), arr[0], start, end);
	ft_del_matrix((void **)(arr), 3);
}

void		get_rooms(t_data *d)
{
	int			read_b;
	char		*line;

	read_b = 1;
	while (read_b && d->read_rooms == 0)
	{
		// Might need or not need to remove check for empty line.
		if ((read_b = get_next_line(0, &line)) == 0)
			break ;
		input_add_node_end(&(d->input), line);
		if (is_comment(line))
			continue ;
		else if (is_rand_command(line))
			continue ;
		else if (is_start(line) && d->read_start == 0)
			get_start(d);
		else if (is_end(line) && d->read_end == 0)
			get_end(d);
		else if (is_room(line))
			insert_room(d, line, 0, 0);
		else if (is_link(line))
			d->read_rooms = 1;
		else
			quit(d, 1);
	}
}

// get_links() should generate the adjacency matrix before the linking
// happens. Remeber to get the 1st link in input list, it's the last node.

void		get_links(t_data *d)
{
	(void)d;
	return ;
}

void		get_input(t_data *d)
{
	get_ants(d);
	get_rooms(d);
	//input_print_list(d->input);
	//room_print_list(data.room);
	get_links(d);
}
