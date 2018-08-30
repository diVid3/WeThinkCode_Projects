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

typedef struct		s_bcktrk
{
	int				start;
	int				end;
	int				room_count;
	int				found_end;
}					t_bcktrk;

typedef struct		s_data
{
	int				ants;
	int				read_ants;
	int				read_start;
	int				read_end;
	int				read_rooms;
	int				read_links;
	int				stack_top;
	int				stack_size;
	int				*stack;
	int				**adj_mat;
	t_input			*input;
	t_room			*room;
}					t_data;

void				input_add_node_end(t_input **head, char *line);
void				input_free_list(t_input *head);
void				input_print_list(t_input *input);
void				room_add_node_end(t_room **head, char *str, int s, int e);
void				room_free_list(t_room *head);
void				room_print_list(t_room *room);
void				quit(t_data *data, int error);
void				insert_room(t_data *d, char *line, int start, int end);
void				get_ants(t_data *d);
void				get_start(t_data *d);
void				get_end(t_data *d);
void				get_rooms(t_data *d);
void				get_links(t_data *d);
void				get_input(t_data *data);
void				zero_int_row(int *arr, int size);
void				make_adj_mat(t_data *d);
void				print_adj_mat(t_data *d);
void				free_adj_mat(t_data *d);
void				make_link(t_data *d, char *link, int mode);
void				link_rooms(t_data *d, char *link);

int					is_room_dup(t_data *d, char *str);
int					is_comment(char *str);
int					is_rand_command(char *str);
int					is_start(char *str);
int					is_end(char *str);
int					is_link(char *str);
int					is_room(char *str);
int					is_ants(char *str);
int					count_pluses(char *str);
int					count_hashes(char *str);
int					count_dashes(char *str);
int					count_dashes_c(char *str, char c);
int					count_spaces(char *str);
int					count_whitespaces(char *str);
int					count_rooms(t_data *d);
int					does_rooms_exist(t_data *d, char *link);

#endif
