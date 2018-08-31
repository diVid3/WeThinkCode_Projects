#include "../inc/lem_in.h"

void		print_room_name(t_data *d, int index)
{
	t_room		*tmp;

	tmp = d->room;
	while (tmp)
	{
		if (index == tmp->room_index)
			break ;
		tmp = tmp->next;
	}
	ft_putstr(tmp->room_name);
}

void		send_ants(t_data *d)
{
	int		ant_cntr;
	int		stk_cntr;

	ant_cntr = 0;
	while (++ant_cntr <= d->ants)
	{
		stk_cntr = 0;
		while (++stk_cntr < d->stack_size && (d->stack)[stk_cntr] != -1)
		{
			ft_putchar('L');
			ft_putnbr(ant_cntr);
			ft_putchar('-');
			print_room_name(d, stk_cntr);
			ft_putchar('\n');
		}
	}
}