/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 15:19:49 by egenis            #+#    #+#             */
/*   Updated: 2018/09/01 15:19:50 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		print_add_node_end(t_print **head, int stack_val)
{
	t_print		*node;
	t_print		*tmp;

	node = malloc(sizeof(t_print));
	node->index = stack_val;
	node->ant_count = 0;
	if (*head == NULL)
	{
		node->prev = NULL;
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
		node->prev = tmp;
	}
}

void		print_free_list(t_print *head)
{
	t_print		*tmp;

	while (head)
	{
		tmp = head->next;
		ft_memdel((void **)(&head));
		head = tmp;
	}
}
