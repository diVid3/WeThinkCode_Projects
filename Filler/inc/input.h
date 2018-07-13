/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:12:15 by egenis            #+#    #+#             */
/*   Updated: 2018/07/09 13:29:49 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct	s_data
{
	int			plyr_num;
	int			map_rws;
	int			map_cls;
	char		**map;
	int			pce_rws;
	int			pce_cls;
	char		**pce;
	_Bool		map_skp_2line;
	_Bool		pce_skp_1line;
}				t_data;

#endif
