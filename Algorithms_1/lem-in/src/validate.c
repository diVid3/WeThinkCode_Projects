/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 06:41:48 by egenis            #+#    #+#             */
/*   Updated: 2018/08/24 06:55:58 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

char		*validate_ants(t_data *d)
{
	t_input		*room;
	char		*str;
	_Bool		swtch;

	room = d->input;
	str = d->input->line_ptr;
	swtch = 0;
}

/*
void		validate_rooms(t_data *d)
{
	t_input *room;

	room = d->input->next;
}
*/

void		validate_input(t_data *d)
{
	char	*last_str;

	last_str = validate_ants(d);
	validate_rooms(d);
}
