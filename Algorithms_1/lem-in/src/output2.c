#include "../inc/lem_in.h"

void		print_ants(t_data *d)
{
	t_print		*tmp;

	if (d->print == NULL)
		return ;
	tmp = d->print;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->ant_count > 0 && tmp->ant_count <= d->ants)
		{
			ft_putchar('L');
			ft_putnbr(tmp->ant_count);
			ft_putchar('-');
			print_room_name(d, tmp->index);
			ft_putchar(' ');
		}
		tmp = tmp->prev;
	}
	ft_putchar('\n');
}