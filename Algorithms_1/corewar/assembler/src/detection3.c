/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:10:32 by egenis            #+#    #+#             */
/*   Updated: 2018/09/18 09:10:34 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

int		is_ind(char *arg)
{
	int		cntr;

	if (arg[0] == '+' || arg[0] == '-')
	{
		cntr = 1;
		if (is_strnum(arg, &cntr, 1) == 0)
			return (0);
	}
	if (ft_isdigit(arg[0]))
	{
		cntr = 0;
		if (is_strnum(arg, &cntr, 0) == 0)
			return (0);
	}
	if (arg[0] == LABEL_CHAR)
	{
		if (is_label_valid(arg + 1) == 0)
			return (0);
	}
	else if (is_digits(arg) == 0)
		return (0);
	return (1);
}

int		validate_field(int field_byte, char *arg)
{
	if (field_byte == 0 || field_byte > 7)
		return (0);
	if (field_byte == 1 && is_reg(arg) == 0)
			return (0);
	if (field_byte == 2 && is_dir(arg) == 0)
			return (0);
	if (field_byte == 3 && is_reg(arg) == 0 && is_dir(arg) == 0)
			return (0);
	if (field_byte == 4 && is_ind(arg) == 0)
			return (0);
	if (field_byte == 5 && is_ind(arg) == 0 && is_reg(arg) == 0)
			return (0);
	if (field_byte == 6 && is_ind(arg) == 0 && is_dir(arg) == 0)
			return (0);
	if (field_byte == 7 && is_ind(arg) == 0 && is_dir(arg) == 0 &&
		is_reg(arg) == 0)
			return (0);
	return (1);
}

int		is_arg_types_valid(int opcode, int fields_valid, char **arr)
{
	int		field_cntr;

	field_cntr = -1;
	while (++field_cntr < fields_valid)
		if (validate_field(g_op_tab[opcode].params[field_cntr],
			arr[field_cntr]) == 0)
			return (0);
	return (1);
}

int		is_args_valid(char *func, char *args)
{
	int		cntr;
	int		field_cntr;
	int		fields_valid;
	int		opcode;
	char	**arr;

	opcode = is_func_valid(func);
	arr = ft_strsplit(args, SEPARATOR_CHAR);
	field_cntr = -1;
	fields_valid = 0;
	while (++field_cntr < 3)
		if (g_op_tab[opcode].params[field_cntr] > 0)
			++fields_valid;
	cntr = 0;
	while (arr[cntr])
		++cntr;
	if (fields_valid != cntr)
		if (free_return(NULL, arr, cntr) == 1)
			return (0);
	if (is_arg_types_valid(opcode, fields_valid ,arr) == 0)
		if (free_return(NULL, arr, cntr) == 1)
			return (0);
	ft_free_matrix((void **)arr);
	return (1);
}

int		is_func(char *str)
{
	int		cntr;
	char	*str_no_cmmnt;
	char	**arr;

	str_no_cmmnt = strcdup(str, COMMENT_CHAR);
	arr = split(str_no_cmmnt);
	cntr = 0;
	while (arr[cntr])
		++cntr;
	if (cntr != 2)
		if (free_return(str_no_cmmnt, arr, cntr) == 1)
			return (0);
	if (is_func_valid(arr[0]) == 0)
		if (free_return(str_no_cmmnt, arr, cntr) == 1)
			return (0);
	if (is_args_valid(arr[0], arr[1]) == 0)
		if (free_return(str_no_cmmnt, arr, cntr) == 1)
			return (0);
	free_return(str_no_cmmnt, arr, cntr);
	return (1);
}
