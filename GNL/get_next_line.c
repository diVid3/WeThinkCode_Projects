/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:21:07 by egenis            #+#    #+#             */
/*   Updated: 2018/06/08 13:09:04 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



static	void	ft_controller(char *buff_str, ssize_t rd_bytes)
{

}

int				get_next_line(const int fd, char **line)
{
	ssize_t		rd_bytes;
	char		*buff_str;

	buff_str = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (!buff_str || BUFF_SIZE == 0)
		return (-1);
	rd_bytes = read(fd, buff_str, BUFF_SIZE);
	if (rd_bytes == 0)
		return (0);
	if (rd_bytes < 0)
		return (-1);
	ft_controller(buff_str, rd_bytes);
	return (1);
}

int	main(int ac, char **av)
{
	return (0);
}
