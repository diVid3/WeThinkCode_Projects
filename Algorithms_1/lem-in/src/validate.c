#include "../inc/lem_in.h"

void		validate_ants(t_data *d)
{
	long	ants;
	char	*str;

	str = d->input->line_ptr;
	ants = ft_atol(str);
	if (ants <= 0 || ants > 2147483647)
		quit(d, 1);
}

void		validate_rooms(t_data *d)
{
	t_input *room;

	room = d->input->next;
}

void		validate_input(t_data *d)
{
	validate_ants(d);
	//validate_rooms(d);
}