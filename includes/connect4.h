/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:54:29 by plouvel           #+#    #+#             */
/*   Updated: 2022/06/11 23:19:35 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

#include <stdbool.h>
#include "all_lib.h"

# define COLOR_BLUE   "\033[94;1m"
# define COLOR_YELLOW "\033[93;1m"
# define COLOR_CYAN   "\033[96;1m"
# define BOLD "\033[1m"
# define COLOR_RESET  "\033[0m"
# define STR_PAWN_AI    COLOR_BLUE   "X" COLOR_RESET
# define STR_PAWN_HUMAN COLOR_YELLOW "O" COLOR_RESET

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

/* board.c */

t_pawn	**create_board(t_connect4 *game, int rows, int cols);
t_pawn	**clone_board(t_connect4 *game);
void	*free_board(t_connect4 *game);
void	show_board(t_connect4 *game);

#endif
