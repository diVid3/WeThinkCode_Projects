/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:17:40 by egenis            #+#    #+#             */
/*   Updated: 2018/06/21 16:36:27 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 32

typedef	struct	s_ac_mem;
{
	char		*arr_l;
	char		*tmp;
	char		*free;
	_Bool		nl_found;
	ssize_t		read_b;
	size_t		spd;
	size_t		cntr;
}				t_ac_mem;

typedef	struct	s_c_mem
{
	char		*arr_l;
	char		*last_nl;
	char		*store;
	char		*prev_line;
	size_t		pos;
	size_t		line_len;
	_Bool		read_1ce;
}				t_c_mem;

int				get_next_line(const int fd, char **line);

#endif
