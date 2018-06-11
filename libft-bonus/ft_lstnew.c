
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	if (!content)
	{
		head->content = NULL;
		head->content_size = 0;
	}
	else
	{
		head->content = (void *)content;
		head->content_size = content_size;
	}
	head->next = NULL;
	return (head);
}