/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 06:24:29 by egenis            #+#    #+#             */
/*   Updated: 2018/10/01 06:24:35 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

static unsigned int		split_calc_req(char *args, unsigned int dir_mult)
{
	unsigned int	ans;
	char			**arr;
	int				cntr;

	ans = 0;
	arr = ft_strsplit(args, SEPARATOR_CHAR);
	cntr = 0;
	while (arr[cntr])
		++cntr;
	while (--cntr >= 0)
		if (is_reg(arr[cntr]))
			ans += 1;
		else if (is_ind(arr[cntr]))
			ans += 2;
		else if (is_dir(arr[cntr]))
			ans += 2 * dir_mult;
	ft_free_matrix((void **)arr);
	return (ans);
}

void					calc_byte_reqs(t_data *d)
{
	t_func			*tmp;
	int				opcode;
	unsigned int	dir_mult;

	tmp = d->func;
	while (tmp)
	{
		tmp->bytes_req = 1;
		opcode = is_func_valid(tmp->func);
		if (g_op_tab[opcode].enc_byte == 1)
			tmp->bytes_req += 1;
		if (g_op_tab[opcode].dir_size == 1)
			dir_mult = 1;
		else
			dir_mult = 2;
		tmp->bytes_req += split_calc_req(tmp->args, dir_mult);
		tmp = tmp->next;
	}
}

void					do_calcs(t_data *d)
{
	calc_byte_reqs(d);
}
