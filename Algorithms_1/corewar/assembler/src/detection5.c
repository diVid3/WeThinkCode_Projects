/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:20:52 by egenis            #+#    #+#             */
/*   Updated: 2018/09/18 09:20:53 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

/*
** This function treats non-zero as true, and zero as false, it thus returns
** the valid operation's opcode upon validation.
*/

int		is_func_valid(char *func)
{
	int		cntr;

	cntr = 0;
	while (++cntr <= 16)
		if (ft_strcmp(func, g_op_tab[cntr].name) == 0)
			return (cntr);
	return (0);
}

int		is_name_comm_overlong(t_data *d)
{
	if (ft_strlen(d->name) > PROG_NAME_LENGTH ||
		ft_strlen(d->comment) > COMMENT_LENGTH)
		return (0);
	return (1);
}