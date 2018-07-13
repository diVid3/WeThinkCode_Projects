/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_matrix_nul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:14:17 by egenis            #+#    #+#             */
/*   Updated: 2018/07/13 16:14:43 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static	void	ft_del_matrix_nul(void **arr)
{
	size_t		cntr;

	if (!arr)
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
