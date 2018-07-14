#include "../inc/filler.h"
#include <stdio.h>

int				verify_top_ruler(char *line)
{
	char		**arr;
	size_t		cntr;

	if (ft_count_words(line, ' ') != 1)
		return (0);
	arr = ft_strsplit(line, ' ');
	cntr = 0;
	while (arr[0][cntr])
	{
		if (!(arr[0][cntr] >= '0' && arr[0][cntr] <= '9'))
			return (0);
		++cntr;
	}
	ft_del_matrix((void **)arr, 1);
	return (1);
}

int				get_map(t_input *data)
{
	char		*line
	char		*arr;

	if (!data->map_rows || !data->map_cols)
		return (-1);
	if (get_next_line(0, &line) <= 0)
		return (-1);
	if (verify_top_ruler(line) == 0)
		return (-1);
	ft_memdel((void **)(&line));

}

int 	main(void)
{
}