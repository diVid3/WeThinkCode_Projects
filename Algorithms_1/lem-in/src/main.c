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
	if (error)
		ft_putstr_fd("ERROR\n", 2);
	input_free_list(d->input);
	room_free_list(d->room);
	free_adj_mat(d);
	exit(1);
}

int			main(void)
{
	static t_data	d;

	get_input(&d);
	//find_path(&d);
	//send_ants(&d);
	quit(&d, 0);
	return (0);
}
