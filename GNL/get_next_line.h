/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:17:40 by egenis            #+#    #+#             */
/*   Updated: 2018/06/19 18:22:17 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 32

typedef	struct	s_ac_mem;
{
	char		*arr_f;
	char		*tmp;
	char		*free;
	_Bool		nl_found;
	ssize_t		read_b;
	size_t		spd;
	size_t		cntr;
}				t_ac_mem;

int				get_next_line(const int fd, char **line);

#endif
