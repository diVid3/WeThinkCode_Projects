/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:09:18 by egenis            #+#    #+#             */
/*   Updated: 2018/09/21 12:09:20 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

int		open_w(char **av)
{
	char	*no_ext_str;
	char	*added_ext_str;
	int		fd;

	if (has_ext(av[1]) == 1)
	{
		no_ext_str = strndup(av[1], ft_strrchr(av[1], '.') - av[1]);
		printf("no_ext_str is %s\n", no_ext_str);
		added_ext_str = ft_strjoin(no_ext_str, ".cor");
		fd = open(added_ext_str, O_CREAT | O_WRONLY);
		ft_memdel((void **)(&no_ext_str));
		ft_memdel((void **)(&added_ext_str));
		return (fd);
	}
	added_ext_str = ft_strjoin(av[1], ".cor");
	fd = open(added_ext_str, O_CREAT | O_WRONLY);
	ft_memdel((void **)(&added_ext_str));
	return (fd);
}

void	write_header(t_data *d, int fd)
{
	int		name_len;
	int		comment_len;
	int		cntr;
	char	etb;

	name_len = ft_strlen(d->name);
	comment_len = ft_strlen(d->comment);
	write_rev_ui(COREWAR_EXEC_MAGIC, 4, fd);
	cntr = -1;
	while (++cntr < name_len)
		write(fd, &(d->name) + cntr, 1);
	cntr = -1;
	while (++cntr < PROG_NAME_LENGTH - name_len)
		write(fd, "\0", 1);
	etb = 27;
	write(fd, &etb, 1);
	cntr = -1;
	while (++cntr < comment_len)
		write(fd, &(d->comment) + cntr, 1);
	cntr = -1;
	while (++cntr < COMMENT_LENGTH - comment_len)
		write(fd, "\0", 1);
}

void	write_data(t_data *d, char **av)
{
	int		fd;

	fd = open_w(av);
	write_header(d, fd);
}
