/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_arr2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 07:31:43 by egenis            #+#    #+#             */
/*   Updated: 2018/07/13 10:46:35 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
//#include <stdio.h>

/*
void		ft_del_arr2d(char **arr, size_t row_count)
{
	size_t		cntr;

	if (!row_count || !arr)
		return ;
	cntr = 0;
	while (cntr < row_count && arr[cntr])
	{
		free(arr[cntr]);
		arr[cntr] = NULL;
		++cntr;
	}
	free(arr);
	arr = NULL;
	return ;
}
*/

char		**ft_alloc_arr2d(size_t rows, size_t cols)
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
			ft_del_arr2d(arr, rows);
			return (NULL);
		}
		ft_bzero(arr[cntr_row], cols + 1);
		++cntr_row;
	}
	arr[rows] = NULL;
	return (arr);
}

/*
void		print_arr2d(char **arr, size_t row_count)
{
	size_t		cntr;

	if (!row_count || !arr)
		return ;
	cntr = 0;
	while (cntr < row_count && arr[cntr])
	{
		printf("%s\n", arr[cntr]);
		++cntr;
	}
	return ;
}

int			main(int ac, char **av)
{
	char	**arr;

	(void)ac;
	(void)av;
	arr = ft_alloc_arr2d(3, 6);

	arr[0][0] = 'H';
	arr[0][1] = 'E';
	arr[0][2] = 'L';
	arr[0][3] = 'L';
	arr[0][4] = 'O';
	arr[0][5] = '\0';

	arr[1][0] = 'T';
	arr[1][1] = 'H';
	arr[1][2] = 'E';
	arr[1][3] = 'R';
	arr[1][4] = 'E';
	arr[1][5] = '\0';

	arr[2][0] = 'B';
	arr[2][1] = 'U';
	arr[2][2] = 'D';
	arr[2][3] = 'D';
	arr[2][4] = 'Y';
	arr[2][5] = '\0';

	print_arr2d(arr, 3);
	ft_del_arr2d(arr, 3);
	//sleep(60);
	return (0);
}
*/
