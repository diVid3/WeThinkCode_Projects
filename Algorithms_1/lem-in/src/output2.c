/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 06:24:16 by egenis            #+#    #+#             */
/*   Updated: 2018/09/03 06:24:18 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (tmp->prev && tmp->ant_count < d->ants)
				ft_putchar(' ');
		}
		tmp = tmp->prev;
	}
	ft_putchar('\n');
}

void		print_room_name_tab(t_data *d)
{
	t_room		*tmp;

	tmp = d->room;
	while (tmp)
	{
		ft_putnbr(tmp->room_index);
		ft_putstr(" - ");
		ft_putstr(tmp->room_name);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
