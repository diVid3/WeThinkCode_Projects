/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:45:51 by egenis            #+#    #+#             */
/*   Updated: 2018/08/13 17:46:24 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap/push_swap.h"

static void		ft_get_lwst_n_info(t_info_ln *info, t_stacks *stacks)
{
	int			cntr;

	info->lwst_n = (stacks->stk_a)[stacks->stk_a_t];
	info->lwst_n_i = stacks->stk_a_t;
	cntr = stacks->stk_a_t - 1;
	while (++cntr < stacks->stk_size)
		if ((stacks->stk_a)[cntr] < info->lwst_n)
		{
			info->lwst_n = (stacks->stk_a)[cntr];
			info->lwst_n_i = cntr;
		}
	info->stk_mid_i = (stacks->stk_a_t + stacks->stk_size - 1) / 2;
}

void			ft_call_r_rotate_a(t_stacks *stacks)
{
	ft_r_rotate(stacks, 0);
	ft_putstr("rra\n");
}

void			ft_call_rotate_a(t_stacks *stacks)
{
	ft_rotate(stacks, 0);
	ft_putstr("ra\n");
}

void			ft_call_push_b(t_stacks *stacks)
{
	ft_push(stacks, 1);
	ft_putstr("pb\n");
}

void			ft_sort_stack(t_stacks *stacks)
{
	t_info_ln	*info;

	info = malloc(sizeof(t_info_ln));
	while ((stacks->stk_size - 1) - stacks->stk_a_t >= 3)
	{
		ft_get_lwst_n_info(info, stacks);
		if (info->lwst_n_i > info->stk_mid_i)
			while ((stacks->stk_a)[stacks->stk_a_t] != info->lwst_n)
				ft_call_r_rotate_a(stacks);
		else
			while ((stacks->stk_a)[stacks->stk_a_t] != info->lwst_n)
				ft_call_rotate_a(stacks);
		ft_call_push_b(stacks);
	}
	ft_sort_stack_rem_val(stacks);
	while ((stacks->stk_size - 1) - stacks->stk_b_t >= 0)
	{
		ft_push(stacks, 0);
		ft_putstr("pa\n");
	}
	ft_memdel((void **)(&info));
}
