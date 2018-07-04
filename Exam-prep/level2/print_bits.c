/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:41:18 by egenis            #+#    #+#             */
/*   Updated: 2018/07/04 15:53:07 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_bits(unsigned char octet)
{
	int			cntr;
	char		arr[8];

	cntr = 0;
	while (cntr < 8)
	{
		arr[cntr] = octet % 2;
		octet /= 2;
		++cntr;
	}
	cntr = 7;
	while (cntr >= 0 )
	{
		ft_putchar(arr[cntr] + '0');
		--cntr;
	}
}

int		main(void)
{
	print_bits(17);
	return (0);
}
