# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 09:17:31 by bsavinel          #+#    #+#              #
#    Updated: 2022/06/11 09:53:51 by plouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	=	srcs

OBJS_DIR	=	objs

SRCS		=	main.c

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

DEPS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.d))

NAME		=	Connect4

CFLAGS		=	-Wall -Wextra -Werror -MMD

BLUE		=	\033[0;37m

NO_COLOR	=	\033[m

CC			=	cc

RM			=	rm -rf

LIBS		=	libft/libft.a

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
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	$(RM) $(OBJS_DIR)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean 
	make -C libft re
	make all

libft/libft.a:
	make -C libft

-include $(DEPS)

.PHONY: all clean fclean re

.SILENT:
