/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:24:22 by yecsong           #+#    #+#             */
/*   Updated: 2022/06/29 16:39:24 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(va_list ap, char sign, int *cnt)
{
	char	c;
	char	*str;

	if (sign == 'c')
	{
		c = (char)va_arg(ap, int);
		ft_putchar(c, cnt);
	}
	else if (sign == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			*cnt = *cnt + 6;
		}
		else
		{
			ft_putstr_fd(str, 1);
			*cnt = *cnt + ft_strlen(str);
		}
	}
}

void	print_num(va_list ap, char sign, int *cnt)
{
	int				num;
	unsigned int	num2;
	char			*str;

	if (sign == 'd' || sign == 'i')
	{
		num = va_arg(ap, int);
		str = ft_itoa(num);
		ft_putstr_fd(str, 1);
		*cnt = *cnt + ft_strlen(str);
		free(str);
	}
	else if (sign == 'u')
	{
		num2 = va_arg(ap, unsigned int);
		ft_putnbr(num2, 1, cnt);
	}
}

void	print_hex(va_list ap, char sign, int *cnt)
{
	unsigned long long	num;

	if (sign == 'x')
	{
		num = va_arg(ap, unsigned int);
		if (!num)
			ft_putchar('0', cnt);
		convert_hex(0, num, cnt);
	}
	else if (sign == 'p')
	{
		num = va_arg(ap, unsigned long long);
		ft_putstr_fd("0x", 1);
		if (!num)
			ft_putchar('0', cnt);
		convert_hex(0, num, cnt);
		*cnt = *cnt + 2;
	}
	else if (sign == 'X')
	{
		num = va_arg(ap, unsigned int);
		if (!num)
			ft_putchar('0', cnt);
		convert_hex(1, num, cnt);
	}
}

void	print_type(va_list ap, char sign, int *cnt)
{
	if (sign == 'c' || sign == 's')
		print_str(ap, sign, cnt);
	else if (sign == 'd' || sign == 'i' || sign == 'u')
		print_num(ap, sign, cnt);
	else if (sign == 'x' || sign == 'X' || sign == 'p')
		print_hex(ap, sign, cnt);
	else if (sign == '%')
		print_percent(sign, cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			print_type(ap, format[i], &cnt);
		}
		else
		{
			write(1, &format[i], 1);
			cnt = cnt + 1;
		}
		i++;
	}
	va_end(ap);
	return (cnt);
}
