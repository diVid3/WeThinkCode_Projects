/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:12:15 by egenis            #+#    #+#             */
/*   Updated: 2018/07/09 12:32:54 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../lib/libft/get_next_line.h"
# include <stdio.h>

typedef unsigned int	t_uint;

typedef struct	s_data
{
	t_uint		player_num;
	t_uint		map_rows;
	t_uint		map_cols;
	char		**map;
	t_uint		piece_rows;
	t_uint		piece_cols;
	char		**piece;
}				t_data;

#endif
