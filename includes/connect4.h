/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:54:29 by plouvel           #+#    #+#             */
/*   Updated: 2022/06/12 14:06:10 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <time.h> 
# include "all_lib.h"

# define COLOR_BLUE   "\033[94;1m"
# define COLOR_YELLOW "\033[93;1m"
# define COLOR_CYAN   "\033[96;1m"
# define BOLD "\033[1m"
# define COLOR_RESET  "\033[0m"
# define STR_PAWN_AI    COLOR_BLUE   "X" COLOR_RESET
# define STR_PAWN_HUMAN COLOR_YELLOW "O" COLOR_RESET
# define MIN_SIZE_ROW 6
# define MAX_SIZE_ROW 2147483647
# define MIN_SIZE_COL 7
# define MAX_SIZE_COL 2147483647

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
	End
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

typedef struct	e_minimax
{
	long long	score;
	int			col;
}				t_minimax;

typedef struct e_window
{
	int	equivalent;
	int	opponent;
	int	empty;
}			t_window;

/*
 *	add_pawn.c
 */

t_position	add_pawn_player(t_connect4 *backpack, Player player);
int			add_pawn(t_connect4 *backpack, unsigned int row, Player player);

/* 
 *	board.c
 */

t_pawn		**create_board(t_connect4 *game);
t_pawn		**clone_board(t_connect4 *game, t_pawn **copy_board);
void		*free_board(t_connect4 *game, t_pawn **board);
void		show_board(t_connect4 *game);
long long	get_score(t_connect4 *game, t_pawn **board, Player player);
void		drop_pawn(t_pawn **board, t_position pos, Player player);

/*
 *	check_win.c
 */

bool		check_win_row(t_connect4 *backpack);
bool		check_win_line(t_connect4 *backpack);
bool		check_win_diag(t_connect4 *backpack);
bool		tab_is_full(t_connect4 *backpack);

/*
 *	first_check.c
 */

int			check_int(char *str);
int			first_check(int ac, char **av, t_connect4 *backpack);

/*
 *	main.c
 */

Player		first_player();

/* 
 *  checks.c
 */

bool	check_valid_col(t_connect4 *game, t_pawn **board, int selected_col);
int		get_valid_row(t_connect4 *game, t_pawn **board, int selected_col);
bool	check_win_move(t_connect4 *game, t_pawn **board, Player player);

/* 
 *	window.c
 */

t_window	get_horizontal_window(t_pawn **board, Player player, t_position pos);
t_window	get_vertical_window(t_pawn **board, Player player, t_position pos);
t_window	get_pos_diagonal_window(t_pawn **board, Player player, t_position pos);
t_window	get_neg_diagonal_window(t_pawn **board, Player player, t_position pos);
long long	eval_window(t_window * window);

/* 
 * minimax.c
 */

t_minimax	minimax(t_connect4 *game, t_pawn **board, int depth, bool maxPlayer);

#endif
