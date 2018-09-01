/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 09:04:16 by egenis            #+#    #+#             */
/*   Updated: 2018/09/01 09:04:28 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

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
		ft_del_matrix((void **)(arr), 3);
	if (room1_exist == 1 && room2_exist == 1)
		return (1);
	ft_del_matrix((void **)(arr), 3);
	return (0);
}

void		link_rooms(t_data *d, char *link)
{
	char		**arr;
	int			room1_index;
	int			room2_index;
	t_room		*tmp;

	arr = ft_strsplit(link, '-');
	room1_index = 0;
	room2_index = 0;
	tmp = d->room;
	while (tmp)
	{
		if (ft_strcmp(arr[0], tmp->room_name) == 0)
			room1_index = tmp->room_index;
		if (ft_strcmp(arr[1], tmp->room_name) == 0)
			room2_index = tmp->room_index;
		tmp = tmp->next;
	}
	(d->adj_mat)[room1_index][room2_index] = 1;
	(d->adj_mat)[room2_index][room1_index] = 1;
	ft_del_matrix((void **)(arr), 3);
}

/*
** if mode == 1, the first link (last node in input list) will be made,
** othewise the given link string will be used to link the rooms.
*/

void		make_link(t_data *d, char *link, int mode)
{
	t_input		*tmp;

	if (mode == 1)
	{
		tmp = d->input;
		while (tmp->next)
			tmp = tmp->next;
		link = tmp->line_ptr;
		if (does_rooms_exist(d, link) == 0)
			quit(d, 1);
		link_rooms(d, link);
	}
	if (does_rooms_exist(d, link) == 0)
		quit(d, 1);
	link_rooms(d, link);
}
