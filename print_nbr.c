/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:43:20 by yecsong           #+#    #+#             */
/*   Updated: 2022/07/12 14:48:08 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_num(t_flag *flags, int *cnt, unsigned long long num)
{
	if (num == 0)
	{
		ft_putchar('0', cnt);
		return ;
	}
	else if (flags->type == 'u' || flags->type == 'X' || flags->type == 'x')
		print_recur_num_u(flags, cnt, num);
	else
		print_recur_num(flags, cnt, num);
}

void	pre_0x(t_flag *flags, int *cnt, unsigned long long num)
{
	if (flags->type == 'p')
	{
		ft_putstr("0x", cnt);
		flags->width -= 2;
	}
	else if (flags->pound == 1 && flags->type == 'x' && num != 0)
	{
		ft_putstr("0x", cnt);
		flags->width -= 2;
	}
	else if (flags->pound == 1 && flags->type == 'X' && num != 0)
	{
		ft_putstr("0X", cnt);
		flags->width -= 2;
	}
}

void	put_left(t_flag *flags, int *cnt, int nbr_len, unsigned long long num)
{
	if (flags->minus != 1)
		return ;
	if (flags->pre == -1)
		flags->pre = 0;
	if (flags->pre >= flags->width)
	{	
		put_sign(flags, cnt);
		put_blank_zero(flags->pre - nbr_len, '0', cnt, flags);
	}
	else if (flags->width > flags->pre)
	{
		if (flags->nbr_sign == -1 || flags->plus == 1)
			flags->width--;
		put_sign(flags, cnt);
		put_blank_zero(flags->pre - nbr_len, '0', cnt, flags);
	}
	pre_0x(flags, cnt, num);
	print_num(flags, cnt, num);
	if (flags->pre < nbr_len)
		flags->pre = nbr_len;
	put_blank_zero(flags->width - nbr_len, ' ', cnt, flags);
}

void	put_right(t_flag *flags, int *cnt, int nbr_len, unsigned long long num)
{
	if (flags->minus != 0)
		return ;
	if (flags->pre == -1)
		flags->pre = 0;
	if (flags->nbr_sign == -1)
		flags->width--;
	if (flags->zero == 1)
		put_sign(flags, cnt);
	if (flags->pre >= nbr_len)
		put_blank_zero(flags->width - flags->pre, ' ', cnt, flags);
	else
		put_blank_zero(flags->width - nbr_len, ' ', cnt, flags);
	if (flags->zero == 0)
		put_sign(flags, cnt);
	put_blank_zero(flags->pre - nbr_len, '0', cnt, flags);
	pre_0x(flags, cnt, num);
	print_num(flags, cnt, num);
}

void	print_nbr(unsigned long long num, t_flag *flags, int *cnt)
{
	int	nbr_len;

	if (num == 0 && flags->pre == 0)
		return ;
	if ((flags->type == 'd' || flags-> type == 'i') && (int) num < 0)
	{
		num = -num;
		flags->nbr_sign = -1;
	}
	else if (flags->type == 'x' || flags->type == 'X' || flags->type == 'p')
		flags->nbr_base = 16;
	nbr_len = ft_nbrlen(num, flags);
	put_space(flags, cnt);
	put_left(flags, cnt, nbr_len, num);
	put_right(flags, cnt, nbr_len, num);
}
