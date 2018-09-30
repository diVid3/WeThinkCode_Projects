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

int				open_w(t_data *d, char **av)
{
	char	*no_ext_str;
	char	*added_ext_str;
	int		fd;

	if (has_ext(av[1]) == 1)
	{
		no_ext_str = strndup(av[1], ft_strrchr(av[1], '.') - av[1]);
		added_ext_str = ft_strjoin(no_ext_str, ".cor");
		d->output_name = ft_strdup(added_ext_str);
		fd = open(added_ext_str, O_CREAT | O_WRONLY | O_TRUNC, 0755);
		ft_memdel((void **)(&no_ext_str));
		ft_memdel((void **)(&added_ext_str));
		return (fd);
	}
	added_ext_str = ft_strjoin(av[1], ".cor");
	d->output_name = ft_strdup(added_ext_str);
	fd = open(added_ext_str, O_CREAT | O_WRONLY | O_TRUNC, 0755);
	ft_memdel((void **)(&added_ext_str));
	return (fd);
}

void			write_header(t_data *d, int fd)
{
	int		name_len;
	int		comment_len;
	int		cntr;

	name_len = ft_strlen(d->name);
	comment_len = ft_strlen(d->comment);
	write_rev_ui(COREWAR_EXEC_MAGIC, 4, fd);
	cntr = -1;
	while (++cntr < name_len)
		write(fd, d->name + cntr, 1);
	cntr = -1;
	while (++cntr < (PROG_NAME_LENGTH - name_len))
		write(fd, "\0", 1);
	write_rev_ui(0x00, 4, fd);
	write_rev_ui(0x17, 4, fd);
	cntr = -1;
	while (++cntr < comment_len)
		write(fd, d->comment + cntr, 1);
	cntr = -1;
	while (++cntr < (COMMENT_LENGTH - comment_len))
		write(fd, "\0", 1);
	write_rev_ui(0x00, 4, fd);
}

void			write_op(int opcode, int fd)
{
	unsigned char	*x;

	x = (unsigned char *)(&opcode);
	write(fd, x, 1);
}

void			write_funcs(t_data *d, int fd)
{
	t_func	*tmp;

	tmp = d->func;
	while (tmp)
	{
		write_op(is_func_valid(tmp->func), fd);
		write_enc(tmp, fd);
		write_args(d, tmp, fd);
		tmp = tmp->next;
	}
}

void			write_data(t_data *d, char **av)
{
	int		fd;

	fd = open_w(d, av);
	write_header(d, fd);
	write_funcs(d, fd);
}
