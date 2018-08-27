#include "../inc/lem_in.h"

void		room_add_node_end(t_room **head, char *str, int start, int end)
{
	t_room			*node;
	t_room			*tmp;
	static int		index = 0;

	node = malloc(sizeof(t_room));
	node->room_name = ft_strdup(str);
	node->room_index = index;
	node->room_start = start;
	node->room_end = end;
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

void		room_free_list(t_room *head)
{
	t_room		*tmp;

	while (head)
	{
		tmp = head->next;
		ft_memdel((void **)(&(head->room_name)));
		ft_memdel((void **)(&head));
		head = tmp;
	}
}

void		room_print_list(t_room *room)
{
	t_room		*tmp;

	tmp = room;
	while (tmp)
	{
		ft_putchar('\n');
		ft_putstr("room name: ");
		ft_putstr(tmp->room_name);
		ft_putchar('\n');
		ft_putstr("room index: ");
		ft_putnbr(room->room_index);
		ft_putchar('\n');
		ft_putstr("room start: ");
		ft_putnbr(room->room_start);
		ft_putchar('\n');
		ft_putstr("room end: ");
		ft_putnbr(room->room_end);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}