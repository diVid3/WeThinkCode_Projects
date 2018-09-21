/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 06:24:40 by egenis            #+#    #+#             */
/*   Updated: 2018/09/20 06:24:43 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

char	*get_args_lbl(char *args)
{
	int		cntr;

	cntr = 0;
	while (args[cntr] != LABEL_CHAR)
		++cntr;
	return (strcdup(args + cntr + 1, SEPARATOR_CHAR));
}

int		has_args_lbl(char *args)
{
	int		cntr;

	cntr = 0;
	while (args[cntr])
	{
		if (args[cntr] == LABEL_CHAR)
			return (1);
		++cntr;
	}
	return (0);
}

int		find_label(t_data *d, char *args_ref)
{
	t_func		*tmp;
	char		*label_ref;

	tmp = d->func;
	while (tmp)
	{
		if (tmp->label)
		{
			label_ref = strcdup(tmp->label, LABEL_CHAR);
			if (ft_strcmp(label_ref, args_ref) == 0 &&
				!free_refs(label_ref, NULL))
				return (1);
			free_refs(label_ref, NULL);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		has_val_lbl_refs(t_data *d)
{
	t_func		*tmp;
	char		*args_ref;

	tmp = d->func;
	while (tmp)
	{
		if (has_args_lbl(tmp->args))
		{
			args_ref = get_args_lbl(tmp->args);
			if (find_label(d, args_ref) == 0)
				return (free_refs(args_ref, NULL));
			free_refs(args_ref, NULL);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	has_dup_labels(t_data *d)
{
	t_func		*label_node;
	t_func		*tmp;

	label_node = d->func;
	while (label_node)
	{
		if (label_node->label == NULL)
		{
			label_node = label_node->next;
			continue ;
		}
		tmp = label_node->next;
		while (tmp)
		{
			if (tmp->label == NULL)
			{
				tmp = tmp->next;
				continue ;
			}
			else if (ft_strcmp(label_node->label, tmp->label) == 0)
				quit(d, 1);
			tmp = tmp->next;
		}
		label_node = label_node->next;
	}
}
