/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:06:29 by egenis            #+#    #+#             */
/*   Updated: 2018/05/18 15:15:59 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_bzero(void *s, size_t n)
{
	size_t cntr;

	cntr = 0;
	while (cntr < n)
	{
		((unsigned char *)s)[cntr] = 0;
		++cntr;
	}
}
