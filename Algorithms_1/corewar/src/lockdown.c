/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lockdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:32:50 by dkaplan           #+#    #+#             */
/*   Updated: 2018/09/18 09:35:37 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "../libft/libft.h"

void	check(void)
{
	if (COMMENT_CHAR != '#' || LABEL_CHAR != ':' || DIRECT_CHAR != '%'
			|| SEPARATOR_CHAR != ',' || REG_NUMBER != 16
			|| LABEL_CHARS != "abcdefghijklmnopqrstuvwxyz_0123456789"
			|| NAME_CMD_STRING != ".name" || COMMENT_CMD_STRING != ".comment"
			|| T_REG != 1 || T_DIR != 2 || T_IND != 4 || COMMENT_LENGTH != 2048
			|| PROG_NAME_LENGTH != 128 || COREWAR_EXEC_MAGIC != 0xea83f3)
	{
		ft_putstr_fd("\e[0;31mPlease don't touch our source code. \
				Thank you.\n\e[0;37m", 2);
		exit(0);
	}
}
