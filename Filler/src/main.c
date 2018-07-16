/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:43:39 by egenis            #+#    #+#             */
/*   Updated: 2018/07/16 14:27:02 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		main(void)
{
	static t_input	data;
	int				ans_input;

	while (1)
	{
		if ((ans_input = ft_get_input(&data)) == -1)
			ft_putstr_fd("Bad input.\n", 2);
		if (ans_input == -1)
			return (-1);
		if (ans_input == 2)
			continue;
		ft_place_piece(data);
	}
	return (0);
}
