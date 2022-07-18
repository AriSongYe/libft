/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:38:06 by yecsong           #+#    #+#             */
/*   Updated: 2022/07/18 12:56:23 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *cnt)
{
	write(1, &c, 1);
	*cnt = *cnt + 1;
}

void	convert_hex(int is_up, unsigned long long num, int *cnt)
{
	int	temp;

	temp = 0;
	if (num)
	{
		temp = num % 16;
		if (is_up)
		{
			convert_hex (1, num / 16, cnt);
			if (temp > 9)
				ft_putchar((temp + 'A' - 10), cnt);
			else
				ft_putchar((temp + '0'), cnt);
		}
		else
		{
			convert_hex (0, num / 16, cnt);
			if (temp > 9)
				ft_putchar((temp + 'a' - 10), cnt);
			else
				ft_putchar((temp + '0'), cnt);
		}
	}
}

void	recur_nbr(unsigned int n, int fd, int *cnt)
{
	int	temp;

	if (n != 0)
	{
		temp = n % 10;
		recur_nbr(n / 10, fd, cnt);
		if (temp >= 0)
			ft_putchar('0' + temp, cnt);
	}
}

void	ft_putnbr(unsigned int n, int fd, int *cnt)
{
	int	i;

	i = 0;
	if (n == 0)
		ft_putchar('0', cnt);
	recur_nbr(n, fd, cnt);
}

void	print_percent(char sign, int *cnt)
{
	if (sign == '%')
	{
		ft_putchar('%', cnt);
	}
}
