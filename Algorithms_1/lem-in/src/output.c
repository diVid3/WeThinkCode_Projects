/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 15:03:53 by egenis            #+#    #+#             */
/*   Updated: 2018/09/03 06:23:17 by egenis           ###   ########.fr       */
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

void		make_print_list(t_data *d)
{
	int		stk_cntr;

	stk_cntr = 0;
	while (++stk_cntr < d->stack_size && (d->stack)[stk_cntr] != -1)
		print_add_node_end(&(d->print), (d->stack)[stk_cntr]);
}

void		increase_ant_count(t_data *d)
{
	t_print		*tmp;

	tmp = d->print;
	while (tmp && tmp->ant_count > 0)
	{
		(tmp->ant_count)++;
		tmp = tmp->next;
	}
	if (tmp)
		(tmp->ant_count)++;
}

int			is_all_above_ant_count(t_data *d)
{
	t_print		*tmp;

	tmp = d->print;
	while (tmp)
	{
		if (tmp->ant_count <= d->ants)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		send_ants(t_data *d)
{
	make_print_list(d);
	while (is_all_above_ant_count(d) == 0)
	{
		increase_ant_count(d);
		print_ants(d);
	}
}
