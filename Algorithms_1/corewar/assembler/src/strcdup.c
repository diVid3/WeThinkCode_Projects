/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:45:58 by dkaplan           #+#    #+#             */
/*   Updated: 2018/09/14 11:05:38 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../asm.h>

char		*strcdup(char *str, char c)
{
	int		word_c;
	char	*dup;

	if (!str || !c)
		return (str);
	word_c = 0;
	while (str[word_c] != c && str[word_c])
		++word_c;
	dup = malloc(sizeof(char) * word_c);
	word_c = 0;
	while (str[word_c] != c && str[word_c])
	{
		dup[word_c] = str[word_c];
		++word_c;
	}
	dup[word_c] = 0;
	return (dup);
}
