/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 06:35:46 by egenis            #+#    #+#             */
/*   Updated: 2018/07/03 07:23:13 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_zero_mem(_Bool *mem)
{
	size_t	cntr;

	cntr = 0;
	while (cntr < 128)
	{
		mem[cntr] = 0;
		++cntr;
	}
}

int		ft_test_ac(int ac)
{
	if (ac != 3)
	{
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	size_t			cntr;
	size_t			cntr2;
	unsigned char	ch;
	_Bool			c_mem[128];

	if (ft_test_ac(ac) == 1)
		return (0);
	ft_zero_mem(c_mem);
	cntr = 0;
	while (av[1][cntr])
	{
		cntr2 = 0;
		while(av[2][cntr2])
		{
			ch = av[2][cntr2];
			if (av[1][cntr] == av[2][cntr2] && c_mem[ch] == 0)
				ft_putchar(av[2][cntr2]);
			if (av[1][cntr] == av[2][cntr2] && c_mem[ch] == 0)
				c_mem[ch] = 1;
			++cntr2;
		}
		++cntr;
	}
	ft_putchar('\n');
	return (0);
}
