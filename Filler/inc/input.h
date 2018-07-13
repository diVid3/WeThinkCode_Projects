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
	int			plyr_num;
	int			map_rws;
	int			map_cls;
	char		**map;
	int			pce_rws;
	int			pce_cls;
	char		**pce;
}				t_input;

#endif
