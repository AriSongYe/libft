/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:38:34 by yecsong           #+#    #+#             */
/*   Updated: 2022/07/06 14:55:22 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_char(int c, t_flag *flags, int *cnt)
{
	int i;

	i = 0;
	if (flags->minus == 1)
		ft_putchar(c , cnt);
	if (flags->width - 1 > 0)
		if (flags->zero == 1)
			while (i++ < flags->width - 1)
				ft_putchar('0', cnt);
		if (flags->zero == 0)
			while (i++ < flags->width - 1)
				ft_putchar(' ', cnt);
	if (flags->minus == 0)
		ft_putchar(c, cnt);
}
