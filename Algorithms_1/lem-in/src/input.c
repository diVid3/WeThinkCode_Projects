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
//#include <stdio.h>

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
		if ((read_b = get_next_line(0, &line)) == 0)
			quit(d, 1);
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

// --------------------------------------------------------------------------

int			does_rooms_exist(t_data *d, char *link)
{
	char		**arr;
	int			room1_exist;
	int			room2_exist;
	t_room		*tmp;

	arr = ft_strsplit(link, '-');
	room1_exist = 0;
	room2_exist = 0;
	tmp = d->room;
	while (tmp)
	{
		if (ft_strcmp(arr[0], tmp->room_name) == 0)
			room1_exist = 1;
		if (ft_strcmp(arr[1], tmp->room_name) == 0)
			room2_exist = 1;
		tmp = tmp->next;
	}
	if (room1_exist == 1 && room2_exist == 1)
		ft_del_matrix((void **)(arr), 2);
	if (room1_exist == 1 && room2_exist == 1)
		return (1);
	ft_del_matrix((void **)(arr), 2);
	return (0);
}

void		link_rooms(t_data *d, char *link)
{
	char		**arr;
	int			room1_index;
	int			room2_index;
	t_room		*tmp;

	arr = ft_strsplit(link, '-');
	tmp = d->room;
	while (tmp)
	{

		tmp = tmp->next;
	}
}

void		make_first_link(t_data *d)
{
	t_input		*tmp;
	char		*link;

	tmp = d->input;
	while (tmp->next)
		tmp = tmp->next;
	link = tmp->line_ptr;
	if (does_rooms_exist(d, link) == 0)
		quit(d, 1);

}

// get_links() should generate the adjacency matrix before the linking
// happens. Remeber to get the 1st link in input list, it's the last node.

void		get_links(t_data *d)
{
	int		read_b;
	char	*line;

	make_adj_mat(d);
	make_first_link(d); // <------------------------------ Add this function.
	read_b = 1;
	while (read_b)
	{
		if ((read_b = get_next_line(0, &line)) == 0)
			d->read_links = 1;
		if (read_b == 0)
			break ;
		input_add_node_end(&(d->input), line);
		if (is_comment(line))
			continue ;
		else if (is_rand_command(line))
			continue ;
		else if (is_link(line))
			continue ;
			//make_link(d, line); // <----------------------- Uncomment this.
		else
			quit(d, 1);
	}
	//ft_putchar('\n');
	//print_adj_mat(d);
	//ft_putchar('\n');
}

// --------------------------------------------------------------------------

void		get_input(t_data *d)
{
	get_ants(d);
	get_rooms(d);
	//input_print_list(d->input);
	//room_print_list(data.room);
	get_links(d);
}
