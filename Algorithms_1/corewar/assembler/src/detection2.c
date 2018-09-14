#include "../inc/asm.h"

int		is_name(char *str)
{
	int		cntr;

	cntr = 0;
	while (str[cntr] && (str[cntr]))
}

int		is_comment(char *str)
{
	int		cntr;

	cntr = 0;
	while (str[cntr] && (str[cntr] == ' ' || str[cntr] == 9 ||
			str[cntr] == 11 || str[cntr] == 12 || str[cntr] == 13))
		++cntr;
	return (str[cntr] == COMMENT_CHAR);
}

int		is_label(char *str)
{
}

int		is_label_op(char *str)
{
}

int		is_op(char *str);
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
