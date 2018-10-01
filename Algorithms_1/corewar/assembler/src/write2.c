/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egenis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 06:31:15 by egenis            #+#    #+#             */
/*   Updated: 2018/10/01 06:31:17 by egenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void			write_num(int nbr, int type_size, int fd)
{
	int				cntr;
	int				stop_val;
	unsigned char	*ptr;

	ptr = (unsigned char *)(&nbr);
	ptr += (type_size == 2) ? 1 : 3;
	stop_val = (type_size == 2) ? 2 : 4;
	cntr = -1;
	while (++cntr < stop_val)
	{
		write(fd, ptr, 1);
		--ptr;
	}
}

unsigned char	ret_enc_bits(char *field, int field_nr)
{
	if (is_reg(field) == 1 && field_nr == 1)
		return (64);
	if (is_dir(field) == 1 && field_nr == 1)
		return (128);
	if (is_ind(field) == 1 && field_nr == 1)
		return (192);
	if (is_reg(field) == 1 && field_nr == 2)
		return (16);
	if (is_dir(field) == 1 && field_nr == 2)
		return (32);
	if (is_ind(field) == 1 && field_nr == 2)
		return (48);
	if (is_reg(field) == 1 && field_nr == 3)
		return (4);
	if (is_dir(field) == 1 && field_nr == 3)
		return (8);
	if (is_ind(field) == 1 && field_nr == 3)
		return (12);
	return (0);
}

void			write_enc(t_func *tmp, int fd)
{
	char			**arr;
	int				cntr;
	unsigned char	enc;

	if (g_op_tab[is_func_valid(tmp->func)].enc_byte == 0)
		return ;
	arr = ft_strsplit(tmp->args, SEPARATOR_CHAR);
	enc = 0;
	cntr = -1;
	while (arr[++cntr])
		enc += ret_enc_bits(arr[cntr], cntr + 1);
	write(fd, &enc, 1);
	ft_free_matrix((void **)arr);
}

void			write_reg(char *reg, int fd)
{
	char			*ptr;
	int				reg_nr;
	unsigned char	*reg_ptr;

	ptr = reg + 1;
	reg_nr = ft_atoi(ptr);
	reg_ptr = (unsigned char *)(&reg_nr);
	write(fd, reg_ptr, 1);
}

void			write_args(t_data *d, t_func *tmp, int fd)
{
	char		**arr;
	int			cntr;

	(void)d;
	arr = ft_strsplit(tmp->args, SEPARATOR_CHAR);
	cntr = -1;
	while (arr[++cntr])
	{
		if (is_reg(arr[cntr]) == 1)
			write_reg(arr[cntr], fd);
		if (is_dir(arr[cntr]) == 1)
			write_dir(tmp, fd, arr[cntr]);
		if (is_ind(arr[cntr]) == 1)
			write_ind(tmp, fd, arr[cntr]);
	}
	ft_free_matrix((void **)arr);
}
