/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 10:58:36 by egenis            #+#    #+#             */
/*   Updated: 2018/09/18 10:58:38 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_matrix(void **arr)
{
	size_t		cntr;

	if (arr == NULL)
		return ;
	cntr = 0;
	while (arr[cntr])
	{
		free(arr[cntr]);
		arr[cntr] = NULL;
		++cntr;
	}
	free(arr);
	arr = NULL;
	return ;
}
