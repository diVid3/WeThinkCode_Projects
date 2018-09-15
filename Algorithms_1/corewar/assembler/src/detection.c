#include "../inc/asm.h"

/*
** Need a better way to detect pipes. This waits for input.
*/

/*
int		has_pipe(void)
{
	char		*line;
	int			read_b;

	read_b = get_next_line(0, &line);
	if (read_b > 0 || read_b == 0)
	{
		ft_memdel((void **)(&line));
		return (1);
	}
	ft_memdel((void **)(&line));
	return (0);
}
*/

void	iterate_w_space(char *str, int *cntr)
{
	while (str[*cntr] && (str[*cntr] == ' ' || str[*cntr] == 9 ||
			str[*cntr] == 11 || str[*cntr] == 12 || str[*cntr] == 13))
		++(*cntr);
}

int		is_name_cmd(char *str)
{
	int		cntr;

	cntr = 0;
	iterate_w_space(str, &cntr);
	if (ft_strncmp(str + cntr, NAME_CMD_STRING,
		strclen(NAME_CMD_STRING)) != 0)
		return (0);
	cntr += strclen(NAME_CMD_STRING);
	if (str[cntr] != ' ' && str[cntr] != 9 && str[cntr] != 11 &&
		str[cntr] != 12 && str[cntr] != 13)
		return (0);
	iterate_w_space(str, &cntr);
	if (str[cntr] != '"')
		return (0);
	while (str[++cntr] && str[cntr] != '"')
		;
	if (str[cntr] != '"')
		return (0);
	++cntr;
	iterate_w_space(str, &cntr);
	if (str[cntr] != '\0' && str[cntr] != COMMENT_CHAR)
		return (0);
	return (1);
}

int		is_comment_cmd(char *str)
{
	int		cntr;

	cntr = 0;
	iterate_w_space(str, &cntr);
	if (ft_strncmp(str + cntr, COMMENT_CMD_STRING,
		strclen(COMMENT_CMD_STRING)) != 0)
		return (0);
	cntr += strclen(COMMENT_CMD_STRING);
	if (str[cntr] != ' ' && str[cntr] != 9 && str[cntr] != 11 &&
		str[cntr] != 12 && str[cntr] != 13)
		return (0);
	iterate_w_space(str, &cntr);
	if (str[cntr] != '"')
		return (0);
	while (str[++cntr] && str[cntr] != '"')
		;
	if (str[cntr] != '"')
		return (0);
	++cntr;
	iterate_w_space(str, &cntr);
	if (str[cntr] != '\0' && str[cntr] != COMMENT_CHAR)
		return (0);
	return (1);
}

int		has_ext(char *file)
{
	int		cntr;

	cntr = 0;
	while (file[cntr])
		++cntr;
	--cntr;
	if (file[cntr] == 's' && file[cntr - 1] == '.')
		return (1);
	return (0);
}
