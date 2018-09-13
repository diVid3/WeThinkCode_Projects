#include "../inc/asm.h"

/*
** Need a better way to detect pipes. This waits for input.
*/

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