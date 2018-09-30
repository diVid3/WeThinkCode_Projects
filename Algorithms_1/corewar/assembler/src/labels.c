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

/*
** has_lbl determines whether the line contains a label or not. This is used
** to build nodes that are not associated with labels, their label pointer thus
** being set to NULL.
*/

int		build_func_node(t_data *d, char *line, int has_lbl)
{
	char	**arr;

	arr = split(line);
	if (has_lbl)
		func_add_node_end(&(d->func), arr[1], arr[2], arr[0]);
	else
		func_add_node_end(&(d->func), arr[0], arr[1], NULL);
	ft_free_matrix((void **)arr);
	return (1);
}

void	fuse_label_func(t_data *d, char *label_line, char *func_line)
{
	char	*joined_str1;
	char	*joined_str2;
	char	*joined_func_line;
	char	**arr_label;
	char	**arr_func;

	arr_func = split(func_line);
	joined_str1 = ft_strjoin(arr_func[0], " ");
	joined_str2 = ft_strjoin(joined_str1, arr_func[1]);
	joined_func_line = ft_strdup(joined_str2);
	ft_memdel((void **)(&joined_str1));
	ft_memdel((void **)(&joined_str2));
	ft_free_matrix((void **)arr_func);
	arr_label = split(label_line);
	joined_str1 = ft_strjoin(arr_label[0], " ");
	joined_str2 = ft_strjoin(joined_str1, joined_func_line);
	ft_memdel((void **)(&joined_str1));
	ft_memdel((void **)(&joined_func_line));
	ft_free_matrix((void **)arr_label);
	build_func_node(d, joined_str2, 1);
	ft_memdel((void **)(&joined_str2));
}

void	switch_reader(t_data *d, t_input **label_node)
{
	int			swtch;
	char		*label_line;
	t_input		*tmp;

	swtch = 1;
	label_line = (*label_node)->line_ptr;
	tmp = (*label_node)->next;
	while (tmp)
	{
		if (is_name_cmd(tmp->line_ptr) || is_comment_cmd(tmp->line_ptr) ||
			is_comment(tmp->line_ptr))
			tmp = tmp->next;
		else if (is_label_func(tmp->line_ptr) || is_label(tmp->line_ptr))
			quit(d, 7, -1);
		else if (is_func(tmp->line_ptr))
		{
			swtch = 0;
			fuse_label_func(d, label_line, tmp->line_ptr);
			*label_node = tmp->next;
			break ;
		}
	}
	if (swtch == 1)
		quit(d, 8, -1);
}

void	build_func_list(t_data *d)
{
	t_input		*tmp;

	tmp = d->input;
	while (tmp)
	{
		if (is_name_cmd(tmp->line_ptr) || is_comment_cmd(tmp->line_ptr) ||
			is_comment(tmp->line_ptr))
			tmp = tmp->next;
		else if (is_label_func(tmp->line_ptr) &&
			build_func_node(d, tmp->line_ptr, 1))
			tmp = tmp->next;
		else if (is_func(tmp->line_ptr) && build_func_node(d, tmp->line_ptr, 0))
			tmp = tmp->next;
		else if (is_label(tmp->line_ptr))
			switch_reader(d, &tmp);
	}
}

void	validate_labels(t_data *d)
{
	build_func_list(d);
	has_dup_labels(d);
	if (has_val_lbl_refs(d) == 0)
		quit(d, 10, -1);
	if (d->func == NULL)
		quit(d, 11, -1);
}
