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

/*
** This function is used to check if prev node linkage was done correctly.
*/

void		print_rev_print(t_print *head)
{
	t_print		*tmp;

	if (head == NULL)
		return ;
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		ft_putnbr(tmp->index);
		ft_putchar('\n');
		tmp = tmp->prev;
	}
}
