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
	char			*op;
	char			*args;
	char			*label;
	int				index;
	struct s_func	*next;
	struct s_func	*prev;
}					t_func;

typedef struct		s_data
{
	char			*name;
	char			*comment;
	t_input			*input;
	t_func			*func;
}					t_data;

extern t_op			g_op_tab[17];

char				*strcdup(char *str, char c);

char				**split(char *str);

int					strclen(char *str);

#endif
