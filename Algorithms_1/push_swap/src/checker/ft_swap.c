/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 06:24:54 by egenis            #+#    #+#             */
/*   Updated: 2018/08/07 06:44:20 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"

static void		ft_swap_m2(t_stacks *stacks)
{
	int tmp1;
	int tmp2;

	if ((stack->stk_size - 1) - stack->stk_a_t >= 1 &&
		(stack->stk_size - 1) - stack->stk_b_t >= 1)
	{
		tmp1 = (stack->stk_a)[stack->stk_a_t];
		(stack->stk_a)[stack->stk_a_t] = (stack->stk_a)[stack->stk_a_t + 1];
		(stack->stk_a)[stack->stk_a_t + 1] = tmp1;
		tmp2 = (stack->stk_b)[stack->stk_b_t];
		(stack->stk_b)[stack->stk_b_t] = (stack->stk_b)[stack->stk_b_t + 1];
		(stack->stk_b)[stack->stk_b_t + 1] = tmp2;
	}
}

void			ft_swap(t_stacks *stacks, int mode)
{
	int		tmp;

	if (stacks->stk_size == 0 || stacks->stk_size == 1)
		return ;
	if (mode == 0 && (stack->stk_size - 1) - stack->stk_a_t >= 1)
	{
		tmp = (stack->stk_a)[stack->stk_a_t];
		(stack->stk_a)[stack->stk_a_t] = (stack->stk_a)[stack->stk_a_t + 1];
		(stack->stk_a)[stack->stk_a_t + 1] = tmp;
	}
	if (mode == 1 && (stack->stk_size - 1) - stack->stk_b_t >= 1)
	{
		tmp = (stack->stk_b)[stack->stk_b_t];
		(stack->stk_b)[stack->stk_b_t] = (stack->stk_b)[stack->stk_b_t + 1];
		(stack->stk_b)[stack->stk_b_t + 1] = tmp;
	}
	if (mode == 2)
		ft_swap_m2(stacks);
}
