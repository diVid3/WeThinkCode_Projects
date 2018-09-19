/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:10:45 by egenis            #+#    #+#             */
/*   Updated: 2018/09/18 09:10:47 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

/*
** A line that contains only whitespace, i.e. not a completely empty line,
** is still valid. The check for null below accommodates that.
*/

int		is_comment(char *str)
{
	int		cntr;

	cntr = 0;
	while (str[cntr] && (str[cntr] == ' ' || str[cntr] == 9 ||
			str[cntr] == 11 || str[cntr] == 12 || str[cntr] == 13))
		++cntr;
	if (str[cntr] == COMMENT_CHAR || str[cntr] == '\0')
		return (1);
	return (0);
}

/*
** Bad naming due to op.h having bad macros.
*/

int		is_label_chars(char c)
{
	char	*str;
	int		cntr;

	str = LABEL_CHARS;
	cntr = -1;
	while (str[++cntr])
		if (c == str[cntr])
			return (1);
	return (0);
}

int		free_return(char *str_no_cmmnt, char **arr, int cntr)
{
	ft_memdel((void **)(&str_no_cmmnt));
	ft_del_matrix((void **)arr, cntr);
	return (0);
}

int		is_label(char *str)
{
	int		cntr;
	int		cntr2;
	char	*str_no_cmmnt;
	char	**arr;

	str_no_cmmnt = strcdup(str, COMMENT_CHAR);
	arr = split(str_no_cmmnt);
	cntr = 0;
	while (arr[cntr])
		++cntr;
	if (cntr != 1)
		if (free_return(str_no_cmmnt, arr, cntr) == 0)
			return (0);
	cntr2 = -1;
	while (arr[0][++cntr2] && arr[0][cntr2] != LABEL_CHAR)
		if (is_label_chars(arr[0][cntr2]) == 0)
			if (free_return(str_no_cmmnt, arr, cntr) == 0)
				return (0);
	if (arr[0][cntr2] != LABEL_CHAR || arr[0][++cntr2] != '\0' ||
		(arr[0][0] == LABEL_CHAR && arr[0][1] == '\0'))
		if (free_return(str_no_cmmnt, arr, cntr) == 0)
			return (0);
	free_return(str_no_cmmnt, arr, cntr);
	return (1);
}

int		is_label_func(char *str)
{
	int		cntr;
	char	*str_no_cmmnt;
	char	*joined_str1;
	char	*joined_str2;
	char	**arr;

	str_no_cmmnt = strcdup(str, '#');
	arr = split(str_no_cmmnt);
	cntr = 0;
	while (arr[cntr])
		++cntr;
	if (cntr != 3)
		if (free_return(str_no_cmmnt, arr, cntr) == 0)
			return (0);
	joined_str1 = ft_strjoin(arr[1], " ");
	joined_str2 = ft_strjoin(joined_str1, arr[2]);
	ft_memdel((void **)(&joined_str1));
	if (is_label(arr[0]) == 0 || is_func(joined_str2) == 0)
		if (free_return(str_no_cmmnt, arr, cntr) == 0)
		{
			ft_memdel((void **)(&joined_str2));
			return (0);
		}
	ft_memdel((void **)(&joined_str2));
	return (1);
}
