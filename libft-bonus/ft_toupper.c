/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:40:34 by egenis            #+#    #+#             */
/*   Updated: 2018/05/30 14:06:06 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	t_uchar	ch;

	ch = (t_uchar)c;
	if (c < 'a' || c > 'z')
		return (c);
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	return (c);
}
