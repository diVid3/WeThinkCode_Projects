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
