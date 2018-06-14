/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 10:26:11 by egenis            #+#    #+#             */
/*   Updated: 2018/06/14 12:17:06 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*ptr;
	t_list		*new;

	if (!lst || !f)
		return (NULL);
	ptr = lst;
	while (ptr)
	{
		tmp = (*f)(ptr);
		ft_lstadd_back(&new, ft_lstnew(tmp->content, tmp->content_size));
		ptr = ptr->next;
	}
	return (new);
}
