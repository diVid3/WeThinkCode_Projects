/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:28:36 by egenis            #+#    #+#             */
/*   Updated: 2018/06/14 08:44:18 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_B_H
# define GET_NEXT_LINE_B_H

# include "libft.h"
# define BUFF_SIZE 32

typedef struct	s_mem
{
	char		**arr;
	_Bool		prep_mem;
	size_t		line_cntr;
}				t_mem;

typedef struct	s_accel
{
	size_t		spd;
	size_t		cntr;
}				t_accel;

int				get_next_line(const int fd, char **line);

#endif
