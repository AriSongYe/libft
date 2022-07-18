/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:24:33 by yecsong           #+#    #+#             */
/*   Updated: 2022/07/18 12:59:37 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "libft/libft.h"

# define TYPE "cspdiuxX%"

typedef struct s_flag
{
	int		minus;
	int		zero;
	int		pound;
	int		space;
	int		pre;
	int		width;
	int		plus;
	int		nbr_base;
	int		nbr_sign;
	char	type;
}	t_flag;

int		ft_printf(const char *format, ...);
int		parse_format(va_list ap, const char *format, int *cnt);
int		ft_nbrlen(unsigned long long num, t_flag *flags);
int		put_pre_str(unsigned long long num, t_flag *flags, char **str);
int		put_space(t_flag *flags, char **str);
int		pre_0x(t_flag *flags, char **str, unsigned long long num);
void	print_type(va_list ap, t_flag *flags, int *cnt);
void	put_pre_str2(unsigned long long num, t_flag *flags, char **str, int t);
void	check_flag(char sign, t_flag *flags);
void	check_zero(t_flag *flags, int *cnt);
void	ft_putchar(char c, int *cnt);
void	ft_putstr(char *s, int *cnt);
void	print_char(int c, t_flag *flags, int *cnt);
void	print_str(char *str, t_flag *flags, int *cnt);
void	print_nbr(unsigned long long num, t_flag *flag, int *cnt);
void	put_str(char *str, t_flag *flags, int *cnt, int len);
void	put_str_width(t_flag *flags, int *cnt, int len);
void	init_flags(t_flag *flags);
void	print_num(t_flag *flags, int *cnt, unsigned long long num);
char	*ft_baseset(t_flag *flags);
char	*ft_my_strjoin(char *s1, char *s2, int target_free);
#endif
