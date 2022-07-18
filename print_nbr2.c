/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:15:55 by yecsong           #+#    #+#             */
/*   Updated: 2022/07/18 12:19:29 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	put_space(t_flag *flags, char **str)
{
	if (flags->space == 1 && flags->nbr_sign != -1)
		(*str) = ft_my_strjoin(" ", (*str), 2);
	if (!(*str))
		return (-1);
	return (1);
}

int	pre_0x(t_flag *flags, char **str, unsigned long long num)
{
	if (num == 0 && (flags->type == 'x' || flags->type == 'X'))
		return (0);
	if (flags->type == 'x' || flags->type == 'p')
		(*str) = ft_my_strjoin ("0x", (*str), 2);
	else if (flags->type == 'X')
		(*str) = ft_my_strjoin ("0X", (*str), 2);
	if (!(*str))
		return (-1);
	return (0);
}

char	*ft_my_strjoin(char *s1, char *s2, int target_free)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) *(s1_len + s2_len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, s1_len + 1);
	ft_strlcat(ptr, s2, s2_len + s1_len + 1);
	if (target_free == 1 || target_free == 3)
		free(s1);
	if (target_free == 2 || target_free == 3)
		free(s2);
	return (ptr);
}

void	put_pre_str2(unsigned long long num, t_flag *flags, char **str, int t)
{
	int	i;

	i = 1;
	while (num)
	{
		(*str)[t - i] = ft_baseset(flags)[num % flags->nbr_base];
		num /= flags->nbr_base;
		i++;
	}
}
