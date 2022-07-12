/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:15:55 by yecsong           #+#    #+#             */
/*   Updated: 2022/07/12 14:42:07 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	put_space(t_flag *flags, int *cnt)
{
	if (flags->nbr_sign != -1 && flags->space == 1)
	{
		ft_putchar(' ', cnt);
		flags->width--;
	}
	else
		return ;
}

void	put_blank_zero(int num, char type, int *cnt, t_flag *flags)
{
	int	i;

	i = 0;
	if (flags->zero == 0)
		while (i++ < num)
			ft_putchar(type, cnt);
	else
		while (i++ < num)
			ft_putchar('0', cnt);
}

void	put_sign(t_flag *flags, int *cnt)
{
	if (flags->nbr_sign == -1)
	{
		ft_putchar('-', cnt);
	}
	else if (flags->plus == 1)
	{
		ft_putchar('+', cnt);
	}
}

void	print_recur_num_u(t_flag *flags, int *cnt, unsigned int num)
{
	int	temp;

	if (num)
	{
		temp = num % flags->nbr_base;
		print_recur_num_u(flags, cnt, num / flags->nbr_base);
		ft_putchar(ft_baseset(flags)[temp], cnt);
	}
}

void	print_recur_num(t_flag *flags, int *cnt, unsigned long long num)
{
	int	temp;

	if (num)
	{
		temp = num % flags->nbr_base;
		print_recur_num(flags, cnt, num / flags->nbr_base);
		ft_putchar(ft_baseset(flags)[temp], cnt);
	}
}
