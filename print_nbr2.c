/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:15:55 by yecsong           #+#    #+#             */
/*   Updated: 2022/07/13 16:24:55 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	put_space(t_flag *flags, char **str)
{
	if (flags->space == 1 && flags->nbr_sign != -1)
		(*str) = ft_strjoin(" ", (*str), 2);
	if (!(*str))
		return (-1);
	return (1); 
}
