#include "../inc/lem_in.h"

void		options(int ac, char **av, t_data *d)
{
	static int		swtch = 0;

	if (ac != 2)
		return ;
	if (ft_strcmp(av[1], "-v") != 0)
		return ;
	if (swtch == 0)
	{
		ft_putchar('\n');
		ft_putchar('\n');
		print_adj_mat(d);
		swtch = 1;
	}
	else if (swtch != 0)
	{
		ft_putchar('\n');
		print_stack(d);
	}
}