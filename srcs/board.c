/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:00:08 by plouvel           #+#    #+#             */
/*   Updated: 2022/06/11 23:19:37 by plouvel          ###   ########.fr       */
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
			return (free_board(game));
	}
	game->rows = rows;
	game->cols = cols;
	return (board);
}

t_pawn	**clone_board(t_connect4 *game)
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
			return (free_board(game));
		else
		{
			for (int col = 0; col < game->cols; col++)
			{
				board[i][col].played_by = game->board[i][col].played_by;
			}
		}
	}
	return (board);
}

void	*free_board(t_connect4 *game)
{
	for (int y = 0; y < game->rows; y++)
		free(game->board[y]);
	free(game->board);
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
