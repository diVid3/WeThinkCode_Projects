/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_move_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:14:39 by egenis            #+#    #+#             */
/*   Updated: 2018/07/17 12:44:22 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void		ft_add_node_back(t_move **head, int map_row, int map_col)
{
	t_move		*node;
	t_move		*tmp;

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

t_move		*ft_make_move_list(t_input *data)
{
	t_move		*head;
	int			cntr_row;
	int			cntr_col;

	head = NULL;
	cntr_row = 0;
	while (cntr_row < data->mp_rws)
	{
		cntr_col = 0;
		while (cntr_col < data->mp_cls)
		{
			if (data->player_num == 1)
				if (ft_can_place_p1(data, cntr_row, cntr_col) == 1)
					ft_add_node_back(&head, cntr_row, cntr_col);
			if (data->player_num == 2)
				if (ft_can_place_p2(data, cntr_row, cntr_col) == 1)
					ft_add_node_back(&head, cntr_row, cntr_col);
			++cntr_col;
		}
		++cntr_row;
	}
	return (head);
}
