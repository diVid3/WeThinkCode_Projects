/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 13:19:46 by egenis            #+#    #+#             */
/*   Updated: 2018/08/24 13:19:47 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		is_comment(char *str)
{
	if (str[0] && str[0] == '#' && str[1] != '#')
		return (1);
	return (0);
}

int		is_command(char *str)
{
	if (str[0] && str[1] && str[0] == '#' && str[1] == '#' && str[2] != '#')
		return (1);
	return (0);
}

/*
** is_start is a type of command.
*/

int		is_start(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len == 7 && is_command(str))
		if (str[2] == 's' && str[3] == 't' && str[4] == 'a' &&
			str[5] == 'r' && str[6] == 't')
			return (1);
	return (0);
}

/*
** is_end is a type of command.
*/

int		is_end(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len == 5 && is_command(str))
		if (str[2] == 'e' && str[3] == 'n' && str[4] == 'd')
			return (1);
	return (0);
}
