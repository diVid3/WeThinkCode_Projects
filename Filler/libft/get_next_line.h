/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 06:28:04 by egenis            #+#    #+#             */
/*   Updated: 2018/07/06 07:38:43 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 32

typedef	struct	s_mem
{
	char		*arr;
	char		*prev_arr;
	int			prev_fd;
	ssize_t		read_b;
	_Bool		swtch;
}				t_mem;

int				get_next_line(const int fd, char **line);

#endif
