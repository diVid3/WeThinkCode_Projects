/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:18:31 by egenis            #+#    #+#             */
/*   Updated: 2018/09/18 09:18:33 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

int		is_reg(char *arg)
{
	int		cntr;
	int		reg_val;

	if (arg[0] != 'r')
		return (0);
	cntr = 1;
	while (ft_isdigit(arg[cntr]))
		++cntr;
	if (arg[cntr] != '\0' || cntr == 1)
		return (0);
	if (ft_is_int(arg + 1) == 0)
		return (0);
	reg_val = ft_atoi(arg + 1);
	if (reg_val <= 0 || reg_val > REG_NUMBER)
		return (0);
	return (1);
}

int		is_strnum(char *arg, int *cntr, int is_int_start)
{
	int		tmp;

	tmp = *cntr;
	while (ft_isdigit(arg[*cntr]))
		++(*cntr);
	if (arg[*cntr] != '\0' || *cntr == tmp)
		return (0);
	if (ft_is_int(arg + is_int_start) == 0)
		return (0);
	return (1);
}

int		is_label_valid(char *arg)
{
	int		cntr;

	cntr = -1;
	while (arg[++cntr])
		if (is_label_chars(arg[cntr]) == 0)
			return (0);
	return (1);
}

int		is_digits(char *arg)
{
	int		cntr;

	cntr = 0;
	if ((arg[0] == '+' || arg[0] == '-') && arg[1])
		++cntr;
	while (ft_isdigit(arg[cntr]))
		++cntr;
	if (arg[cntr] != '\0' || cntr == 0)
		return (0);
	return (1);
}

int		is_dir(char *arg)
{
	int		cntr;

	if (arg[0] != '%')
		return (0);
	if (arg[1] == '+' || arg[1] == '-')
	{
		cntr = 2;
		if (is_strnum(arg, &cntr, 1) == 0)
			return (0);
	}
	if (ft_isdigit(arg[1]))
	{
		cntr = 1;
		if (is_strnum(arg, &cntr, 1) == 0)
			return (0);
	}
	if (arg[1] == LABEL_CHAR)
	{
		if (is_label_valid(arg + 2) == 0)
			return (0);
	}
	else if (is_digits(arg + 1) == 0)
		return (0);
	return (1);
}
