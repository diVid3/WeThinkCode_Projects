#include "../inc/lem_in.h"

void		stack_push(t_data *d, int value)
{
	++(d->stack_top);
	(d->stack)[d->stack_top] = value;
}

void		stack_pop(t_data *d)
{
	--(d->stack_top);
}

void		neg_int_row(int *arr, int size)
{
	int		cntr;

	cntr = -1;
	while (++cntr < size)
		arr[cntr] = -1;
}

void		print_stack(t_data *d)
{
	int		cntr;

	cntr = -1;
	while (++cntr < d->stack_size && (d->stack)[cntr] != -1)
	{
		ft_putnbr((d->stack)[cntr]);
		if (cntr < d->stack_size - 1)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

void		make_stack(t_data *d)
{
	int		room_count;

	room_count = count_rooms(d);
	d->stack_size = room_count;
	d->stack = malloc(sizeof(int) * (room_count * room_count));
	neg_int_row(d->stack, (room_count * room_count));
	d->stack_top = -1;
	d->stack_size = room_count * room_count;
}