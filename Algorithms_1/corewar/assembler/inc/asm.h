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
	unsigned int	bytes_req;
	struct s_func	*next;
	struct s_func	*prev;
}					t_func;

typedef struct		s_data
{
	char			*name;
	char			*comment;
	char			*output_name;
	int				read_name;
	int				read_comment;
	t_input			*input;
	t_func			*func;
}					t_data;

extern t_op			g_op_tab[17];

void				quit(t_data *d, int err_msg, int line_nbr);
void				print_err_exit(int err_msg, int line_nbr);
void				print_err_exit_more(int err_msg);
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
void				macro_check(t_data *d);
void				has_dup_labels(t_data *d);
void				write_rev_ui(unsigned int x, int size, int fd);
void				write_rev_us(unsigned short x, int size, int fd);
void				do_calcs(t_data *d);
void				calc_byte_reqs(t_data *d);
void				write_data(t_data *d, char **av);
void				write_header(t_data *d, int fd);
void				write_op(int opcode, int fd);
void				write_funcs(t_data *d, int fd);
void				write_num(int nbr, int type_size, int fd);
void				write_enc(t_func *tmp, int fd);
void				write_reg(char *reg, int fd);
void				write_args(t_data *d, t_func *tmp, int fd);
void				write_label_dir(t_func *tmp, char *arg, int ty_sze, int fd);
void				write_dir(t_func *tmp, int fd, char *arg);
void				write_label_ind(t_func *tmp, char *arg, int fd);
void				write_ind(t_func *tmp, int fd, char *arg);

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
int					open_w(t_data *d, char **av);
int					calc_jump_up(t_func *tmp, char *ref_label);
int					calc_jump_down(t_func *tmp, char *ref_label);
int					is_reg(char *arg);
int					is_ind(char *arg);
int					is_dir(char *arg);
int					is_name_cmd(char *str);
int					is_comment_cmd(char *str);
int					is_comment(char *str);
int					is_label(char *str);
int					is_func(char *str);
int					is_label_func(char *str);

char				*get_args_lbl(char *args);

char				**split(char *str);

unsigned char		ret_enc_bits(char *field, int field_nr);

#endif
