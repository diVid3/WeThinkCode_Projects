/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 09:03:24 by egenis            #+#    #+#             */
/*   Updated: 2018/09/01 09:03:47 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		print_room_name(t_data *d, int index)
{
	t_room		*tmp;

	tmp = d->room;
	while (tmp)
	{
		if (tmp->room_index == index)
		{
			ft_putstr(tmp->room_name);
			break ;
		}
		tmp = tmp->next;
	}
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
			print_room_name(d, (d->stack)[stk_cntr]);
			ft_putchar('\n');
		}
	}
}
