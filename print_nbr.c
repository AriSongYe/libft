/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:43:20 by yecsong           #+#    #+#             */
/*   Updated: 2022/07/15 11:43:28 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	pre_0x(t_flag *flags, char **str, unsigned long long num)
{
	if (num == 0 && (flags->type == 'x' || flags->type =='X'))
		return (0);
	if (flags->type == 'x' || flags->type == 'p')
		(*str) = ft_strjoin ("0x", (*str), 2);
	else if (flags->type =='X')
		(*str) = ft_strjoin ("0X", (*str), 2);
	if (!(*str))
		return (-1);
	return (0);
}

int	put_pre_str(unsigned long long num, t_flag *flags, char **str)
{
	int	len;
	int	temp;
	int	i;

	len = ft_nbrlen(num, flags);
	if (flags->pre > len)
		temp = flags->pre;
	else
		temp = len;
	(*str) = (char *)malloc(sizeof(char) * temp + 1);
	if (!(*str))
		return (-1);
	(*str)[temp] = '\0';
	i = 0;
	while (len + i < temp)
	{
		(*str)[i] = '0';
		i++;
	}
	i = 1;
	if (num == 0 && flags->pre != 0)
		(*str)[temp - i] = '0';
	if (num == 0 && flags->pre == 0)
		(*str)[0] = '\0';
	while (num)
	{
		(*str)[temp - i] = ft_baseset(flags)[num % flags->nbr_base];
		num /= flags->nbr_base;
		i++;
	}
	return (len);
}

int	put_num_sign_1(t_flag *flags, char **str)
{
	if (flags->nbr_sign == -1 && flags->zero == 1 && flags->pre > 0)
	{
			(*str) = ft_strjoin("-", (*str), 2);
			flags->width += 1;
	}
	if (flags->nbr_sign == -1 && flags->zero == 0)
		if(flags->type == 'd' || flags->type == 'i')
			(*str) = ft_strjoin("-", (*str), 2);
	if (flags->nbr_sign == 0 && flags->plus == 1 && flags->zero == 0)
	{
		(*str) = ft_strjoin("+", (*str), 2);
	}
	if(!(*str))
		return (-1);
	return (0);
}

int	put_num_sign_2(t_flag *flags, char **str)
{
	if (flags->nbr_sign == -1 && flags->zero == 1)
	{
		if (ft_strlen(*str) >= flags->width && flags-> pre <= 0)
			(*str) = ft_strjoin("-", (*str), 2);
		else if (ft_strlen(*str) < flags->width && flags->pre <= 0)
			(*str)[0] = '-';
	}
	else if (flags->nbr_sign == 0 && flags->plus == 1 && flags->zero == 1)
	{
		if (ft_strlen(*str) > flags->width && flags->pre <= 0)
			(*str) = ft_strjoin("+", (*str), 2);
		else if (ft_strlen(*str) < flags->width && flags->pre <= 0)
			(*str)[0] = '+';
	}
	if(!(*str))
		return (-1);
	return (0);
}
int	put_width(t_flag *flags, char **str)
{
	char	*width;
	int		i;

	i = 0;
	if (flags->zero == 1 && flags->nbr_sign == -1)
		flags->width -= 1;
	if (flags->width <= ft_strlen(*str))
		return (1);
	width = (char *)malloc(sizeof(char)* flags->width - ft_strlen(*str) + 1);
	if(!width)
		return (-1);
	while (i < flags->width - ft_strlen(*str))
	{
		if (flags->zero == 1 && flags->pre < 0)
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if (flags->minus == 1)
		(*str) = ft_strjoin((*str), width, 3);
	else
		(*str) = ft_strjoin(width, (*str), 3);
	return (1);
}
void	print_nbr(unsigned long long num, t_flag *flags, int *cnt)
{
	char	*str;

	if ((flags->type == 'd' || flags-> type == 'i') && (int) num < 0)
	{
		num = -num;
		flags->nbr_sign = -1;
	}
	else if (flags->type == 'x' || flags->type == 'X' || flags->type == 'p')
		flags->nbr_base = 16;
	put_pre_str(num, flags, &str);
	put_num_sign_1(flags, &str);
	if (flags->type == 'p' || flags->pound == 1)
		pre_0x(flags, &str, num);
	put_width(flags, &str);
	put_num_sign_2(flags, &str);
	put_space(flags, &str);
	ft_putstr(str ,cnt);
	free(str);
}
