/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:44:21 by egenis            #+#    #+#             */
/*   Updated: 2018/08/06 07:32:41 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap/push_swap.h"

static int		ft_check(int ac, char **av)
{
	char		*str;

	if (ac == 2 && ft_check_arg(av[1]) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (ac > 2)
	{
		str = ft_join_args(av);
		if (ft_check_arg(str) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			ft_memdel((void **)(&str));
			return (-1);
		}
		ft_memdel((void **)(&str));
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac < 2)
		return (0);
	if (ft_check(ac, av) == -1)
		return (-1);
	stacks = ft_build_stacks(ac, av);
	ft_sort_stack(stacks);
	return (0);
}
