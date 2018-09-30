#include "../inc/asm.h"

void			write_label_ind(t_func *tmp, char *arg, int fd)
{
	char		**arr;
	int			jump_diff_up;
	int			jump_diff_down;

	arr = ft_strsplit(arg, LABEL_CHAR);
	jump_diff_up = calc_jump_up(tmp, arr[0]);
	jump_diff_down = calc_jump_down(tmp, arr[0]);
	if (jump_diff_up == jump_diff_down)
		write_num(0, 2, fd);
	else if (jump_diff_up && jump_diff_down == 0)
		write_num(jump_diff_up, 2, fd);
	else if (jump_diff_up == 0 && jump_diff_down)
		write_num(jump_diff_down, 2, fd);
	ft_free_matrix((void **)arr);
}

void			write_ind(t_func *tmp, int fd, char *arg)
{
	int		nbr;

	if (arg[0] == LABEL_CHAR)
		write_label_ind(tmp, arg, fd);
	else
	{
		nbr = ft_atoi(arg);
		write_num(nbr, 2, fd);
	}
}
