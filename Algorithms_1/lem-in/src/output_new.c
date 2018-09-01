/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 15:03:53 by egenis            #+#    #+#             */
/*   Updated: 2018/09/01 15:03:56 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		make_print_list(t_data *d)
{
	int		stk_cntr;

	stk_cntr = 0;
	while (++stk_cntr < d->stack_size && (d->stack)[stk_cntr] != -1)
		print_add_node_end(d->print, (d->stack)[stk_cntr]);
}
