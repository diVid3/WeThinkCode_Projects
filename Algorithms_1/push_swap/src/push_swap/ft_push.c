/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:03:17 by egenis            #+#    #+#             */
/*   Updated: 2018/08/07 12:21:11 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap/push_swap.h"

void				ft_push(t_stacks *stacks, int mode)
{
	if (mode == 0 && (stacks->stk_size - 1) - stacks->stk_b_t >= 0)
	{
		--stacks->stk_a_t;
		(stacks->stk_a)[stacks->stk_a_t] = (stacks->stk_b)[stacks->stk_b_t];
		++stacks->stk_b_t;
	}
	if (mode == 1 && (stacks->stk_size - 1) - stacks->stk_a_t >= 0)
	{
		--stacks->stk_b_t;
		(stacks->stk_b)[stacks->stk_b_t] = (stacks->stk_a)[stacks->stk_a_t];
		++stacks->stk_a_t;
	}
}
