/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 00:06:25 by plouvel           #+#    #+#             */
/*   Updated: 2022/06/12 14:43:20 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

bool	check_win_move(t_connect4 *game, t_pawn **board, Player player)
{
	t_position	pos;

	for (pos.y = game->rows - 1; pos.y >= 0; pos.y--)
	{
		for (pos.x = 0; pos.x < game->cols - 3; pos.x++)
		{
			if (board[pos.y][pos.x].played_by == player
				&& board[pos.y][pos.x + 1].played_by == player
				&& board[pos.y][pos.x + 2].played_by == player
				&& board[pos.y][pos.x + 3].played_by == player)
			{
				return (true);
			}
		}
	}

	for (pos.x = 0; pos.x < game->cols; pos.x++)
	{
		for (pos.y = game->rows - 1; pos.y >= game->rows - 3; pos.y--)
		{
			if (board[pos.y][pos.x].played_by == player
				&& board[pos.y - 1][pos.x].played_by == player
				&& board[pos.y - 2][pos.x].played_by == player
				&& board[pos.y - 3][pos.x].played_by == player)
			{
				return (true);
			}
		}
	}

	for (pos.x = 0; pos.x < game->cols - 3; pos.x++)
	{
		for (pos.y = game->rows - 1; pos.y >= game->rows - 3; pos.y--)
		{
			if (board[pos.y][pos.x].played_by == player
				&& board[pos.y - 1][pos.x + 1].played_by == player
				&& board[pos.y - 2][pos.x + 2].played_by == player
				&& board[pos.y - 3][pos.x + 3].played_by == player)
				return (true);
		}
	}

	for (pos.x = 0; pos.x <= game->rows - 3; pos.x++)
	{
		for (pos.y = game->rows - 4; pos.y >= 0; pos.y--)
		{
			if (board[pos.y][pos.x].played_by == player
				&& board[pos.y + 1][pos.x + 1].played_by == player
				&& board[pos.y + 2][pos.x + 2].played_by == player
				&& board[pos.y + 3][pos.x + 3].played_by == player)
				return (true);
		}
	}

	return (false);
}

bool	check_valid_col(t_connect4 *game, t_pawn **board, int selected_col)
{
	if (selected_col < 0 || selected_col > game->rows)
		return (false);
	if (board[0][selected_col].played_by != Nobody)
		return (false);
	return (true);
}

int	get_valid_row(t_connect4 *game, t_pawn **board, int selected_col)
{
	int	row;

	row = game->rows - 1;
	while (board[row][selected_col].played_by != Nobody)
		row--;
	return (row);
}
