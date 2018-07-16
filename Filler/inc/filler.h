/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:32:26 by egenis            #+#    #+#             */
/*   Updated: 2018/07/16 07:00:46 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "input.h"
# include "../lib/libft/libft.h"

int				ft_get_player_num(t_input *data);
int				ft_get_map_size(t_input *data);
int				ft_get_map(t_input *data);
int				ft_get_piece_size(t_input *data);
int				ft_get_piece(t_input *data);

#endif
