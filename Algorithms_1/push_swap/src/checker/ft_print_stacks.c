/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 06:29:21 by egenis            #+#    #+#             */
/*   Updated: 2018/08/07 08:51:51 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"
#include <stdio.h>

void				ft_print_stacks(t_stacks *stacks)
{
	int		cntr;

	printf("\n");
	printf("\t\tSTACK A:\n");
	cntr = stacks->stk_a_t;
	while (stacks->stk_a_t < stacks->stk_size && cntr < stacks->stk_size)
	{
		printf("\t\t%d\n", (stacks->stk_a)[cntr]);
		++cntr;
	}
	printf("\n");
	printf("\t\tSTACK B:\n");
	cntr = stacks->stk_b_t;
	while (stacks->stk_b_t < stacks->stk_size && cntr < stacks->stk_size)
	{
		printf("\t\t%d\n", (stacks->stk_b)[cntr]);
		++cntr;
	}
	printf("\n");
}
