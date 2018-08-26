#include "../inc/lem_in.h"

void		get_start(t_data *d, char *line)
{
	int		read_b;
	char	*arr;

	read_b = 1;
	while (read_b)
	{
		read_b = get_next_line(0, &line);
		if (is_room(line))
		{
			arr = ft_strsplit(line, ' ');
			room_add_node_end(&(d->room), arr[0], 1, 0);
			ft_del_matrix((void **)(arr), 3);
		}
		else if (is_comment(line))
			continue ;
		else if (is_command(line))
			continue ;
		else
			quit(d, 1);
	}
}