/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:00:44 by egenis            #+#    #+#             */
/*   Updated: 2018/06/05 06:23:59 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		ans;

	if (!s1 || !s2)
		return (0);
	ans = ft_strncmp(s1, s2, n);
	if (ans == 0)
		return (1);
	return (0);
}
