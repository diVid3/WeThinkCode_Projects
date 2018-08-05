/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:44:21 by egenis            #+#    #+#             */
/*   Updated: 2018/07/30 11:56:24 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"

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
	if (ac < 2)
		return (0);
	if (ft_check(ac, av) == -1)
		return (-1);
	// ft_build_stacks()
	// ft_do_ops()
	// ft_validate_stack()
	return (0);
}
