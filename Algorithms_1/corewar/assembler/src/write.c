/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:19:50 by egenis            #+#    #+#             */
/*   Updated: 2018/09/11 07:19:52 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

/*
** This is to simply write a variable of variable size in reverse, useful for
** different endian systems.
*/

void	write_rev(void x, int size)
{
	char	*ptr;

	ptr = (char *)&x;
	while (--size >= 0)
		write(1, ptr + size, 1);
}