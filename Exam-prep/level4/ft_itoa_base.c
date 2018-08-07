/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:18:02 by egenis            #+#    #+#             */
/*   Updated: 2018/08/07 17:44:44 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> // <-------------------------------------------- Remove this.

int	ft_itoa_base(int value, int base)
{
	int		len;
	long	nb;
	char	*str;

	len = (value < 0 && base == 10) ? 3 : 2;
	nb = (value < 0) ? (value *= -1) : value;
	while ((value /= 10) >= 1)
		++len;
	str = malloc(sizeof(char) * len);
	str[len--] = '\0';
	nb = (value < 0) ? (value *= -1) : value;
	return (len);
}

int		main(void)
{
	int x = 5734;
	printf("len is %d\n", ft_itoa_base(x, 10));
	return (0);
}
