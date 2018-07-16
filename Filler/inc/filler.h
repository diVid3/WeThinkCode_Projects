/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:32:26 by egenis            #+#    #+#             */
/*   Updated: 2018/07/16 14:32:00 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../lib/libft/libft.h"
# include "input.h"
# include "move.h"

int				ft_get_player_num(t_input *data);
int				ft_get_map_size(t_input *data);
int				ft_get_map(t_input *data);
int				ft_get_piece_size(t_input *data);
int				ft_get_piece(t_input *data);
int				ft_get_input(t_input *data);

void			ft_place_piece(t_input *data);

#endif
