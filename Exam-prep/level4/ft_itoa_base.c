/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:18:02 by egenis            #+#    #+#             */
/*   Updated: 2018/08/07 18:33:51 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> // <-------------------------------------------- Remove this.

char	*ft_itoa_base(int value, int base)
{
	int		len;
	int		stop;
	long	nb;
	char	*str;

	len = (value < 0 && base == 10) ? 2 : 1;
	nb = (value < 0) ? -(long)value : value;
	while ((nb /= base) >= 1)
		++len;
	str = malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	nb = (value < 0) ? -(long)value : value;
	stop = (value < 0 && base == 10) ? 1 : 0;
	while (--len >= stop)
	{
		str[len] = (nb % base < 10) ? nb % base + 48 : nb % base - 10 + 65;
		nb /= base;
	}
	(value < 0 && base == 10) ? str[0] = '-' : 0;
	return (str);
}

int		main(int ac, char **av)
{
	(void)ac;

	int value = atoi(av[1]);
	int base = atoi(av[2]);
	printf("%s\n", ft_itoa_base(value, base));
	return (0);
}
