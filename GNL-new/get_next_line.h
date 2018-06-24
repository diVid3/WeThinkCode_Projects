#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 8

typedef	struct	s_mem
{
	char		*arr;
	char		*tmp;
	char		*nl_addr;
	//char		*store;
	char		*free_me;
	ssize_t		read_b;
}				t_mem;

int	get_next_line(const int fd, char **line);

#endif