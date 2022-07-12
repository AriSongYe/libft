/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:08:17 by yecsong           #+#    #+#             */
/*   Updated: 2022/07/12 14:58:34 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	check_zero(t_flag *flags, int *cnt)
{
	if (flags->zero == 1)
		ft_putchar('0', cnt);
	else
		ft_putchar(' ', cnt);
}

void	put_str(char *str, t_flag *flags, int *cnt, int len)
{
	int	i;

	i = 0;
	if (len > flags->pre && flags->pre != -1)
		while (i < flags->pre)
			ft_putchar(str[i++], cnt);
	else if (len <= flags->pre || flags->pre == -1)
		ft_putstr(str, cnt);
}

void	put_str_width(t_flag *flags, int *cnt, int len)
{
	int	i;

	i = 0;
	if (flags->pre != -1 && len > flags->pre)
		while (i++ < flags->width - len - flags->pre)
			check_zero(flags, cnt);
	else if (flags->pre == -1 || flags->pre >= len)
		while (i++ < flags->width - len)
			check_zero(flags, cnt);
}

void	print_str(char *str, t_flag *flags, int *cnt)
{
	int	str_len;

	if (flags->pre == 0)
		return ;
	str_len = ft_strlen(str);
	if (flags->minus == 1)
	{
		put_str(str, flags, cnt, str_len);
		put_str_width(flags, cnt, str_len);
	}
	else if (flags->minus == 0)
	{
		put_str_width(flags, cnt, str_len);
		put_str(str, flags, cnt, str_len);
	}
}
