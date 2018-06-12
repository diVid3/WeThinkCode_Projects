/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:28:36 by egenis            #+#    #+#             */
/*   Updated: 2018/06/12 16:20:53 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 1024

typedef struct	s_mem
{
	char		**arr;
	_Bool		split_mem;
	_Bool		build_mem;
	size_t		line_cntr;
}				t_mem;

#endif
