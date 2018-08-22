/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:13:11 by egenis            #+#    #+#             */
/*   Updated: 2018/08/20 16:53:18 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		ft_input_add_node_end(t_move **head, char *line)
{
	t_input		*node;
	t_input		*tmp;

	node = malloc(sizeof(t_input));
	node->line_ptr = line;
	if (*head == NULL)
	{
		node->next = NULL;
		*head = node;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		node->next = NULL;
	}
}

void		ft_input_free_list(t_input *head)
{
	t_input		*tmp;

	while (head)
	{
		tmp = head->next;
		ft_memdel((void **)(&(head->line_ptr)));
		ft_memdel((void **)(&head));
		head = tmp;
	}
	return ;
}
