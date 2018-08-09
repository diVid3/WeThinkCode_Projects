/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 06:24:54 by egenis            #+#    #+#             */
/*   Updated: 2018/08/07 12:20:28 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap/push_swap.h"

void			ft_swap(t_stacks *stacks, int mode)
{
	int		tmp;

	if (mode == 0 && (stacks->stk_size - 1) - stacks->stk_a_t >= 1)
	{
		tmp = (stacks->stk_a)[stacks->stk_a_t];
		(stacks->stk_a)[stacks->stk_a_t] = (stacks->stk_a)[stacks->stk_a_t + 1];
		(stacks->stk_a)[stacks->stk_a_t + 1] = tmp;
	}
	if (mode == 1 && (stacks->stk_size - 1) - stacks->stk_b_t >= 1)
	{
		tmp = (stacks->stk_b)[stacks->stk_b_t];
		(stacks->stk_b)[stacks->stk_b_t] = (stacks->stk_b)[stacks->stk_b_t + 1];
		(stacks->stk_b)[stacks->stk_b_t + 1] = tmp;
	}
	if (mode == 2)
		ft_swap(stacks, 0);
	if (mode == 2)
		ft_swap(stacks, 1);
}
