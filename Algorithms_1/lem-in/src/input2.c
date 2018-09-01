/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 08:57:27 by egenis            #+#    #+#             */
/*   Updated: 2018/09/01 08:57:29 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		get_start(t_data *d)
{
	int		read_b;
	char	*line;

	read_b = 1;
	while (read_b)
	{
		read_b = get_next_line(0, &line);
		input_add_node_end(&(d->input), line);
		if (is_comment(line))
			continue ;
		else if (is_rand_command(line))
			continue ;
		else if (is_room(line))
		{
			insert_room(d, line, 1, 0);
			d->read_start = 1;
			return ;
		}
		else
			quit(d, 1);
	}
}

void		get_end(t_data *d)
{
	int		read_b;
	char	*line;

	read_b = 1;
	while (read_b)
	{
		read_b = get_next_line(0, &line);
		input_add_node_end(&(d->input), line);
		if (is_comment(line))
			continue ;
		else if (is_rand_command(line))
			continue ;
		else if (is_room(line))
		{
			insert_room(d, line, 0, 1);
			d->read_end = 1;
			return ;
		}
		else
			quit(d, 1);
	}
}
