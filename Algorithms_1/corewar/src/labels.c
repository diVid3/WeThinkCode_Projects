/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:14:40 by egenis            #+#    #+#             */
/*   Updated: 2018/09/18 13:14:43 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	build_func_node(t_data *d, char *line)
{
	char	**arr;

	arr = split(line);
}

void	switch_reader(t_data *d, t_input *lbl_node)
{
}

char	*fuse_label_func(char *label_line, char *func_line)
{
}

void	build_func_list(t_data *d)
{
	t_input		*tmp;
	char		*label_line;

	tmp = d->input;
	while (tmp)
	{
		if (is_label_func(tmp->line_ptr) == 1)
			build_func_node(d, tmp->line_ptr);
		else if (is_label(tmp->line_ptr) == 1)
		{
			label_line = tmp->line_ptr;
			while (tmp)
			{
				if (is_comment(tmp->line_ptr))
					tmp = tmp->next;
				else if (is_func(tmp->line_ptr) == 0)
					quit(d, 0);
			}
		}
		tmp = tmp->next;
	}
}

void	validate_labels(t_data *d)
{
}

/*
void	validate_labels(t_data *d)
{
	t_input		*tmp;

	tmp = d->input;
	while (tmp)
	{
		if (is_label_func(tmp->line_ptr) == 1)
			build_func_node(d, tmp->line_ptr);
		else if (is_label(tmp->line_ptr) == 1)
			switch_reader(d, tmp);
		tmp = tmp->next;
	}
}
*/
