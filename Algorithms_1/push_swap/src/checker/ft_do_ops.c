#include "../../inc/checker/checker.h"
#include <stdio.h>

// Remember to free line inside the operation functions.

static int		ft_do_ops2(t_stacks *stacks, char **line)
{
	if (ft_strcmp(*line, "ra") == 0)
		ft_rotate(stacks, 0);
	else if (ft_strcmp(*line, "rb") == 0)
		ft_rotate(stacks, 1);
	else if (ft_strcmp(*line, "rr") == 0)
		ft_rotate(stacks, 2);
	else if (ft_strcmp(*line, "rra") == 0)
		ft_r_rotate(stacks, 0);
	else if (ft_strcmp(*line, "rrb") == 0)
		ft_r_rotate(stacks, 1);
	else if (ft_strcmp(*line, "rrr") == 0)
		ft_r_rotate(stacks, 2);
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (0);
}

int				ft_do_ops(t_stacks *stacks)
{
	char	**line;

	while (get_next_line(0, line))
	{
		if (ft_strcmp(*line, "sa") == 0)
			ft_swap(stacks, 0);
		else if (ft_strcmp(*line, "sb") == 0)
			ft_swap(stacks, 1);
		else if (ft_strcmp(*line, "ss") == 0)
			ft_swap(stacks, 2);
		else if (ft_strcmp(*line, "pa") == 0)
			ft_push(stacks, 0);
		else if (ft_strcmp(*line, "pb") == 0)
			ft_push(stacks, 1);
		else if (ft_do_ops2(stacks, line) == -1)
				return (-1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	return (0);
}
