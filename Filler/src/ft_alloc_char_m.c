/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_char_m.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:53:44 by egenis            #+#    #+#             */
/*   Updated: 2018/07/13 13:55:19 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_alloc_char_m(size_t rows, size_t cols)
{
	char		**arr;
	size_t		cntr_row;

	if (!rows || !cols)
		return (NULL);
	if ((arr = malloc(sizeof(char *) * rows + 1)) == NULL)
		return (NULL);
	cntr_row = 0;
	while (cntr_row < rows)
	{
		if ((arr[cntr_row] = malloc(sizeof(char) * cols + 1)) == NULL)
		{
			ft_del_matrix((void **)arr, rows);
			return (NULL);
		}
		ft_bzero(arr[cntr_row], cols + 1);
		++cntr_row;
	}
	arr[rows] = NULL;
	return (arr);
}
