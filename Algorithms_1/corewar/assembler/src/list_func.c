/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:25:52 by egenis            #+#    #+#             */
/*   Updated: 2018/09/18 13:26:04 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

/*
static void	link_if_head_null(t_func **h, t_func **node)
{
	(*node)->prev = NULL;
	(*node)->next = NULL;
	*h = *node;
}

static void	link_if_head_non_null(t_func **h, t_func **node, t_func **tmp)
{
}
*/

void		func_add_node_end(t_func **h, char *func, char *args, char *label)
{
	t_func		*node;
	t_func		*tmp;
	static int	index = 1;

	node = malloc(sizeof(t_func));
	node->func = func;
	node->args = args;
	node->label = label;
	node->index = index;
	if (*h == NULL)
	{
		node->prev = NULL;
		node->next = NULL;
		*h = node;
	}
	else
	{
		tmp = *h;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		node->next = NULL;
		node->prev = tmp;
	}
	++index;
}

void		func_print_list(t_func *head)
{
	t_func		*tmp;

	tmp = head;
	while (tmp)
	{
		ft_putstr("index : ");
		ft_putnbr(tmp->index);
		ft_putchar('\n');
		ft_putstr("label : ");
		ft_putstr(tmp->label);
		ft_putchar('\n');
		ft_putstr("func  : ");
		ft_putstr(tmp->func);
		ft_putchar('\n');
		ft_putstr("args  : ");
		ft_putstr(tmp->args);
		ft_putchar('\n');
		ft_putstr("b_req : ");
		ft_putnbr(tmp->bytes_req);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void		func_free_list(t_func *head)
{
	t_func		*tmp;

	while (head)
	{
		tmp = head->next;
		ft_memdel((void **)(&(head->func)));
		ft_memdel((void **)(&(head->args)));
		ft_memdel((void **)(&(head->label)));
		ft_memdel((void **)(&head));
		head = tmp;
	}
}
