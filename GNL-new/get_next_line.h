#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 8

typedef	struct	s_gnl_mem
{
	char		*arr_l;
	char		*prev_l;
	char		*prev_arr_l;
	ssize_t		read_b;
}				t_gnl_mem;

int	get_next_line(const int fd, char **line);

#endif
