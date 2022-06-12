/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:26:48 by plouvel           #+#    #+#             */
/*   Updated: 2022/06/12 16:07:19 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

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

t_window	get_pos_diagonal_window(t_pawn **board, Player player, t_position pos)
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

t_window	get_neg_diagonal_window(t_pawn **board, Player player, t_position pos)
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

long long	eval_window(t_window * window)
{
	long long	score;

	score = 0;
	if (window->equivalent == 4)
		score += 100;
	else if (window->equivalent == 3 && window->empty == 1)
		score += 5;
	else if (window->equivalent == 2 && window->empty == 2)
		score += 2;
	if (window->opponent == 3 && window->empty == 1)
		score -= 4;
	
	return (score);
}
