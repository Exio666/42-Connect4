/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:29:27 by plouvel           #+#    #+#             */
/*   Updated: 2022/06/12 13:40:11 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"
#include <limits.h>

static Player	is_a_terminal_node(t_connect4 *game, t_pawn **board)
{
	if (check_win_move(game, board, AI))
		return (AI);
	if (check_win_move(game, board, Human))
		return (Human);
	for (int x = 0; x < game->cols; x++)
	{
		if (check_valid_col(game, board, x))
			return (Nobody);
	}
	return (End);
}

static t_minimax	new_minimax(int col, long long score)
{
	t_minimax	minimax;

	minimax.score = score;
	minimax.col = col;
	return (minimax);
}

t_minimax	minimax(t_connect4 *game, t_pawn **board, int depth, bool maxPlayer)
{
	Player	is_terminal_node;
	t_position	pos;
	t_minimax	ret_call, ret;

	is_terminal_node = is_a_terminal_node(game, board);
	if (is_terminal_node != Nobody)
	{
		if (is_terminal_node == AI)
			return (new_minimax(0, LLONG_MAX - 1));
		else if (is_terminal_node == Human)
			return (new_minimax(0, LLONG_MIN + 1));
		else
			return (new_minimax(0, 0));
	}
	else if (depth == 0)
		return (new_minimax(0, get_score(game, board, AI)));
	if (maxPlayer)
	{
		ret.score = LLONG_MIN;

		ret.col = rand() % (game->cols - 1);
		while (check_valid_col(game, board, ret.col) == false)
			ret.col = rand() % (game->cols + 1);

		for (pos.x = 0; pos.x < game->cols; pos.x++)
		{
			if (check_valid_col(game, board, pos.x))
			{
				pos.y = get_valid_row(game, board, pos.x);
				drop_pawn(board, pos, AI);
				ret_call = minimax(game, board, depth - 1, false);
				if (ret_call.score > ret.score)
				{
					ret.score = ret_call.score;
					ret.col = pos.x;
				}
				board[pos.y][pos.x].played_by = Nobody;
			}
		}
		return (ret);
	}
	else
	{
		ret.score = LLONG_MAX;

		ret.col = rand() % (game->cols - 1);
		while (check_valid_col(game, board, ret.col) == false)
			ret.col = rand() % (game->cols + 1);

		for (pos.x = 0; pos.x < game->cols; pos.x++)
		{
			if (check_valid_col(game, board, pos.x))
			{
				pos.y = get_valid_row(game, board, pos.x);
				drop_pawn(board, pos, Human);
				ret_call = minimax(game, board, depth - 1, true);
				if (ret_call.score < ret.score)
				{
					ret.score = ret_call.score;
					ret.col = pos.x;
				}
				board[pos.y][pos.x].played_by = Nobody;
			}
		}
		return (ret);
	}
}
