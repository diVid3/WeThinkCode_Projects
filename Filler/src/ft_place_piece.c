/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:06:10 by egenis            #+#    #+#             */
/*   Updated: 2018/07/16 15:48:11 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static _Bool	ft_can_place_p1(t_input *data, int map_row, int map_col)
{
	int		overlaps;
	int		p_row;
	int		p_col;

	overlaps = 0;
	if (map_row + data->piece_rows > data->map_rows || 
		map_col + data->piece_cols > data->map_cols)
		return (0);
	p_row = 0;
	while (p_row < data->piece_rows)
	{
		p_col = 0;
		while (p_col < data->piece_cols)
		{
			if ((data->map[map_row + p_row][map_col + p_col] == 'o' ||
				data->map[map_row + p_row][map_col + p_col] == 'O') &&
				(data->map[map_row + p_row][map_col + p_col] != 'x' ||
				data->map[map_row + p_row][map_col + p_col] != 'X') &&
				data->piece[p_row][p_col] == '*')
				++overlaps;
			++p_col;
		}
		++p_row;
	}
	return ((overlaps == 1) ? 1 : 0);
}

static _Bool	ft_can_place_p2(t_input *data, int map_row, int map_col)
{
	int		overlaps;
	int		p_row;
	int		p_col;

	overlaps = 0;
	if (map_row + data->piece_rows > data->map_rows || 
		map_col + data->piece_cols > data->map_cols)
		return (0);
	p_row = 0;
	while (p_row < data->piece_rows)
	{
		p_col = 0;
		while (p_col < data->piece_cols)
		{
			if ((data->map[map_row + p_row][map_col + p_col] == 'x' ||
				data->map[map_row + p_row][map_col + p_col] == 'X') &&
				(data->map[map_row + p_row][map_col + p_col] != 'o' ||
				data->map[map_row + p_row][map_col + p_col] != 'O') &&
				data->piece[p_row][p_col] == '*')
				++overlaps;
			++p_col;
		}
		++p_row;
	}
	return ((overlaps == 1) ? 1 : 0);
}

static void		ft_add_node_back(t_move **head, int map_row, int map_col)
{
	t_move		*node;
	t_move		*tmp;

	node = malloc(sizeof(t_move));
	node->row = map_row;
	node->col = map_col;
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

/*
static void		ft_add_node(t_move **head, int map_row, int map_col)
{
	t_move		*node;

	node = malloc(sizeof(t_move));
	node->row = map_row;
	node->col = map_col;
	if (*head == NULL)
		node->next = NULL;
	else
		node->next = *head;
	*head = node;
}
*/

static t_move		*ft_make_move_list(t_input *data)
{
	t_move		*head;
	int			cntr_row;
	int			cntr_col;

	head = NULL;
	cntr_row = 0;
	while (cntr_row < data->map_rows)
	{
		cntr_col = 0;
		while (cntr_col < data->map_cols)
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

static void		ft_free_list(t_move *head)
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

void			ft_place_piece(t_input *data)
{
	t_move		*move;

	move = ft_make_move_list(data);
	sleep(1);
	if (move)
		ft_putnbr(move->row);
	else
		ft_putnbr(0);
	ft_putchar(' ');
	if (move)
		ft_putnbr(move->col);
	else
		ft_putnbr(0);
	ft_putchar('\n');
	ft_free_list(move);
}
