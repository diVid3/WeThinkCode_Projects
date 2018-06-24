
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		get_next_line(const int fd, char **line);
{
	static t_mem	mem = {"", NULL, NULL, NULL, NULL, 1};

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (!read_b)
		return (0);
	while (!mem.nl_addr && mem.read_b)
	{
		mem.free_me = mem.arr;
		mem.tmp = ft_memalloc(sizeof(char) * BUFF_SIZE + 1)
		mem.read_b = read(fd, mem.tmp, BUFF_SIZE);
		mem.arr = ft_strjoin(mem.arr, mem.tmp);
		mem.nl_addr = ft_strchr(mem.arr, '\n');
		if (*mem.free_me)
			ft_memdel((void **)(&free_me));
		ft_memdel((void **)(&mem.tmp));
	}
	*line = ft_strsub(mem.arr, 0, ft_strclen(mem.arr, '\n'));
	mem.arr = (mem.nl_addr) ? ft_strdup(mem.nl_addr + 1) : mem.arr;
	return (1);
}

int		main(int ac, char **av)
{
	int			fd;
	int			ans;
	char		**line;

	(void)ac;
	line = malloc(sizeof(void *));
	fd = open(av[1], O_RDONLY);

	return (0);
}