# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 14:46:07 by yecsong           #+#    #+#              #
#    Updated: 2022/07/11 17:59:48 by yecsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SRCS := ft_printf.c\
		ft_printf_utils.c

SRCS_BONUS :=	ft_printf_bonus.c\
				ft_printf_bonus_utils.c\
				print_char.c\
				print_str.c\
				print_nbr.c\
				

OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

AR := ar

ARFLAGS := src

CC := cc

CFLAGS := -Werror -Wextra -Wall

all : $(NAME)

$(NAME) : $(OBJS_BONUS)
		$(MAKE) -C ./libft all
		cp ./libft/libft.a ./$(NAME)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS_BONUS)

re : fclean all

clean :
	rm -f *.o
	rm -f libft/*.o

fclean : clean
	rm -f $(NAME)
	rm -f libft/libft.a

bonus : $(OBJS_BONUS)
		$(MAKE) -C ./libft all
		cp ./libft/libft.a ./$(NAME)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS_BONUS)

.PHONY : all clean fclean bonus re
