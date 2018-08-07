/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 06:29:21 by egenis            #+#    #+#             */
/*   Updated: 2018/08/07 06:46:30 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"
#include <stdio.h>

void				ft_print_stacks(t_stacks *stacks)
{
	int		cntr;

	printf("\tSTACK A:\n");
	cntr = stack->stk_a_t;
	while (stack->stk_a_t < stack->stk_size && cntr < stack->stk_size)
	{
		printf("\t\t%d\n", (stack->stk_a)[cntr]);
		++cntr;
	}
	printf("\tSTACK B:\n");
	cntr = stack->stk_b_t;
	while (stack->stk_b_t < stack->stk_size && cntr < stack->stk_size)
	{
		printf("\t\t%d\n", (stack->stk_b)[cntr]);
		++cntr;
	}
}
