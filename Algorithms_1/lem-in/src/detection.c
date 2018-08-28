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

int		is_start(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len == 7 && str[0] == '#' && str[1] == '#')
		if (str[2] == 's' && str[3] == 't' && str[4] == 'a' &&
			str[5] == 'r' && str[6] == 't')
			return (1);
	return (0);
}

int		is_end(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len == 5 && str[0] == '#' && str[1] == '#')
		if (str[2] == 'e' && str[3] == 'n' && str[4] == 'd')
			return (1);
	return (0);
}

int		is_rand_command(char *str)
{
	if (is_start(str))
		return (0);
	if (is_end(str))
		return (0);
	if (str[0] && str[1] && str[0] == '#' && str[1] == '#')
		return (1);
	return (0);
}
