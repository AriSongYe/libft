/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:32:25 by yecsong           #+#    #+#             */
/*   Updated: 2022/07/12 14:57:55 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	check_flag(char sign, t_flag *flags)
{
	if (sign == '-' && flags->width == 0)
		flags->minus = 1;
	else if (sign == '0' && flags->width == 0 && flags->pre == -1)
		flags->zero = 1;
	else if (sign == '+')
		flags->plus = 1;
	else if (sign == '.')
		flags->pre = 0;
	else if (sign == '#')
		flags->pound = 1;
	else if (sign == ' ')
		flags->space = 1;
	else if (ft_isdigit(sign))
	{
		if (flags->pre >= 0)
			flags->pre = flags->pre * 10 + sign - 48;
		else
			flags->width = flags->width * 10 + sign - 48;
	}
}

void	print_type(va_list ap, t_flag *flags, int *cnt)
{
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->type == 'c')
		print_char(va_arg(ap, int), flags, cnt);
	else if (flags->type == '%')
		print_char('%', flags, cnt);
	else if (flags->type == 's')
		print_str(va_arg(ap, char *), flags, cnt);
	else if (flags->type == 'd' || flags->type == 'i')
		print_nbr(va_arg(ap, int), flags, cnt);
	else if (flags->type == 'u')
		print_nbr(va_arg(ap, unsigned int), flags, cnt);
	else if (flags->type == 'x' || flags->type == 'X')
		print_nbr(va_arg(ap, unsigned int), flags, cnt);
	else if (flags->type == 'p')
		print_nbr(va_arg(ap, unsigned long long), flags, cnt);
}

int	parse_format(va_list ap, const char *format, int *cnt)
{
	t_flag	*flags;
	int		i;

	i = 0;
	flags = malloc(sizeof(t_flag));
	if (!flags)
		return (0);
	while (format[i] != '\0')
	{
		while (format[i] && format[i] != '%')
			ft_putchar(format[i++], cnt);
		if (format[i] == '%')
		{
			init_flags(flags);
			while (format[++i] && !ft_strchr(TYPE, format[i]))
				check_flag(format[i], flags);
			flags->type = format[i++];
			print_type(ap, flags, cnt);
		}
	}
	free(flags);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	cnt = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	if (!parse_format(ap, format, &cnt))
		return (-1);
	va_end(ap);
	return (cnt);
}
