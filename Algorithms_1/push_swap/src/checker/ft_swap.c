/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 06:24:54 by egenis            #+#    #+#             */
/*   Updated: 2018/08/07 07:00:35 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"

static void		ft_swap_m2(t_stacks *stacks)
{
	int tmp1;
	int tmp2;

	if ((stacks->stk_size - 1) - stacks->stk_a_t >= 1 &&
		(stacks->stk_size - 1) - stacks->stk_b_t >= 1)
	{
		tmp1 = (stacks->stk_a)[stacks->stk_a_t];
		(stacks->stk_a)[stacks->stk_a_t] = (stacks->stk_a)[stacks->stk_a_t + 1];
		(stacks->stk_a)[stacks->stk_a_t + 1] = tmp1;
		tmp2 = (stacks->stk_b)[stacks->stk_b_t];
		(stacks->stk_b)[stacks->stk_b_t] = (stacks->stk_b)[stacks->stk_b_t + 1];
		(stacks->stk_b)[stacks->stk_b_t + 1] = tmp2;
	}
}

void			ft_swap(t_stacks *stacks, int mode)
{
	int		tmp;

	if (stacks->stk_size == 0 || stacks->stk_size == 1)
		return ;
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
		ft_swap_m2(stacks);
	ft_print_stacks(stacks);
}
