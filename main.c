/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:03:44 by yecsong           #+#    #+#             */
/*   Updated: 2022/07/12 12:21:20 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf_bonus.h"
#include <limits.h>

int main()
{
	ft_printf("\n\n//// type 's' ////\n\n");
	ft_printf(NULL);
	ft_printf("%-03%\n");
	ft_printf("%03%\n");
	ft_printf("%03c\n", 'a');
	ft_printf("%-03c\n", 'b');
	ft_printf(" abc\n"); // 일반 문자열이 들어왔을 경우
	ft_printf("%2cbc\n", 'a'); //type 'c' 에서 width 를 준 경우
	ft_printf("%.2cbc\n", 'a'); // type 'c' 에서 precision -> undefined behavior
	ft_printf("%-2cbc\n", 'a'); //type 'c' 에서 '-' flag && width를 준 경우
	ft_printf("%-cbc\n", 'a'); //type 'c' 에서 '-' flag  단독으로준 경우
	ft_printf("%-03cbc\n", 'a'); //type 'c' 에서 '-' flag '0' 같이 준경우
	ft_printf("%02cbc\n", 'a'); // type 'c' 에서 '0' flag -> undefined behavior 이지만 출력은 된다. 임의로 만들어놓음.
	ft_printf("%+2cbc\n", 'a'); // type 'c' 에서 '+' flag -> undefined behavior
	ft_printf("% cbc\n", 'a'); // type 'c' 에서 ' ' flag -> undefined behavior
	ft_printf("%#cbc\n", 'a'); // type 'c' 에서 '#' flag -> undefined behavior
	ft_printf("\n\n//// type 's' ////\n\n");
	ft_printf("%s\n", "abc");
	ft_printf("%6s\n", "abc"); // type 's' 에서 width를 준 경우
	ft_printf("%3s\n", "abc"); // type 's' 에서 width를 준 경우 width 와 문자열이 같은 경우 
	ft_printf("%2s\n", "abc"); // type 's' 에서 width를 준 경우 width 가 문자열 보다 작게 준 경우
	ft_printf("%.6s\n", "abc"); // type 's' 에서 precision을 준경우
	ft_printf("%.s\n", "abc"); // type 's' 에서 precision 단독으로 쓸 경우
	ft_printf("%-10s\n", "abc"); // type 's' 에서 '-' flag & width를 준 경우
	ft_printf("%-2s\n", "abc"); // type 's' 에서 '-' flag & width 문자열 보다 작게 준경우
	ft_printf("%-s\n", "abc"); // type 's' 에서 '-' flag 를 단독으로 준 경우
	ft_printf("%-03s\n", "abc"); // type 's' 에서 '-' flag를 '0'  같이 준 경우
	ft_printf("%0s\n", "abc"); // type 's' 에서 '0'  flag -> undefined behavior
	ft_printf("%+s\n", "abc"); // type 's' 에서 '+' flag -> undefined behavior
	ft_printf("% s\n", "abc"); // type 's' 에서 ' ' flag -> undefined behavior
	
	ft_printf("\n\n//// type 'd' & 'i' ////\n\n");
	ft_printf("%0d\n", 0);
	ft_printf("%1d\n", INT_MAX);
	ft_printf("%2d\n", INT_MIN);
	ft_printf("%3d\n", 123123);
	ft_printf("%.4d\n", 0);
	ft_printf("%.5d\n", INT_MAX);
	ft_printf("%.6d\n", INT_MIN);
	ft_printf("%.7d\n", 123123);
	ft_printf("%0.4d\n", 0);
	ft_printf("%1.5d\n", INT_MAX);
	ft_printf("%2.6d\n", INT_MIN);
	ft_printf("%3.7d\n", 123123);
	ft_printf("%.d\n", 1);
	ft_printf("%5.1d\n", INT_MAX);
	ft_printf("%6.2d\n", INT_MIN);
	ft_printf("%7.3d\n", 123123);
	ft_printf("%-10.3d\n", 0);
	ft_printf("%09d\n", INT_MAX);
	ft_printf("% 8.5d\n", INT_MIN);
	ft_printf("%.d\n", 0);
	ft_printf("%0u\n", 0);
	ft_printf("%1u\n", INT_MAX);
	ft_printf("%2u\n", INT_MIN);
	ft_printf("%3u\n", 123123);
	ft_printf("%.4u\n", 0);
	ft_printf("%.5u\n", INT_MAX);
	ft_printf("%.6u\n", INT_MIN);
	ft_printf("%.7u\n", 123123);
	ft_printf("%0.4u\n", 0);
	ft_printf("%1.5u\n", INT_MAX);
	ft_printf("%2.6u\n", INT_MIN);
	ft_printf("%3.7u\n", 123123);
	ft_printf("%.u\n", 0);
	ft_printf("%5.1u\n", INT_MAX);
	ft_printf("%6.2u\n", INT_MIN);
	ft_printf("%7.3u\n", 123123);
	ft_printf("%-10.3u\n", 0);
	ft_printf("%09u\n", INT_MAX);
	ft_printf("% 8.5u\n", INT_MIN);
	ft_printf("\n\n//// type 'x' ////\n\n");
	ft_printf("%0x\n", 0);
	ft_printf("%1x\n", INT_MAX);
	ft_printf("%2x\n", INT_MIN);
	ft_printf("%3x\n", 123123);
	ft_printf("%.4x\n", 0);
	ft_printf("%.5x\n", INT_MAX);
	ft_printf("%.6x\n", INT_MIN);
	ft_printf("%.7x\n", 123123);
	ft_printf("%0.4x\n", 0);
	ft_printf("%1.5x\n", INT_MAX);
	ft_printf("%2.6x\n", INT_MIN);
	ft_printf("%3.7x\n", 123123);
	ft_printf("%.x\n", 0);
	ft_printf("%x\n", 0);
	ft_printf("%5.1x\n", INT_MAX);
	ft_printf("%6.2x\n", INT_MIN);
	ft_printf("%7.3x\n", 123123);
	ft_printf("%-10.3x\n", 0);
	ft_printf("%09x\n", INT_MAX);
	ft_printf("%#8.5x\n", INT_MIN);
	ft_printf("%#x\n", 0);
	ft_printf("\n\n//// type 'X' ////\n\n");
	ft_printf("%0X\n", 0);
	ft_printf("%1X\n", INT_MAX);
	ft_printf("%2X\n", INT_MIN);
	ft_printf("%3X\n", 123123);
	ft_printf("%.4X\n", 0);
	ft_printf("%.5X\n", INT_MAX);
	ft_printf("%.6X\n", INT_MIN);
	ft_printf("%.7X\n", 123123);
	ft_printf("%0.4X\n", 0);
	ft_printf("%1.5X\n", INT_MAX);
	ft_printf("%2.6X\n", INT_MIN);
	ft_printf("%3.7X\n", 123123);
	ft_printf("%.X\n", 0);
	ft_printf("%X\n", 0);
	ft_printf("%5.3X\n", INT_MAX);
	ft_printf("%6.2X\n", INT_MIN);
	ft_printf("%7.3X\n", 123123);
	ft_printf("%-10.3X\n", 0);
	ft_printf("%09X\n", INT_MAX);
	ft_printf("%#8.5X\n", INT_MIN);
	ft_printf("\n\n//// type 'p' ////\n\n");
	ft_printf("%0p\n", 0);
	ft_printf("%1p\n", INT_MAX);
	ft_printf("%2p\n", INT_MIN);
	ft_printf("%3p\n", 123123);
	ft_printf("%.4p\n", 0);
	ft_printf("%.5p\n", INT_MAX);
	ft_printf("%.6p\n", INT_MIN);
	ft_printf("%.7p\n", 123123);
	ft_printf("%0.4p\n", 0);
	ft_printf("%1.5p\n", INT_MAX);
	ft_printf("%2.6p\n", INT_MIN);
	ft_printf("%3.7p\n", 123123);
	ft_printf("%.p\n", 0);
	ft_printf("%p\n", 0);
	ft_printf("%5.3p\n", INT_MAX);
	ft_printf("%6.2p\n", INT_MIN);
	ft_printf("%7.3p\n", 123123);
	ft_printf("%-10.3p\n", 0);
	ft_printf("%09p\n", INT_MAX);
	ft_printf("%#8.5p\n", INT_MIN);
}
