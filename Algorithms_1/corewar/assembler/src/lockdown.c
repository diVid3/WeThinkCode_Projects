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

#include "../inc/asm.h"

void	macro_check(t_data *d)
{
	if (COMMENT_CHAR != '#' || LABEL_CHAR != ':' || DIRECT_CHAR != '%' ||
		SEPARATOR_CHAR != ',' || REG_NUMBER != 16 ||
		ft_strcmp(LABEL_CHARS, "abcdefghijklmnopqrstuvwxyz_0123456789") ||
		ft_strcmp(NAME_CMD_STRING, ".name") ||
		ft_strcmp(COMMENT_CMD_STRING, ".comment") ||
		T_REG != 1 || T_DIR != 2 || T_IND != 4 || COMMENT_LENGTH != 2048 ||
		PROG_NAME_LENGTH != 128 || COREWAR_EXEC_MAGIC != 0xea83f3)
		quit(d, 1, -1);
}
