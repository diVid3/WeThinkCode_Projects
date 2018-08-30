#include "../inc/lem_in.h"

int			count_rooms(t_data *d)
{
	int			room_count;
	t_room		*tmp;

	room_count = 0;
	tmp = d->room;
	while (tmp)
	{
		++room_count;
		tmp = tmp->next;
	}
	return (room_count);
}

void		free_adj_mat(t_data *d)
{
	int		cntr;
	int		room_count;

	room_count = count_rooms(d);
	cntr = -1;
	if (d->adj_mat)
	{
		while (++cntr < room_count)
			ft_memdel((void **)(&((d->adj_mat)[cntr])));
		ft_memdel((void **)(&(d->adj_mat)));
	}
}

void		print_adj_mat(t_data *d)
{
	int		**adj_mat;
	int		row;
	int		col;
	int		room_count;

	adj_mat = d->adj_mat;
	room_count = count_rooms(d);
	row = -1;
	ft_putchar('\n');
	ft_putchar('\n');
	while (++row < room_count)
	{
		col = -1;
		while (++col < room_count)
		{
			ft_putnbr(adj_mat[row][col]);
			if (col < room_count - 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

void		zero_int_row(int *arr, int size)
{
	int		cntr;

	cntr = -1;
	while (++cntr < size)
		arr[cntr] = 0;
}

void		make_adj_mat(t_data *d)
{
	int		room_count;
	int		cntr;

	room_count = count_rooms(d);
	d->adj_mat = malloc(sizeof(int *) * room_count);
	cntr = -1;
	while (++cntr < room_count)
		(d->adj_mat)[cntr] = malloc(sizeof(int) * room_count);
	cntr = -1;
	while (++cntr < room_count)
		zero_int_row((d->adj_mat)[cntr], room_count);
}
