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

typedef struct		s_op
{
	int				opcode;
	char			*args;
	t_label			*label;
}					t_op;

typedef struct		s_label
{
	char			*label;
	s_label			*next;
}					t_label;

typedef struct		s_data
{
	t_op			op;
	t_label			label;
}					t_data

extern t_op		g_op_tab[17];

#endif
