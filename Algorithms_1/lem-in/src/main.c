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

void		quit(t_data *data, int error)
{
	if (error)
		ft_putstr_fd("ERROR\n", 2);
	input_free_list(data->input);
	room_free_list(data->room);
	exit(1);
}

int			main(void)
{
	static t_data	data;

	get_input(&data);
	//input_print_list(data.input);
	//room_print_list(data.room);
	return (0);
}
