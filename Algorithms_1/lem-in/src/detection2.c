/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 14:45:28 by egenis            #+#    #+#             */
/*   Updated: 2018/08/24 14:45:29 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"
//#include <stdio.h>

int				is_ants(char *str)
{
	int		cntr;
	int		digits;
	int		len;

	if (count_whitespaces(str) > 0 || count_spaces(str) != 0 ||
		count_dashes(str) != 0 || count_pluses(str) >= 2 ||
		(count_pluses(str) == 1 && *str != '+'))
		return (0);
	digits = 0;
	if (*str == '+')
		cntr = 0;
	else
		cntr = -1;
	while (str[++cntr])
		if (str[cntr] >= '0' && str[cntr] <= '9')
			++digits;
	len = (*str == '+') ? ft_strlen(str) - 1 : ft_strlen(str);
	if (digits != len || ft_is_int(str) == 0 || ft_atoi(str) <= 0)
		return (0);
	return (1);
}

static int		is_coordinate(char *str, char c)
{
	int		cntr;
	int		num_count;

	if (*str == '-' || *str == '+')
		cntr = 0;
	else
		cntr = -1;
	num_count = 0;
	while (str[++cntr] && (str[cntr] >= '0' && str[cntr] <= '9') &&
		str[cntr] != c)
		if (str[cntr] >= '0' && str[cntr] <= '9')
			++num_count;
	if ((str[cntr] != '\0' && str[cntr] != c) || num_count == 0)
		return (0);
	return (1);
}

int				is_room(char *str)
{
	int		cntr;

	if (count_whitespaces(str) > 0 || count_spaces(str) != 2 ||
		count_dashes(str) != 0 || ft_strclen(str, ' ') == 0 || 
		is_comment(str) || is_command(str))
		return (0);
	cntr = 0;
	while (str[cntr] && ft_isprint((int)(str[cntr])) && str[cntr] != ' ')
		++cntr;
	if (str[cntr] != ' ')
		return (0);
	++cntr;
	if (is_coordinate(str + cntr, ' ') == 0)
		return (0);
	while (str[cntr] && str[cntr] != ' ')
		++cntr;
	++cntr;
	if (is_coordinate(str + cntr, ' ') == 0)
		return (0);
	return (1);
}

int				is_link(char *str)
{
	int		cntr;

	if (count_whitespaces(str) > 0 || count_spaces(str) > 0 ||
		count_dashes(str) != 1 || ft_strclen(str, '-') == 0 ||
		is_comment(str) || is_command(str))
		return (0);
	cntr = 0;
	while (str[cntr] && ft_isprint((int)(str[cntr])) && str[cntr] != '-')
		++cntr;
	if (str[cntr] != '-')
		return (0);
	++cntr;
	if (ft_strclen(str + cntr, '\0') == 0 || is_comment(str + cntr) ||
		is_command(str + cntr))
		return (0);
	if (ft_strclen(str, '-') == ft_strclen(str + cntr, '\0'))
		if (ft_strncmp(str, str + cntr, ft_strclen(str, '-')) == 0)
			return (0);
	while (str[cntr] && ft_isprint((int)(str[cntr])))
		++cntr;
	if (str[cntr] != '\0')
		return (0);
	return (1);
}

/*
int				main(int ac, char **av)
{
	(void)ac;
	printf("is_link for av[1] returns %d\n", is_link(av[1]));
	printf("is_room for av[2] returns %d\n", is_room(av[2]));
	printf("is_ants for av[3] returns %d\n", is_ants(av[3]));
	return (0);
}
*/
