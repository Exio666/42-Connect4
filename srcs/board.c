/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:00:08 by plouvel           #+#    #+#             */
/*   Updated: 2022/06/12 13:36:23 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

t_pawn	**create_board(t_connect4 *game, int cols, int rows)
{
	t_pawn	**board;
	int		i;

	board = ft_calloc(rows, sizeof(t_pawn *));
	if (!board)
		return (NULL);
	for (i = 0; i < rows; i++)
	{
		board[i] = ft_calloc(cols, sizeof(t_pawn));
		if (!board[i])
			return (free_board(game, board));
	}
	game->rows = rows;
	game->cols = cols;
	return (board);
}

t_pawn	**clone_board(t_connect4 *game, t_pawn **copy_board)
{
	t_pawn	**board;
	int		i;

	board = ft_calloc(game->rows, sizeof(t_pawn *));
	if (!board)
		return (NULL);
	for (i = 0; i < game->rows; i++)
	{
		board[i] = ft_calloc(game->cols, sizeof(t_pawn));
		if (!board[i])
			return (free_board(game, board));
		else
		{
			for (int col = 0; col < game->cols; col++)
			{
				board[i][col].played_by = copy_board[i][col].played_by;
			}
		}
	}
	return (board);
}

void	*free_board(t_connect4 *game, t_pawn **board)
{
	for (int y = 0; y < game->rows; y++)
		free(board[y]);
	free(board);
	return (NULL);
}

static void	print_col_indicator(int cols)
{
	ft_putstr_fd("\n\t", STDOUT_FILENO);
	for (int x = 0; x < cols; x++)
	{
		ft_putstr_fd("  ", STDOUT_FILENO);
		ft_putstr_fd(COLOR_CYAN, STDOUT_FILENO);
		ft_putnbr_fd((int) x + 1, STDOUT_FILENO);
		ft_putstr_fd(COLOR_RESET, STDOUT_FILENO);
		ft_putstr_fd(" ", STDOUT_FILENO);
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	show_board(t_connect4 *game)
{
	bool	draw_line = true;
	int		y;

	//ft_putstr_fd(HEADER, STDOUT_FILENO);
	for (y = 0; y < game->rows; )
	{
		ft_putstr_fd("\t", STDOUT_FILENO);
		for (int x = 0; x < game->cols; x++)
		{
			if (draw_line)
				ft_putstr_fd("+---", STDOUT_FILENO);
			else
			{
				ft_putstr_fd("+ ", STDOUT_FILENO);
				if (game->board[y][x].played_by == AI)
					ft_putstr_fd(STR_PAWN_AI, STDOUT_FILENO);
				else if (game->board[y][x].played_by == Human)
					ft_putstr_fd(STR_PAWN_HUMAN, STDOUT_FILENO);
				else
					ft_putstr_fd(" ", STDOUT_FILENO);
				ft_putstr_fd(" ", STDOUT_FILENO);
			}
		}
		if (draw_line)
			draw_line = false;
		else
		{
			draw_line = true;
			y++;
		}
		ft_putstr_fd("+\n", STDOUT_FILENO);
	}

	/* Finish the board */ 

	ft_putstr_fd("\t", STDOUT_FILENO);
	for (int x = 0; x < game->cols; x++)
		ft_putstr_fd("+---", STDOUT_FILENO);
	ft_putstr_fd("+\n", STDOUT_FILENO);

	print_col_indicator(game->cols);
}

long long	get_score(t_connect4 *game, t_pawn **board, Player player)
{
	t_window	horizontal, vertical, pos_diagonal, neg_diagonal, center;
	long long	score = 0;
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
			pos_diagonal = get_pos_diagonal_window(board, player, pos);
			score += eval_window(&pos_diagonal);
		}
	}

	// Check negative diagonal

	for (pos.x = 0; pos.x < game->cols - 3; pos.x++)
	{
		for (pos.y = game->rows - 1; pos.y >= 3; pos.y--)
		{
			neg_diagonal = get_neg_diagonal_window(board, player, pos);
			score += eval_window(&neg_diagonal);
		}
	}

	return (score);
}

void	drop_pawn(t_pawn **board, t_position pos, Player player)
{
	board[pos.y][pos.x].played_by = player;
}
