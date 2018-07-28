/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:24:36 by egenis            #+#    #+#             */
/*   Updated: 2018/07/23 13:26:21 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"

int		ft_check_arg1(const char *str);
int		ft_check_min_max(const char *num_adrs);
int		ft_count_nums(const char *str);

long	ft_atol(const char *str);

char	*ft_nxt_num_adrs(char *s, _Bool reset);

#endif
