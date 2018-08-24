/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 06:42:01 by egenis            #+#    #+#             */
/*   Updated: 2018/08/24 07:39:36 by egenis           ###   ########.fr       */
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

void		get_input(t_data *d)
{
	int			read_b;
	char		*line;

	read_b = 1;
	while (read_b)
	{
		if ((read_b = get_next_line(0, &line)) == 0)
			quit(d, 1);
		if (d->read_ants == 0)
			get_ants(d, line);
		else if (d->read_rooms == 0)
			get_rooms(d, line);
		else if (d->read_links == 0)
			get_links(d, line);
		input_add_node_end(&(d->input), line);
	}
}
