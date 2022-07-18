# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 14:46:07 by yecsong           #+#    #+#              #
#    Updated: 2022/07/12 15:28:11 by yecsong          ###   ########.fr        #
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
				print_nbr2.c\
				

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)


ifdef BONUS_CHECK
OBJS_FILES = $(OBJS_BONUS)
else
OBJS_FILES = $(OBJS)
endif

AR := ar

ARFLAGS := src

CC := cc

CFLAGS := -Werror -Wextra -Wall

all : $(NAME)


$(NAME) : $(OBJS_FILES)
		$(MAKE) -C ./libft all
		cp ./libft/libft.a ./$(NAME)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS_FILES)

re : fclean all

clean :
	rm -f *.o
	rm -f libft/*.o

fclean : clean
	rm -f $(NAME)
	rm -f libft/libft.a

bonus :
	@make BONUS_CHECK=1 all

.PHONY : all clean fclean bonus re
