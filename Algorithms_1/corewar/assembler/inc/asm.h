/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:08:23 by egenis            #+#    #+#             */
/*   Updated: 2018/09/11 07:09:28 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "./op.h"

typedef struct		s_input
{
	char			*line_ptr;
	int				line_nbr;
	struct s_input	*next;
}					t_input;

typedef struct		s_func
{
	char			*func;
	char			*args;
	char			*label;
	int				index;
	unsigned int	bytes_req;
	struct s_func	*next;
	struct s_func	*prev;
}					t_func;

/*
typedef struct		s_label
{
	char			*label;
	struct s_label	*next;
}					t_label;
*/

typedef struct		s_data
{
	char			*name;
	char			*comment;
	int				read_name;
	int				read_comment;
	t_input			*input;
	t_func			*func;
}					t_data;

extern t_op			g_op_tab[17];

void				quit(t_data *d, int err_msg);
void				iterate_w_space(char *str, int *cntr);
void				get_input(t_data *d, int ac, char **av);
void				save_input(t_data *d, int fd);
void				get_header(t_data *d);
void				validate_input(t_data *d);
void				fuse_label_func(t_data *d, char *lbl_line, char *func_line);
void				switch_reader(t_data *d, t_input **label_node);
void				build_func_list(t_data *d);
void				validate_labels(t_data *d);
void				func_add_node_end(t_func **h, char *f, char *a, char *l);
void				func_print_list(t_func *head);
void				func_free_list(t_func *head);
void				input_add_node_end(t_input **head, char *line);
void				input_free_list(t_input *head);
void				input_print_list(t_input *input);
void				macro_check(void);
void				has_dup_labels(t_data *d);
void				write_rev_ui(unsigned int x, int size, int fd);
void				write_rev_us(unsigned short x, int size, int fd);
void				do_calcs(t_data *d);
void				calc_byte_reqs(t_data *d);
void				write_data(t_data *d, char **av);
void				write_header(t_data *d, int fd);

int					strclen(char *str);
int					is_func(char *str);
int					has_ext(char *file);
int					is_label_chars(char c);
int					free_return(char *str_no_cmmnt, char **arr, int cntr);
int					is_label_func(char *str);
int					validate_field(int field_byte, char *arg);
int					is_arg_types_valid(int opcode, int fields_valid, char **ar);
int					is_args_valid(char *func, char *args);
int					is_strnum(char *arg, int *cntr, int is_int_start);
int					is_label_valid(char *arg);
int					is_digits(char *arg);
int					is_func_valid(char *func);
int					build_func_node(t_data *d, char *line, int has_lbl);
int					strjoin_open(char **av);
int					free_refs(char *str1, char *str2);
int					has_args_lbl(char *args);
int					find_label(t_data *d, char *args_ref);
int					has_val_lbl_refs(t_data *d);
int					is_name_comm_overlong(t_data *d);
int					open_w(char **av);
int					is_reg(char *arg);
int					is_ind(char *arg);
int					is_dir(char *arg);
int					is_name_cmd(char *str);
int					is_comment_cmd(char *str);
int					is_comment(char *str);
int					is_label(char *str);
int					is_func(char *str);
int					is_label_func(char *str);

char				*strcdup(char *str, char c);
char				*get_args_lbl(char *args);
char				*ft_strndup(const char *s1, size_t len);

char				**split(char *str);

#endif
