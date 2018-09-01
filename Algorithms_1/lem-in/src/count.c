/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 08:56:07 by egenis            #+#    #+#             */
/*   Updated: 2018/09/01 08:56:32 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		count_pluses(char *str)
{
	int		cntr;
	int		pluses;

	cntr = 0;
	pluses = 0;
	while (str[cntr])
	{
		if (str[cntr] == '+')
			++pluses;
		++cntr;
	}
	return (pluses);
}

int		count_dashes_c(char *str, char c)
{
	int		cntr;
	int		dashes;

	cntr = 0;
	dashes = 0;
	while (str[cntr] && str[cntr] != c)
	{
		if (str[cntr] == '-')
			++dashes;
		++cntr;
	}
	return (dashes);
}

int		count_dashes(char *str)
{
	int		cntr;
	int		dashes;

	cntr = 0;
	dashes = 0;
	while (str[cntr])
	{
		if (str[cntr] == '-')
			++dashes;
		++cntr;
	}
	return (dashes);
}

int		count_spaces(char *str)
{
	int		cntr;
	int		spaces;

	cntr = 0;
	spaces = 0;
	while (str[cntr])
	{
		if (str[cntr] == ' ')
			++spaces;
		++cntr;
	}
	return (spaces);
}

int		count_whitespaces(char *str)
{
	int		cntr;
	int		whitespaces;

	cntr = 0;
	whitespaces = 0;
	while (str[cntr])
	{
		if (str[cntr] >= 9 && str[cntr] <= 13)
			++whitespaces;
		++cntr;
	}
	return (whitespaces);
}
