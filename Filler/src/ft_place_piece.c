/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:06:10 by egenis            #+#    #+#             */
/*   Updated: 2018/07/17 07:21:55 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include <stdio.h>

static _Bool	ft_out_of_bounds(t_input *data, int map_row, int map_col)
{
	if (map_row + data->p_rws > data->mp_rws || 
		map_col + data->p_cls > data->mp_cls)
		return (0);
	return (1);
}

static _Bool	ft_can_place_p1(t_input *d, int m_rw, int m_cl)
{
	int		p_rw;
	int		p_cl;

	d->overlaps = 0;
	if (ft_out_of_bounds(d, m_rw, m_cl) == 0)
		return (0);
	p_rw = 0;
	while (p_rw < d->p_rws)
	{
		p_cl = 0;
		while (p_cl < d->p_cls)
		{
			if ((d->mp[m_rw + p_rw][m_cl + p_cl] == 'x' ||
				d->mp[m_rw + p_rw][m_cl + p_cl] == 'X') &&
				d->p[p_rw][p_cl] == '*')
				return (0);
			if ((d->mp[m_rw + p_rw][m_cl + p_cl] == 'o' ||
				d->mp[m_rw + p_rw][m_cl + p_cl] == 'O') &&
				d->p[p_rw][p_cl] == '*')
				++d->overlaps;
			++p_cl;
		}
		++p_rw;
	}
	return ((d->overlaps == 1) ? 1 : 0);
}

static _Bool	ft_can_place_p2(t_input *d, int m_rw, int m_cl)
{
	int		p_rw;
	int		p_cl;

	d->overlaps = 0;
	if (ft_out_of_bounds(d, m_rw, m_cl) == 0)
		return (0);
	p_rw = 0;
	while (p_rw < d->p_rws)
	{
		p_cl = 0;
		while (p_cl < d->p_cls)
		{
			if ((d->mp[m_rw + p_rw][m_cl + p_cl] == 'o' ||
				d->mp[m_rw + p_rw][m_cl + p_cl] == 'O') &&
				d->p[p_rw][p_cl] == '*')
				return (0);
			if ((d->mp[m_rw + p_rw][m_cl + p_cl] == 'x' ||
				d->mp[m_rw + p_rw][m_cl + p_cl] == 'X') &&
				d->p[p_rw][p_cl] == '*')
				++d->overlaps;
			++p_cl;
		}
		++p_rw;
	}
	return ((d->overlaps == 1) ? 1 : 0);
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
	//sleep(1);
	if (move)
	{
		dprintf(2, "First avaiable move is row -- %d ", move->row);
		ft_putnbr(move->row);
	}
	else
		ft_putnbr(0);
	ft_putchar(' ');
	if (move)
	{
		dprintf(2, "col -- %d\n", move->col);
		ft_putnbr(move->col);
	}
	else
		ft_putnbr(0);
	ft_putchar('\n');
	ft_free_list(move);
}
