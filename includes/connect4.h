/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:54:29 by plouvel           #+#    #+#             */
/*   Updated: 2022/06/12 09:54:53 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h> 
#include "all_lib.h"

# define COLOR_BLUE   "\033[94;1m"
# define COLOR_YELLOW "\033[93;1m"
# define COLOR_CYAN   "\033[96;1m"
# define BOLD "\033[1m"
# define COLOR_RESET  "\033[0m"
# define STR_PAWN_AI    COLOR_BLUE   "X" COLOR_RESET
# define STR_PAWN_HUMAN COLOR_YELLOW "O" COLOR_RESET
# define MIN_SIZE_LINE 6
# define MAX_SIZE_LINE 10
# define MIN_SIZE_ROW 7
# define MAX_SIZE_ROW 10

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
}				t_pawn;

typedef struct e_position
{
	int	x;
	int	y;
}				t_position;

typedef struct e_connect4
{
	t_pawn	**board;
	int	rows;
	int	cols;
	Player	current_player;
}				t_connect4;

/* 
 * board.c
 */

t_pawn		**create_board(t_connect4 *game, int rows, int cols);
void		*free_board(t_connect4 *game);
void		show_board(t_connect4 *game);

/*
 *	first check
 */

int		check_int(char *str);
int		first_check(int ac, char **av);

/*
 *	Check win
 */

bool	check_win_row(t_connect4 *backpack);
bool	check_win_line(t_connect4 *backpack);
bool	check_win_diag(t_connect4 *backpack);

/*
 *	Add pawn
 */

t_position	add_pawn_player(t_connect4 *backpack, Player player);
int	add_pawn(t_connect4 *backpack, unsigned int row, Player player);
t_pawn	**create_board(t_connect4 *game, int rows, int cols);
t_pawn	**clone_board(t_connect4 *game);
void	*free_board(t_connect4 *game);
void	show_board(t_connect4 *game);

#endif
