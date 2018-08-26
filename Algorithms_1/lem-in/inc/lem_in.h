/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:52:21 by egenis            #+#    #+#             */
/*   Updated: 2018/08/24 06:43:20 by egenis           ###   ########.fr       */
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

typedef struct		s_room
{
	char			*room_name;
	int				room_index;
	int				room_start;
	int				room_end;
	struct s_room	*next;
}					t_room;

typedef struct		s_data
{
	int				ants;
	int				read_ants;
	int				read_start;
	int				read_end;
	int				read_rooms;
	int				read_links;
	t_input			*input;
	t_room			*room;
}					t_data;

void				input_add_node_end(t_input **head, char *line);
void				input_free_list(t_input *head);
void				input_print_list(t_input *input);
void				quit(t_data *data, int error);
void				get_ants(t_data *d, char *line);
void				get_room(t_data *d, char *line);
void				get_input(t_data *data);

int					is_comment(char *str);
int					is_command(char *str);
int					is_start(char *str);
int					is_end(char *str);
int					is_link(char *str);
int					is_room(char *str);
int					is_ants(char *str);
int					count_pluses(char *str);
int					count_hashes(char *str);
int					count_dashes(char *str);
int					count_spaces(char *str);
int					count_whitespaces(char *str);

#endif
