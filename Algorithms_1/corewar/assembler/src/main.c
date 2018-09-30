/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:31:34 by egenis            #+#    #+#             */
/*   Updated: 2018/09/11 07:31:36 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	print_err_exit_more(int err_msg)
{
	if (err_msg == 10)
		ft_putstr_fd("ERROR - INVALID LABEL REFERENCE(S)\n", 2);
	else if (err_msg == 11)
		ft_putstr_fd("ERROR - NO INSTRUCTION(S)\n", 2);
	exit(-1);
}

void	print_err_exit(int err_msg, int line_nbr)
{
	if (err_msg == 1)
		ft_putstr_fd("ERROR - INVALID MACRO(S)\n", 2);
	else if (err_msg == 2)
		ft_putstr_fd("ERROR - NO INPUT FILE / MULTIPLE FILES\n", 2);
	else if (err_msg == 3)
		ft_putstr_fd("ERROR - INVALID FILE / COULD NOT OPEN FILE\n", 2);
	else if (err_msg == 4)
	{
		ft_putstr_fd("ERROR - UNKNOWN LINE - LINE: ", 2);
		ft_putnbr_fd(line_nbr, 2);
		ft_putchar_fd('\n', 2);
	}
	else if (err_msg == 5)
		ft_putstr_fd("ERROR - NO NAME / NO COMMENT\n", 2);
	else if (err_msg == 6)
		ft_putstr_fd("ERROR - NAME / COMMENT TOO LONG\n", 2);
	else if (err_msg == 7)
		ft_putstr_fd("ERROR - STACKED LABEL(S)\n", 2);
	else if (err_msg == 8)
		ft_putstr_fd("ERROR - LABEL(S) NOT ASSOCIATED\n", 2);
	else if (err_msg == 9)
		ft_putstr_fd("ERROR - DUPLICATE LABEL(S)\n", 2);
	else if (err_msg > 9)
		print_err_exit_more(err_msg);
	exit(-1);
}

void	quit(t_data *d, int err_msg, int line_nbr)
{
	ft_memdel((void **)(&(d->name)));
	ft_memdel((void **)(&(d->comment)));
	ft_memdel((void **)(&(d->output_name)));
	input_free_list(d->input);
	func_free_list(d->func);
	if (err_msg != 0)
		print_err_exit(err_msg, line_nbr);
	exit(0);
}

int		main(int ac, char **av)
{
	static t_data		d;

	macro_check(&d);
	get_input(&d, ac, av);
	do_calcs(&d);
	write_data(&d, av);
	ft_putstr_fd("GENERATED - ", 1);
	ft_putstr_fd(d.output_name, 1);
	ft_putchar_fd('\n', 1);
	quit(&d, 0, -1);
}
