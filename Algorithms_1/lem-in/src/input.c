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

void		get_input(t_data *data)
{
	t_input		*input;
	int			read_b;
	char		*line;

	input = NULL;
	read_b = 1;
	while (read_b)
	{
		read_b = get_next_line(0, &line);
		if (read_b)
			input_add_node_end(&input, line);
	}
	data->input = input;
}