#include "../inc/lem_in.h"
#include <stdio.h>

int			find_start_room(t_data *d)
{
	int			start_room;
	t_room		*tmp;

	start_room = -1;
	tmp = d->room;
	while (tmp)
	{
		if (tmp->room_start == 1)
		{
			start_room = tmp->room_index;
			break ;
		}
		tmp = tmp->next;
	}
	return (start_room);
}

int			find_end_room(t_data *d)
{
	int			end_room;
	t_room		*tmp;

	end_room = -1;
	tmp = d->room;
	while (tmp)
	{
		if (tmp->room_end == 1)
		{
			end_room = tmp->room_index;
			break ;
		}
		tmp = tmp->next;
	}
	return (end_room);
}

/*
** The actual recursive backtracking algorithm.
*/

void		find_path(t_data *d, t_bcktrk *i, int row, int col)
{
	stack_push(d, row);
	if (row == i->end)
	{
		i->found_end = 1;
		return ;
	}
	while (col < i->room_count)
	{
		if ((d->adj_mat)[row][col] == 1)
		{
			(d->adj_mat)[row][col] = 0;
			find_path(d, i, col, 0);
			if (i->found_end == 1)
				return ;
		}
		++col;
	}
	stack_pop(d);
}

void		solve_graph(t_data *d)
{
	t_bcktrk	info;

	make_stack(d);
	info.start = find_start_room(d);
	info.end = find_end_room(d);
	info.room_count = count_rooms(d);
	info.found_end = 0;
	find_path(d, &info, info.start, 0);
	if (d->stack_top <= -1)
		quit(d, 2);
}
