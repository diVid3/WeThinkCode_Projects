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

int		is_label_return(char *str_no_cmmnt, char **arr, int cntr)
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

	str_no_cmmnt = strcdup(str, '#');
	arr = split(str_no_cmmnt);
	cntr = 0;
	while (arr[cntr])
		++cntr;
	if (cntr != 1)
		if (is_label_return(str_no_cmmnt, arr, cntr) == 0)
			return (0);
	cntr2 = -1;
	while (arr[0][++cntr2] && arr[0][cntr2] != LABEL_CHAR)
		if (is_label_chars(arr[0][cntr2]) == 0)
			if (is_label_return(str_no_cmmnt, arr, cntr) == 0)
				return (0);
	if (arr[0][cntr2] != LABEL_CHAR || arr[0][++cntr2] != '\0')
		if (is_label_return(str_no_cmmnt, arr, cntr) == 0)
			return (0);
	is_label_return(str_no_cmmnt, arr, cntr);
	return (1);
}

int		is_label_op(char *str)
{
}

int		is_func(char *str);
{
}

/*
** Dovi's bad pseudo code
*/

/*
char	*is_name(char *line, int swtch)
{
	if swtch == 0
	if (strsplit(line)[0] == ".name")
		if (qoute_count(strsplit(line[1])) == 2)
			return (strcdup(strsplit[1], """) + 1);
	if swtch == 1
		do comment
	
}
*/

/*
int		main(void)
{
	int		read_b;
	char	*line;
	int		ans;

	read_b = get_next_line(0, &line);
	ans = is_label(line);
	printf("is_label returned %d\n", ans);
	return (0);
}
*/

