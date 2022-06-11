/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:54:29 by plouvel           #+#    #+#             */
/*   Updated: 2022/06/11 11:24:01 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

# include "all_lib.h"
# include <stdbool.h>

# define COLOR_BLUE   "\033[94;1m"
# define COLOR_YELLOW "\033[93;1m"
# define COLOR_CYAN   "\033[96;1m"
# define BOLD "\033[1m"
# define COLOR_RESET  "\033[0m"
# define STR_PAWN_AI    COLOR_BLUE   "X" COLOR_RESET
# define STR_PAWN_HUMAN COLOR_YELLOW "O" COLOR_RESET
# define MIN_SIZE_LINE 6
# define MAX_SIZE_LINE 10
# define MIN_SIZE_RAW 7
# define MAX_SIZE_RAW 10
# define HEADER \
BOLD \
"   ______                            __  __ __\n" \
"  / ____/___  ____  ____  ___  _____/ /_/ // /\n" \
" / /   / __ \\/ __ \\/ __ \\/ _ \\/ ___/ __/ // /_\n" \
"/ /___/ /_/ / / / / / / /  __/ /__/ /_/__  __/\n" \
"\\____/\\____/_/ /_/_/ /_/\\___/\\___/\\__/  /_/  \n\n\n" \
COLOR_RESET

typedef enum e_player
{
	Nobody,
	AI,
	Human,
}			Player;

typedef struct e_pawn
{
	Player	played_by;
	bool	endl;
}				t_pawn;

typedef struct e_connect4
{
	t_pawn	**board;
	unsigned int nb_line;
	unsigned int nb_raw;
}				t_connect4;

/* board.c */

t_pawn	**create_board(unsigned int rows, unsigned int lines);
void	*free_board(t_pawn **board);
void	show_board(t_pawn **board);
int		check_int(char *str);
int		first_check(int ac, char **av);

#endif
