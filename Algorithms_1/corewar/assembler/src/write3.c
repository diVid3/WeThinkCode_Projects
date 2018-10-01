/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 06:31:24 by egenis            #+#    #+#             */
/*   Updated: 2018/10/01 06:31:26 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

int				calc_jump_up(t_func *tmp, char *ref_label)
{
	t_func		*tmp2;
	char		*norm_label;
	int			jmp_val;

	jmp_val = 0;
	tmp2 = tmp;
	while (tmp2)
	{
		if ((norm_label = ft_strcdup(tmp2->label, LABEL_CHAR)) &&
			ft_strcmp(norm_label, ref_label) == 0)
		{
			ft_memdel((void **)(&norm_label));
			return (jmp_val * -1);
		}
		ft_memdel((void **)(&norm_label));
		tmp2 = tmp2->prev;
		if (tmp2)
			jmp_val += tmp2->bytes_req;
	}
	ft_memdel((void **)(&norm_label));
	return (0);
}

int				calc_jump_down(t_func *tmp, char *ref_label)
{
	t_func		*tmp2;
	char		*norm_label;
	int			jmp_val;

	jmp_val = 0;
	tmp2 = tmp;
	while (tmp2)
	{
		if ((norm_label = ft_strcdup(tmp2->label, LABEL_CHAR)) &&
			ft_strcmp(norm_label, ref_label) == 0)
		{
			ft_memdel((void **)(&norm_label));
			return (jmp_val);
		}
		ft_memdel((void **)(&norm_label));
		jmp_val += tmp2->bytes_req;
		tmp2 = tmp2->next;
	}
	ft_memdel((void **)(&norm_label));
	return (0);
}

void			write_label_dir(t_func *tmp, char *arg, int type_size, int fd)
{
	char	**arr;
	int		jump_diff_up;
	int		jump_diff_down;

	arr = ft_strsplit(arg, LABEL_CHAR);
	jump_diff_up = calc_jump_up(tmp, arr[1]);
	jump_diff_down = calc_jump_down(tmp, arr[1]);
	if (jump_diff_up == jump_diff_down)
		write_num(0, type_size, fd);
	else if (jump_diff_up && jump_diff_down == 0)
		write_num(jump_diff_up, type_size, fd);
	else if (jump_diff_up == 0 && jump_diff_down)
		write_num(jump_diff_down, type_size, fd);
	ft_free_matrix((void **)arr);
}

void			write_dir(t_func *tmp, int fd, char *arg)
{
	int		nbr;
	int		type_size;

	if (arg[1] == LABEL_CHAR)
	{
		if (g_op_tab[is_func_valid(tmp->func)].dir_size == 1)
			type_size = 2;
		else
			type_size = 4;
		write_label_dir(tmp, arg, type_size, fd);
	}
	else
	{
		if (g_op_tab[is_func_valid(tmp->func)].dir_size == 1)
			type_size = 2;
		else
			type_size = 4;
		nbr = ft_atoi(arg + 1);
		write_num(nbr, type_size, fd);
	}
}
