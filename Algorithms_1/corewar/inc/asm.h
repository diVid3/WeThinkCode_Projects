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

void				iterate_w_space(char *str, int *cntr);
void				get_input(t_data *d, int ac, char **av);

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

char				**split(char *str);

#endif
