/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:40:40 by yecsong           #+#    #+#             */
/*   Updated: 2022/07/12 14:41:15 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar(char c, int *cnt)
{
	write(1, &c, 1);
	*cnt = *cnt + 1;
}

void	ft_putstr(char *s, int *cnt)
{
	if (!s)
		;
	write(1, s, ft_strlen(s));
	*cnt = *cnt + ft_strlen(s);
}

void	init_flags(t_flag *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->pound = 0;
	flags->space = 0;
	flags->pre = -1;
	flags->width = 0;
	flags->nbr_sign = 0;
	flags->plus = 0;
	flags->nbr_base = 10;
	flags->type = '\0';
}

char	*ft_baseset(t_flag *flags)
{
	if (flags->type == 'u' || flags->type == 'd' || flags->type == 'i')
		return ("0123456789");
	else if (flags->type == 'x' || flags->type == 'p')
		return ("0123456789abcdef");
	else if (flags->type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int	ft_nbrlen(unsigned long long num, t_flag *flags)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= flags->nbr_base;
		i++;
	}
	return (i);
}
