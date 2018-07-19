/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:32:26 by egenis            #+#    #+#             */
/*   Updated: 2018/07/17 13:07:03 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../lib/libft/libft.h"
# include "input.h"
# include "move.h"
# include "midpos.h"

int			ft_get_player_num(t_input *data);
int			ft_get_map_size(t_input *data);
int			ft_get_map(t_input *data);
int			ft_get_piece_size(t_input *data);
int			ft_get_piece(t_input *data);
int			ft_get_input(t_input *data);
int			ft_players_exist(t_input *data);

void		ft_add_node_back(t_move **head, int map_row, int map_col);
void		ft_free_list(t_move *head);
void		ft_place_piece(t_input *data);
void		ft_rate_moves(t_input *data, t_move *head);

_Bool		ft_can_place_p1(t_input *d, int m_rw, int m_cl);
_Bool		ft_can_place_p2(t_input *d, int m_rw, int m_cl);

t_move		*ft_make_move_list(t_input *data);

t_midpos	ft_optmze(t_input *d, t_move *n);

#endif
