/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:43:25 by egenis            #+#    #+#             */
/*   Updated: 2018/08/07 12:14:20 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap/push_swap.h"

void				ft_rotate(t_stacks *stacks, int mode)
{
	int		tmp;
	int		cntr;

	if (mode == 0 && (stacks->stk_size - 1) - stacks->stk_a_t >= 1)
	{
		tmp = (stacks->stk_a)[stacks->stk_a_t];
		cntr = stacks->stk_a_t - 1;
		while (++cntr + 1 <= stacks->stk_size - 1)
			(stacks->stk_a)[cntr] = (stacks->stk_a)[cntr + 1];
		(stacks->stk_a)[stacks->stk_size - 1] = tmp;
	}
	if (mode == 1 && (stacks->stk_size - 1) - stacks->stk_b_t >= 1)
	{
		tmp = (stacks->stk_b)[stacks->stk_b_t];
		cntr = stacks->stk_b_t - 1;
		while (++cntr + 1 <= stacks->stk_size - 1)
			(stacks->stk_b)[cntr] = (stacks->stk_b)[cntr + 1];
		(stacks->stk_b)[stacks->stk_size - 1] = tmp;
	}
	if (mode == 2)
		ft_rotate(stacks, 0);
	if (mode == 2)
		ft_rotate(stacks, 1);
}
