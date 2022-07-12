/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:24:33 by yecsong           #+#    #+#             */
/*   Updated: 2022/06/29 16:35:05 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *cnt);
void	print_str(va_list ap, char sign, int *cnt);
void	print_num(va_list ap, char sign, int *cnt);
void	print_hex(va_list ap, char sign, int *cnt);
void	print_percent(char sign, int *cnt);
void	convert_hex(int is_up, unsigned long long num, int *cnt);
void	recur_nbr(unsigned int n, int fd, int *cnt);
void	ft_putnbr(unsigned int n, int fd, int *cnt);
void	print_type(va_list ap, char sign, int *cnt);

#endif
