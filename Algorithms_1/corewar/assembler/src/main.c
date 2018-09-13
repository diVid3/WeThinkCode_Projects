/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:31:34 by egenis            #+#    #+#             */
/*   Updated: 2018/09/11 07:31:36 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	quit(t_data *d, int err_msg)
{
	input_free_list(d->input);
	exit(0);
}

/*
** Don't forget to loop ac.
*/

int		main(int ac, char **av)
{
	static t_data		d;

	get_input(&d, ac, av);
	make_champ();
	quit(d, 0);
}
