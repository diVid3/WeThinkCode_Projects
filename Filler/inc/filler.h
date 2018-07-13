/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:32:26 by egenis            #+#    #+#             */
/*   Updated: 2018/07/13 10:32:29 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./data.h"
# include "../lib/libft/get_next_line.h"

void		ft_del_arr2d(char **arr, size_t row_count);
int			ft_get_plyr_num(t_data *data);
int			ft_get_map_size(t_data *data);
char		**ft_alloc_arr2d(size_t rows, size_t cols);

#endif
