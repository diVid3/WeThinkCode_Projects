/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:51:18 by egenis            #+#    #+#             */
/*   Updated: 2018/08/20 17:32:53 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		print_error_line(t_data *d, int error)
{
	int			cntr;
	t_input		*tmp;

	if (error <= 0)
		return ;
	cntr = 0;
	tmp = d->input;
	while (tmp)
	{
		++cntr;
		tmp = tmp->next;
	}
	if (error == 3)
		++cntr;
	ft_putstr_fd("\033[0;33mLINE - ", 2);
	ft_putnbr(cntr);
	ft_putstr_fd("\033[0m\n", 2);
}

void		print_error_type(int error)
{
	if (error == 1)
		ft_putstr_fd("\033[0;33mERROR - ANTS - INCORRECT\033[0m\n", 2);
	if (error == 2)
		ft_putstr_fd("\033[0;33mERROR - ROOM - DUPLICATE ROOM\033[0m\n", 2);
	if (error == 3)
		ft_putstr_fd("\033[0;33mERROR - ROOM - EMPTY LINE\033[0m\n", 2);
	if (error == 4)
		ft_putstr_fd("\033[0;33mERROR - ROOM - UNKNOWN LINE\033[0m\n", 2);
	if (error == 5)
		ft_putstr_fd("\033[0;33mERROR - ROOM - MISSING START/END OR "
		"NO ROOMS\033[0m\n", 2);
	if (error == 6)
		ft_putstr_fd("\033[0;33mERROR - LINK - ROOM(S) DOESN'T "
		"EXIST\033[0m\n", 2);
	if (error == 7)
		ft_putstr_fd("\033[0;33mERROR - LINK - UNKNOWN LINE\033[0m\n", 2);
	if (error == 8)
		ft_putstr_fd("\033[0;33mERROR - NO PATH\n", 2);
}

void		quit(t_data *d, int error)
{
	print_error_type(error);
	print_error_line(d, error);
	input_free_list(d->input);
	free_adj_mat(d);
	ft_memdel((void **)(&(d->stack)));
	room_free_list(d->room);
	if (error)
		exit(1);
	exit(0);
}

int			main(void)
{
	static t_data	d;

	get_input(&d);
	ft_putchar('\n');
	print_adj_mat(&d);
	solve_graph(&d);
	ft_putchar('\n');
	print_stack(&d);
	ft_putchar('\n');
	input_print_list(d.input);
	send_ants(&d);
	quit(&d, 0);
}
