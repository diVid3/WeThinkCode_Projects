/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:23:13 by egenis            #+#    #+#             */
/*   Updated: 2018/07/17 07:20:47 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

typedef struct	s_input
{
	_Bool		read_1st;
	int			player_num;
	int			mp_rws;
	int			mp_cls;
	char		**mp;
	int			p_rws;
	int			p_cls;
	char		**p;
	int			overlaps;
}				t_input;

#endif
