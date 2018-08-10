/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:24:36 by egenis            #+#    #+#             */
/*   Updated: 2018/08/10 16:44:36 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"

typedef struct	s_stacks
{
	int			*stk_a;
	int			stk_a_t;
	int			*stk_b;
	int			stk_b_t;
	int			stk_size;
}				t_stacks;

typedef struct	s_info_ln
{
	int			lwst_n;
	int			lwst_n_i;
	int			stk_mid_i;
}				t_info_ln;

void			ft_swap(t_stacks *stacks, int mode);
void			ft_push(t_stacks *stacks, int mode);
void			ft_rotate(t_stacks *stacks, int mode);
void			ft_r_rotate(t_stacks *stacks, int mode);
void			ft_sort_stack(t_stacks *stacks);

int				ft_check_arg(const char *str);
int				ft_check_min_max(const char *num_adrs);
int				ft_count_nums(const char *str);
int				ft_check_spaces(const char *str);
int				ft_validate_stack(t_stacks *stacks);

long			ft_atol(const char *str);

char			*ft_nxt_num_adrs(char *s, _Bool reset);
char			*ft_join_args(char **av);

t_stacks		*ft_build_stacks(int ac, char **av);

#endif
