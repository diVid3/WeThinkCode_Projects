#include "../inc/lem_in.h"

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
int			stack_contain_end(t_data *d, t_bcktrk *inf)
{
	int		has_end;
	int		cntr;
	int		*tmp;

	tmp = d->stack;
	cntr = -1;
	while (++cntr < d->stack_size - 1)
		if 
}
*/

/*
** The actual backtracking algorithm.
*/

void		find_path(t_data *d, t_bcktrk *i)
{
	while (i->col < i->room_count - 1)
}

void		solve_graph(t_data *d)
{
	t_bcktrk	info;

	make_stack(d);
	info.row = find_start_room(d);
	info.end = find_end_room(d);
	info.col = 0;
	info.room_count = count_rooms(d);
	find_path(d, &info);
}
