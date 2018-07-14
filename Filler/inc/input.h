/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:12:15 by egenis            #+#    #+#             */
/*   Updated: 2018/07/13 14:16:19 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct	s_input
{
	int			player_num;
	int			map_rows;
	int			map_cols;
	char		**map;
	int			piece_rows;
	int			piece_cols;
	char		**piece;
}				t_input;

#endif
