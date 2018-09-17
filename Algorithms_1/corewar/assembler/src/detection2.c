#include "../inc/asm.h"

/*
** A line that contains only whitespace, i.e. not a completely empty line,
** is still valid. The check for null below accommodates that.
*/

int		is_comment(char *str)
{
	int		cntr;

	cntr = 0;
	while (str[cntr] && (str[cntr] == ' ' || str[cntr] == 9 ||
			str[cntr] == 11 || str[cntr] == 12 || str[cntr] == 13))
		++cntr;
	if (str[cntr] == COMMENT_CHAR || str[cntr] == '\0')
		return (1);
	return (0);
}

/*
** Bad naming due to op.h having bad macros.
*/

int		is_label_chars(char c)
{
	char	*str;
	int		cntr;

	str = LABEL_CHARS;
	cntr = -1;
	while (str[++cntr])
		if (c == str[cntr])
			return (1);
	return (0);
}

int		free_return(char *str_no_cmmnt, char **arr, int cntr)
{
	ft_memdel((void **)(&str_no_cmmnt));
	ft_del_matrix((void **)arr, cntr);
	return (0);
}

int		is_label(char *str)
{
	int		cntr;
	int		cntr2;
	char	*str_no_cmmnt;
	char	**arr;

	str_no_cmmnt = strcdup(str, COMMENT_CHAR);
	arr = split(str_no_cmmnt);
	cntr = 0;
	while (arr[cntr])
		++cntr;
	if (cntr != 1)
		if (free_return(str_no_cmmnt, arr, cntr) == 0)
			return (0);
	cntr2 = -1;
	while (arr[0][++cntr2] && arr[0][cntr2] != LABEL_CHAR)
		if (is_label_chars(arr[0][cntr2]) == 0)
			if (free_return(str_no_cmmnt, arr, cntr) == 0)
				return (0);
	if (arr[0][cntr2] != LABEL_CHAR || arr[0][++cntr2] != '\0' ||
		(arr[0][0] == LABEL_CHAR && arr[0][1] == '\0'))
		if (free_return(str_no_cmmnt, arr, cntr) == 0)
			return (0);
	free_return(str_no_cmmnt, arr, cntr);
	return (1);
}

/*
int		is_label_op(char *str)
{
}
*/

/*
** This function treats non-zero as true, and zero as false, it thus returns
** the valid operation's opcode upon validation.
*/

int		is_func_valid(char *func)
{
	int		cntr;

	cntr = 0;
	while (++cntr <= 16)
		if (ft_strcmp(func, g_op_tab[cntr].name) == 0)
			return (cntr);
	return (0);
}

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
		return 0;
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

int		validate_field(int param_byte, char *arg)
{
	if (param_byte == 0)
		return (0);
	if (param_byte == 1)
		if (is_reg(arg) == 0)
			return (0);
	if (param_byte == 2)
		if (is_dir(arg) == 0)
			return (0);
	if (param_byte == 3)
		if (is_reg(arg) == 0 && is_dir(arg) == 0)
			return (0);
	if (param_byte == 4)
		if (is_ind(arg) == 0)
			return (0);
	if (param_byte == 5)
		if (is_ind(arg) == 0 && is_reg(arg) == 0)
			return (0);
	if (param_byte == 6)
		if (is_ind(arg) == 0 && is_dir(arg) == 0)
			return (0);
	if (param_byte == 7)
		if (is_ind(arg) == 0 && is_dir(arg) == 0 && is_reg(arg) == 0)
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
		if (free_return(NULL, arr, cntr) == 0)
			return (0);
	if (is_arg_types_valid(opcode, fields_valid ,arr) == 0)
		if (free_return(NULL, arr, cntr) == 0)
			return (0);
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
		if (free_return(str_no_cmmnt, arr, cntr) == 0)
			return (0);
	if (is_func_valid(arr[0]) == 0)
		if (free_return(str_no_cmmnt, arr, cntr) == 0)
			return (0);
	if (is_args_valid(arr[0], arr[1]) == 0)
		if (free_return(str_no_cmmnt, arr, cntr) == 0)
			return (0);
	free_return(str_no_cmmnt, arr, cntr);
	return (1);
}

int		main(void)
{
	int		read_b;
	char	*line;
	int		ans;

	while (1)
	{
		read_b = get_next_line(0, &line);
		ans = is_label(line);
		printf("is_label returned %d\n", ans);
	}
	read_b = get_next_line(0, &line);
	ans = is_func(line);
	printf("is_func returned %d\n", ans);
	return (0);
}
