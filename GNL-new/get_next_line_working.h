#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 2

typedef	struct	s_ac_mem
{
	char		*arr_l;
	char		*tmp;
	char		*free;
	size_t		spd;
	size_t		cntr;
	_Bool		nl_found;
}				t_ac_mem;

typedef	struct	s_gl_mem
{
	char		*arr_l;
	char		*prev_line;
	char		*p_arr_l;
	size_t		nl_pos;
	ssize_t		read_b;
	int			ret_val;
	_Bool		nl_found;
	_Bool		swtch;
}				t_gl_mem;

int	get_next_line(const int fd, char **line);

#endif
