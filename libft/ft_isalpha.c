/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 06:53:58 by egenis            #+#    #+#             */
/*   Updated: 2018/05/23 07:13:23 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <ctype.h>

int ft_isalpha(int c)
{
	return (((unsigned char)c >= 0 && (unsigned char)c <= 127) ? 1 : 0);
}

int main(void)
{
	printf("The return val is %d\n", isalpha(69));
	printf("The return val is %d\n", ft_isalpha(69));
	return (0);
}
