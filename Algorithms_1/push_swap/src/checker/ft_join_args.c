/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 07:13:27 by egenis            #+#    #+#             */
/*   Updated: 2018/08/10 06:57:43 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker/checker.h"

char		*ft_join_args(char **av)
{
	int		cntr;
	char	*str;
	char	*tmp;

	cntr = 2;
	if (!av[1])
		return (NULL);
	if (ft_strcmp(av[1], "-v") == 0)
	{
		cntr = 3;
		str = ft_strdup(av[2]);
	}
	else
		str = ft_strdup(av[1]);
	while (av[cntr])
	{
		tmp = ft_strjoin(str, " ");
		ft_memdel((void **)(&str));
		str = ft_strjoin(tmp, av[cntr]);
		ft_memdel((void **)(&tmp));
		++cntr;
	}
	return (str);
}
