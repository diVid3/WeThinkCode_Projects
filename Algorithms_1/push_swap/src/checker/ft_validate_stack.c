#include "../../inc/checker/checker.h"

void			ft_validate_stack(t_stacks *stacks)
{
	int		cntr;

	if (stacks->stk_size == 1 && stacks->stk_b_t == stacks->stk_size)
		ft_putstr_fd("OK\n", 1);
	if (stacks->stk_size == 1 && stacks->stk_b_t == stacks->stk_size)
		return ;
	if (stacks->stk_b_t == stacks->stk_size)
	{
		cntr = -1;
		while (++cntr + 1 < stacks->stk_size)
			if ((stacks->stk_a)[cntr] > (stacks->stk_a)[cntr + 1])
			{
				ft_putstr_fd("KO\n", 1);
				return ;
			}
	}
	else
	{
		ft_putstr_fd("KO\n", 1);
		return ;
	}
	ft_putstr_fd("OK\n", 1);
}