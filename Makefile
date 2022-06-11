# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 09:17:31 by bsavinel          #+#    #+#              #
#    Updated: 2022/06/11 09:40:37 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c

OBJS	= 	$(SRCS:.c=.o)
DEPS	=	$(SRCS:.c=.d)

NAME = Connect4

CPPFLAGS = -Wall -Wextra -Werror -MMD

BLUE		=	\033[0;37m
NO_COLOR	=	\033[m

CC = cc

RM = rm -f

LIBS = libft/libft.a

all: header $(NAME)

header:
		echo "${BLUE}"
		echo "   ______                            __  __ __"
		echo "  / ____/___  ____  ____  ___  _____/ /_/ // /"
		echo " / /   / __ \/ __ \/ __ \/ _ \/ ___/ __/ // /_"
		echo "/ /___/ /_/ / / / / / / /  __/ /__/ /_/__  __/"
		echo "\____/\____/_/ /_/_/ /_/\___/\___/\__/  /_/   "
		echo "${NO_COLOR}"

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean 
	make all

libft/libft.a:
	make -C libft

-include $(DEPS)

.PHONY: all clean fclean re

.SILENT: