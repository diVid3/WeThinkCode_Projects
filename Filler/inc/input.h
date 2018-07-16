/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:23:13 by egenis            #+#    #+#             */
/*   Updated: 2018/07/16 06:23:32 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

typedef struct	s_input
{
	_Bool		read_1st;
	int			player_num;
	int			map_rows;
	int			map_cols;
	char		**map;
	int			piece_rows;
	int			piece_cols;
	char		**piece;
}				t_input;

#endif
