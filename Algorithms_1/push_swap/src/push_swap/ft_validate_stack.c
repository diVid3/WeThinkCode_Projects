/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:46:50 by egenis            #+#    #+#             */
/*   Updated: 2018/08/13 17:46:52 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap/push_swap.h"

int			ft_validate_stack(t_stacks *stacks)
{
	int		cntr;

	if (stacks->stk_size == 1 && stacks->stk_b_t == stacks->stk_size)
		return (1);
	if (stacks->stk_b_t == stacks->stk_size)
	{
		cntr = -1;
		while (++cntr + 1 < stacks->stk_size)
			if ((stacks->stk_a)[cntr] > (stacks->stk_a)[cntr + 1])
				return (0);
	}
	else
		return (0);
	return (1);
}
