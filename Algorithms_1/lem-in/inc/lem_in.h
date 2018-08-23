/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:52:21 by egenis            #+#    #+#             */
/*   Updated: 2018/08/20 14:00:23 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct		s_input
{
	char			*line_ptr;
	struct s_input	*next;
}					t_input;

typedef struct		s_data
{
	t_input			*input;
}					t_data;

void		input_add_node_end(t_input **head, char *line);
void		input_free_list(t_input *head);
void		input_print_list(t_input *input);
void		get_input(t_data *data);
void		quit(t_data *data, int error);
void		validate_input(t_data *d);
void		validate_ants(t_data *d);

#endif
