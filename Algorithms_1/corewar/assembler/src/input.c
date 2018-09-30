/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 10:12:36 by egenis            #+#    #+#             */
/*   Updated: 2018/09/12 10:12:37 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	save_input(t_data *d, int fd)
{
	char		*line;
	int			read_b;

	read_b = 1;
	while (read_b)
	{
		read_b = get_next_line(fd, &line);
		input_add_node_end(&(d->input), line);
	}
	close(fd);
}

void	get_header(t_data *d)
{
	t_input		*tmp;
	char		**arr;

	tmp = d->input;
	while (tmp)
	{
		if (is_name_cmd(tmp->line_ptr) == 1 && d->read_name == 0)
		{
			arr = ft_strsplit(tmp->line_ptr, '"');
			d->name = ft_strdup(arr[1]);
			d->read_name = 1;
			ft_free_matrix((void **)arr);
		}
		else if (is_comment_cmd(tmp->line_ptr) == 1 && d->read_comment == 0)
		{
			arr = ft_strsplit(tmp->line_ptr, '"');
			d->comment = ft_strdup(arr[1]);
			d->read_comment = 1;
			ft_free_matrix((void **)arr);
		}
		tmp = tmp->next;
	}
	if (d->read_name == 0 || d->read_comment == 0)
		quit(d, 5, -1);
}

void	validate_input(t_data *d)
{
	t_input		*tmp;

	tmp = d->input;
	while (tmp)
	{
		if (!is_name_cmd(tmp->line_ptr) && !is_comment_cmd(tmp->line_ptr) &&
			!is_comment(tmp->line_ptr) && !is_label(tmp->line_ptr) &&
			!is_label_func(tmp->line_ptr) && !is_func(tmp->line_ptr))
			quit(d, 4, tmp->line_nbr);
		tmp = tmp->next;
	}
}

int		strjoin_open(char **av)
{
	int		fd;
	char	*added_ext_str;

	added_ext_str = ft_strjoin(av[1], ".s");
	fd = open(added_ext_str, O_RDONLY);
	ft_memdel((void **)(&added_ext_str));
	return (fd);
}

void	get_input(t_data *d, int ac, char **av)
{
	int		fd;

	if (ac == 1 || ac > 2)
		quit(d, 2, -1);
	if (has_ext(av[1]) == 0)
		fd = strjoin_open(av);
	else
		fd = open(av[1], O_RDONLY);
	if (fd == -1)
		quit(d, 3, -1);
	save_input(d, fd);
	validate_input(d);
	get_header(d);
	if (is_name_comm_overlong(d) == 0)
		quit(d, 6, -1);
	validate_labels(d);
}
