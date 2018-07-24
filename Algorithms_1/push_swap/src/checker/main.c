/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:44:21 by egenis            #+#    #+#             */
/*   Updated: 2018/07/24 08:07:51 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"

static int		ft_check(int ac, char **av)
{
	if (ac < 2)
		ft_putstr_fd("Error\n", 2);
	if (ac < 2)
		return (-1);
	if (ac == 2)
		if (ft_check_arg1(av[1]) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
	if (ac > 2)
		if (ft_check_argm(ac, av) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
	return (0);
}

int				main(int ac, char **av)
{
	if (ft_check(ac, av) == -1)
		return (-1);
	return (0);
}
