/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:11:49 by egenis            #+#    #+#             */
/*   Updated: 2018/09/18 09:11:51 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

int		strclen(char *str)
{
	int		cntr;

	cntr = 0;
	while (str[cntr] && str[cntr] != ' ' && str[cntr] != 9 &&
		str[cntr] != 11 && str[cntr] != 12 && str[cntr] != 13)
		++cntr;
	return (cntr);
}

int		count_words(char *str)
{
	int		cntr;
	int		word_count;
	_Bool	swtch;

	cntr = 0;
	word_count = 0;
	while (str[cntr])
	{
		if (str[cntr] != ' ' && str[cntr] != 9 && str[cntr] != 11 &&
			str[cntr] != 12 && str[cntr] != 13 && swtch == 0)
		{
			++word_count;
			swtch = 1;
		}
		if (str[cntr] == ' ' || str[cntr] == 9 || str[cntr] == 11 ||
			str[cntr] == 12 || str[cntr] == 13)
			swtch = 0;
		++cntr;
	}
	return (word_count);
}

char	*nxt_addr(char *str, _Bool *word_first)
{
	int		cntr;
	char	*addr;

	cntr = 0;
	addr = 0;
	if (*word_first)
	{
		*word_first = 0;
		return (str);
	}
	while (str[cntr] && str[cntr] != ' ' && str[cntr] != 9 &&
		str[cntr] != 11 && str[cntr] != 12 && str[cntr] != 13)
		++cntr;
	while (str[cntr] && (str[cntr] == ' ' || str[cntr] == 9 ||
		str[cntr] == 11 || str[cntr] == 12 || str[cntr] == 13))
		++cntr;
	addr = &str[cntr];
	return (addr);
}

char	*dup_str(char *src)
{
	int		len;
	char	*str;
	int		cntr;

	len = strclen(src);
	str = malloc(sizeof(char) * len + 1);
	cntr = 0;
	while (cntr < len)
	{
		str[cntr] = src[cntr];
		++cntr;
	}
	str[len] = '\0';
	return (str);
}

char	**split(char *str)
{
	int		word_count;
	int		cntr;
	char	*word_addr;
	char	**ar;
	_Bool	word_first;

	if (str == NULL)
		return (NULL);
	word_count = count_words(str);
	word_first = (*str != ' ' && *str != 9 && *str != 11 &&
		*str != 12 && *str != 13) ? 1 : 0;
	ar = malloc(sizeof(char *) * word_count + 1);
	word_addr = str;
	cntr = 0;
	while (cntr < word_count)
	{
		word_addr = nxt_addr(word_addr, &word_first);
		ar[cntr] = dup_str(word_addr);
		++cntr;
	}
	ar[word_count] = NULL;
	return (ar);
}
