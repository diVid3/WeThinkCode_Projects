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

void				ft_print_stacks(t_stacks *stacks)
{
	int		cntr;

	ft_putstr("\n\t\tSTACK A:\n");
	cntr = stacks->stk_a_t;
	while (stacks->stk_a_t < stacks->stk_size && cntr < stacks->stk_size)
	{
		ft_putstr("\t\t");
		ft_putnbr((stacks->stk_a)[cntr]);
		ft_putchar('\n');
		++cntr;
	}
	ft_putstr("\n\t\tSTACK B:\n");
	cntr = stacks->stk_b_t;
	while (stacks->stk_b_t < stacks->stk_size && cntr < stacks->stk_size)
	{
		ft_putstr("\t\t");
		ft_putnbr((stacks->stk_b)[cntr]);
		ft_putchar('\n');
		++cntr;
	}
	ft_putchar('\n');
}
