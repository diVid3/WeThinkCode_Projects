/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:51:18 by egenis            #+#    #+#             */
/*   Updated: 2018/08/20 17:32:53 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		quit(t_data *d, int error)
{
	if (error == 1)
		ft_putstr_fd("ERROR - ANTS - INCORRECT\n", 2);
	if (error == 2)
		ft_putstr_fd("ERROR - ROOM - DUPLICATE ROOM\n", 2);
	if (error == 3)
		ft_putstr_fd("ERROR - ROOM - EMPTY LINE\n", 2);
	if (error == 4)
		ft_putstr_fd("ERROR - ROOM - UNKNOWN LINE\n", 2);
	if (error == 5)
		ft_putstr_fd("ERROR - LINK - ROOM(S) DOESN'T EXIST\n", 2);
	if (error == 6)
		ft_putstr_fd("ERROR - LINK - UNKNOWN LINE\n", 2);
	if (error == 7)
		ft_putstr_fd("ERROR - NO PATH\n", 2);
	input_free_list(d->input);
	free_adj_mat(d);
	ft_memdel((void **)(&(d->stack)));
	room_free_list(d->room);
	if (error)
		exit(1);
	exit(0);
}

int			main(void)
{
	static t_data	d;

	get_input(&d);
	solve_graph(&d);
	input_print_list(d.input);
	send_ants(&d);
	quit(&d, 0);
}
