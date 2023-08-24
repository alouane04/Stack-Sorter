# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 13:48:31 by ariahi            #+#    #+#              #
#    Updated: 2023/08/24 16:31:07 by ariahi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  rules/rules.c rules/rules_2.c rules/rules_3.c algo.c \
		ft_checking.c ft_fix.c indexing.c lst_utiles.c markup.c \
		send_to_b.c
SRCM = push_swap.c
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(SRCM) $(SRCS) libft/libft.a push_swap.h
	$(CC) $(CFLAGS) -o $(NAME) $(SRCM) $(SRCS) libft/libft.a

.PHONY: all re clean fclean

libft/libft.a:
	make -C Libft all

all: $(NAME)

clean:
	make -C Libft clean

fclean:
	make -C Libft fclean
	rm -rf $(NAME)

re: fclean all

