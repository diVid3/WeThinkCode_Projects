/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:11:25 by egenis            #+#    #+#             */
/*   Updated: 2018/09/18 09:11:26 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void		input_add_node_end(t_input **head, char *line)
{
	t_input		*node;
	t_input		*tmp;
	static int	index = 1;

	node = malloc(sizeof(t_input));
	node->line_ptr = line;
	node->line_nbr = index;
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
	++index;
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
