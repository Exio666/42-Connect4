/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:54:29 by plouvel           #+#    #+#             */
/*   Updated: 2022/06/11 14:44:44 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

# include "all_lib.h"
# include <stdbool.h>
# include <stdio.h>

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
	bool	endl;
}				t_pawn;

typedef struct e_point
{
	int x;
	int y;
}				t_point;

typedef struct e_connect4
{
	t_pawn	**board;
	unsigned int nb_line;
	unsigned int nb_row;
}				t_connect4;

/* board.c */

t_pawn	**create_board(unsigned int rows, unsigned int lines);
void	*free_board(t_pawn **board);
void	show_board(t_pawn **board);
int		check_int(char *str);
int		first_check(int ac, char **av);

bool	check_win_row(t_connect4 *backpack, int x, int y, Player player);

/*
 *	Add pawn
 */

t_point	add_pawn_player(t_connect4 *backpack, Player player);
int	add_pawn(t_connect4 *backpack, unsigned int row, Player player);

#endif
