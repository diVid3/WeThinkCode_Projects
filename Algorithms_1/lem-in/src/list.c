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

void		ft_add_node_back(t_move **head)
{
	t_input		*node;
	t_input		*tmp;

	node = malloc(sizeof(t_move));
	node->row = map_row;
	node->col = map_col;
	node->rating = 2147483647;
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

void		ft_free_list(t_move *head)
{
	t_move		*tmp;

	while (head)
	{
		tmp = head->next;
		ft_memdel((void **)(&head));
		head = tmp;
	}
	return ;
}
