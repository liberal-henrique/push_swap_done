# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 15:28:14 by lliberal          #+#    #+#              #
#    Updated: 2023/03/08 21:50:20 by lliberal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
# CFLAGS	=	-fsanitize=address
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
NAME	=	push_swap
INCLUDE	=	push_swap.h
SRCS	=	push_swap.c \
			create_stack.c \
			initialize_list.c \
			insert_list.c \
			manage_lists.c \
			rotate.c \
			send_bot.c \
			send_top.c \
			sort_a.c \
			sort_big.c \
			sort_utils.c \
			sort_small.c \
			split.c \
			swap.c \
			util.c \
			util2.c \
			util3.c \

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(SRCS)-o $(NAME) $(INCLUDE)

clean:
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)
re:	fclean all

.PHONY:	all clean fclean re
