/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:12:17 by egenis            #+#    #+#             */
/*   Updated: 2018/09/18 09:13:40 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

/*
** Writes 2 bytes in reverse order, i.e. little endian -> big endian.
*/

void	write_rev_us(unsigned short x, int size, int fd)
{
	char	*ptr;

	ptr = (char *)&x;
	while (--size >= 0)
		write(fd, ptr + size, 1);
}

/*
** Writes 4 bytes in reverse order, i.e. little endian -> big endian.
*/

void	write_rev_ui(unsigned int x, int size, int fd)
{
	char	*ptr;

	ptr = (char *)&x;
	while (--size >= 0)
		write(fd, ptr + size, 1);
}

int		free_refs(char *str1, char *str2)
{
	ft_memdel((void **)(&str1));
	ft_memdel((void **)(&str2));
	return (0);
}

void	put2hex(unsigned char num, size_t turn, int fd)
{
	static char	*hex_val = "0123456789abcdef";

	if (turn == 3)
		return ;
	put2hex(num / 16, turn + 1, fd);
	ft_putchar_fd(hex_val[num % 16], fd);
}

void	ft_put2hex(unsigned char num, int fd)
{
	if (num == 0)
		ft_putstr_fd("00", fd);
	else
		put2hex(num, 1, fd);
}
