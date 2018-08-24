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

int		is_link(char *str)
{
	int		cntr;

	cntr = 0;
	return (1);
}

int		is_room(char *str)
{
	int		cntr;

	if (is_comment(str))
		return (0);
	if (is_command(str))
		return (0);
	cntr = 0;
	while (str[cntr] && str[cntr] != ' ')
		++cntr;
	return (1);
}
