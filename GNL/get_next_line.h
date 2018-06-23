/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:17:40 by egenis            #+#    #+#             */
/*   Updated: 2018/06/23 12:16:19 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 8

typedef	struct	s_ac_mem
{
	char		*arr_l;
	char		*tmp;
	char		*free;
	size_t		spd;
	size_t		cntr;
	_Bool		nl_found;
}				t_ac_mem;

typedef	struct	s_c_mem
{
	char		*arr_l;
	char		*store;
	char		*prev_l;
	char		*last_nl;
	size_t		pos;
	size_t		line_len;
	ssize_t		read_b;
	int			ans_pa;
	int			ans_sl;
	_Bool		read_1ce;
}				t_c_mem;

int				get_next_line(const int fd, char **line);

#endif
