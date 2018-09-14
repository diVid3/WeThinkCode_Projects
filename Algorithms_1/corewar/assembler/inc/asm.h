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
	s_input			*next;
}					t_input;

typedef struct		s_func
{
	char			*op;
	char			*args;
	int				index;
	t_label			*label;
	t_op			*next;
	t_op			*prev;
}					t_func;

// Not needed as empty labels can be regarded as errors.

/*
typedef struct		s_label
{
	char			*label;
	s_label			*next;
}					t_label;
*/

typedef struct		s_data
{
	char			*name;
	char			*comment;
	t_input			*input;
	t_op			*func;
}					t_data

extern t_op			g_op_tab[17];

#endif
