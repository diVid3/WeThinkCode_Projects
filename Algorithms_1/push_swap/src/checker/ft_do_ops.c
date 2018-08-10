/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 07:10:34 by egenis            #+#    #+#             */
/*   Updated: 2018/08/10 07:09:44 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"

static int		ft_pick_op(t_stacks *stacks, char **line)
{
	if (ft_strcmp(*line, "sa") == 0)
		ft_swap(stacks, 0);
	else if (ft_strcmp(*line, "sb") == 0)
		ft_swap(stacks, 1);
	else if (ft_strcmp(*line, "ss") == 0)
		ft_swap(stacks, 2);
	else if (ft_strcmp(*line, "pa") == 0)
		ft_push(stacks, 0);
	else if (ft_strcmp(*line, "pb") == 0)
		ft_push(stacks, 1);
	else if (ft_strcmp(*line, "ra") == 0)
		ft_rotate(stacks, 0);
	else if (ft_strcmp(*line, "rb") == 0)
		ft_rotate(stacks, 1);
	else if (ft_strcmp(*line, "rr") == 0)
		ft_rotate(stacks, 2);
	else if (ft_strcmp(*line, "rra") == 0)
		ft_r_rotate(stacks, 0);
	else if (ft_strcmp(*line, "rrb") == 0)
		ft_r_rotate(stacks, 1);
	else if (ft_strcmp(*line, "rrr") == 0)
		ft_r_rotate(stacks, 2);
	else
		return (-1);
	return (0);
}

int				ft_do_ops(t_stacks *stacks)
{
	char	*line;

	if (ft_strcmp(av[1], "-v") == 0)
		ft_print_stacks(stacks);
	while (get_next_line(0, &line))
	{
		if (ft_pick_op(stacks, &line) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			ft_memdel((void **)(&line));
			return (-1);
		}
		else
			ft_memdel((void **)(&line));
	if (ft_strcmp(av[1], "-v") == 0)
		ft_print_stacks(stacks);
	}
	return (0);
}
