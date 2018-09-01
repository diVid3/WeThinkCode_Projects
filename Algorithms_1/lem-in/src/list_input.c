/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 08:58:01 by egenis            #+#    #+#             */
/*   Updated: 2018/09/01 08:58:08 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		input_add_node_end(t_input **head, char *line)
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

void		input_free_list(t_input *head)
{
	t_input		*tmp;

	while (head)
	{
		tmp = head->next;
		ft_memdel((void **)(&(head->line_ptr)));
		ft_memdel((void **)(&head));
		head = tmp;
	}
}

void		input_print_list(t_input *input)
{
	t_input		*tmp;

	tmp = input;
	while (tmp)
	{
		ft_putstr(tmp->line_ptr);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
