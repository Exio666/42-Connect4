/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:19:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/12 10:09:25 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

bool	check_valid_col(t_connect4 *game, int selected_col)
{
	if (selected_col < 0 || selected_col > game->rows)
		return (false);
	if (game->board[0][selected_col].played_by != Nobody)
		return (false);
	return (true);
}

int	get_valid_row(t_connect4 *game, int selected_col)
{
	int	row;

	row = game->rows - 1;
	while (game->board[row][selected_col].played_by != Nobody)
		row--;
	return (row);
}


t_window	get_horizontal_window(t_pawn **board, Player player, t_position pos)
{
	t_window	window;

	window.empty = 0;
	window.equivalent = 0;
	window.opponent = 0;
	for (int _x = pos.x; _x <= pos.x + 3; _x++)
	{
		if (board[pos.y][_x].played_by == player)
			window.equivalent++;
		else if (board[pos.y][_x].played_by == Nobody)
			window.empty++;
		else
			window.opponent++;
	}
	return (window);
}

t_window	get_vertical_window(t_pawn **board, Player player, t_position pos)
{
	t_window	window;

	window.empty = 0;
	window.equivalent = 0;
	window.opponent = 0;
	for (int _y = pos.y; _y >= pos.y - 3; _y--)
	{
		if (board[_y][pos.x].played_by == player)
			window.equivalent++;
		else if (board[_y][pos.x].played_by == Nobody)
			window.empty++;
		else
			window.opponent++;
	}
	return (window);
}

t_window	get_positive_diagonal(t_pawn **board, Player player, t_position pos)
{
	t_window	window;
	int			_y;

	window.empty = 0;
	window.equivalent = 0;
	window.opponent = 0;
	_y = pos.y;
	for (int _x = pos.x; _x <= pos.x + 3; _x++)
	{
		if (board[_y][_x].played_by == player)
			window.equivalent++;
		else if (board[_y][_x].played_by == Nobody)
			window.empty++;
		else
			window.opponent++;
		_y--;
	}
	return (window);
}

t_window	get_negative_diagonal(t_pawn **board, Player player, t_position pos)
{
	t_window	window;
	int			_y;

	window.empty = 0;
	window.equivalent = 0;
	window.opponent = 0;
	_y = pos.y - 3;
	for (int _x = pos.x; _x <= pos.x + 3; _x++)
	{
		if (board[_y][_x].played_by == player)
			window.equivalent++;
		else if (board[_y][_x].played_by == Nobody)
			window.empty++;
		else
			window.opponent++;
		_y++;
	}
	return (window);
}

int	eval_window(t_window * window)
{
	int	score;

	score = 0;
	if (window->equivalent == 4)
		score += 100;
	else if (window->equivalent == 3 && window->empty == 1)
		score += 10;
	else if (window->equivalent == 2 && window->empty == 2)
		score += 5;
	if (window->opponent == 3 && window->empty == 1)
		score -= 80;
	
	return (score);
}

int	get_score(t_connect4 *game, t_pawn **board, Player player)
{
	t_window	horizontal, vertical, pos_diagonal, neg_diagonal, center;
	int			score = 0;
	t_position	pos;

	center.empty = 0;
	center.equivalent = 0;
	center.opponent = 0;
	pos.x = (game->cols - 1) / 2;
	for (pos.y = game->rows - 1; pos.y >= 0; pos.y--)
	{
		if (board[pos.y][pos.x].played_by == player)
			center.equivalent++;
	}
	score += center.equivalent * 6;

	for (pos.y = game->rows - 1; pos.y >= 0; pos.y--)
	{
		for (pos.x = 0; pos.x < game->cols - 3; pos.x++)
		{
			horizontal = get_horizontal_window(board, player, pos);
			score += eval_window(&horizontal);
		}
	}
	// Check vertical

	for (pos.x = 0; pos.x < game->cols; pos.x++)
	{
		for (pos.y = game->rows - 1; pos.y >= 3; pos.y--)
		{
			vertical = get_vertical_window(board, player, pos);
			score += eval_window(&vertical);
		}
	}

	// Check positive diagonal

	for (pos.x = 0; pos.x < game->cols - 3; pos.x++)
	{
		for (pos.y = game->rows - 1; pos.y >= 3; pos.y--)
		{
			pos_diagonal = get_positive_diagonal(board, player, pos);
			score += eval_window(&pos_diagonal);
		}
	}

	// Check negative diagonal

	for (pos.x = 0; pos.x < game->cols - 3; pos.x++)
	{
		for (pos.y = game->rows - 1; pos.y >= 3; pos.y--)
		{
			neg_diagonal = get_negative_diagonal(board, player, pos);
			score += eval_window(&neg_diagonal);
		}
	}

	return (score);
}

int	pick_best_move(t_connect4 *game, Player player)
{
	t_position	pos;
	int	best_score = -10000;
	int	best_col = rand() % (game->cols + 1);

	for (pos.x = 0; pos.x < game->cols; pos.x++)
	{
		if (check_valid_col(game, pos.x))
		{
			t_pawn **	temp_board;
			int			score;

			pos.y = get_valid_row(game, pos.x);
			temp_board = clone_board(game);
			drop_pawn(game->board, pos, player);
			score = get_score(game, game->board, player);
			if (score > best_score)
			{
				best_score = score;
				best_col = pos.x;
			}
			game->board[pos.y][pos.x].played_by = Nobody;
		}
	}
	//printf("best score : %d\n", best_score);
	return (best_col);
}

int	first_player()
{
	srand (time(NULL));
	return rand() % 2;
}

int	main(int ac, char **av)
{
	t_connect4	game;
	t_position p;
	int first;

	if (!first_check(ac, av))
		return (1);
	first = first_player();
	game.current_player = Human;
	game.rows = 7;
	game.cols = 6;
	game.board = create_board(&game, 7, 6);
	p.x = 0;
	p.y = 0;
	while (!tab_is_full(&game))
	{
		if (first)
		{
			show_board(&game);
			p = add_pawn_player(&game, Human);
			if (check_win_row(&game) || check_win_line(&game) || check_win_diag(&game))
			{
				ft_printf("The humanity won\n");
				free_board(&game);
				return (0);
			}
		}
		{
			show_board(&game);
			p = add_pawn_player(&game, AI);
			if (check_win_row(&game) || check_win_line(&game) || check_win_diag(&game))
			{
				ft_printf("The IA is just superior\n");
				free_board(&game);
				return (0);
			}
		}
		first = 1;
	}
	ft_printf("Nobody won try again\n");
	free_board(&game);
	return (0);
}
