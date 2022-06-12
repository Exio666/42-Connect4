/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:15:36 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/12 09:27:31 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

bool	check_win_row(t_connect4 *backpack)
{
	int suite = 0;
	Player actual;
	for (int actual_row = 0; actual_row < (int)backpack->cols; actual_row++)
	{
		for (int i = 0; i < (int)backpack->rows; i++)
		{
			suite = 0;
			actual = backpack->board[i][actual_row].played_by;
			for (int actual_line = 0; actual_line + i < (int)backpack->rows && actual != Nobody; actual_line++)
			{
				if (backpack->board[actual_line + i][actual_row].played_by == actual)
					suite++;
				else
					break;
				if (suite == 4)
					return true;
			}
		}
	}
	return false;
}
/*{
	int suite = 0;
	
	(void)y;
	for (int i = 0; i < backpack->rows && suite != 4; i++)
	{
		if (backpack->board[i][x].played_by == player)
			suite++;
		else if (suite != 4)
			suite = 0;
	}
	if (suite == 4)
		return true;
	return false;
}*/

bool	check_win_line(t_connect4 *backpack)
{
	int suite = 0;
	Player actual;
	for (int actual_line = 0; actual_line < (int)backpack->rows; actual_line++)
	{
		for (int i = 0; i < (int)backpack->cols; i++)
		{
			suite = 0;
			actual = backpack->board[actual_line][i].played_by;
			for (int actual_row = 0; actual_row + i < (int)backpack->cols && actual != Nobody; actual_row++)
			{
				if (backpack->board[actual_line][actual_row + i].played_by == actual)
					suite++;
				else
					break;
				if (suite == 4)
					return true;
			}
		}
	}
	return false;
}
/*{
	int suite = 0;
	
	(void)x;
	for (int i = 0; i < backpack->cols && suite != 4; i++)
	{
		if (backpack->board[y][i].played_by == player)
			suite++;
		else
			suite = 0;
	}
	if (suite == 4)
		return true;
	return false;
}*/


bool check_win_diag(t_connect4 *backpack)
{
	int suite = 0;
	Player actual;
	for (int actual_row = 0; actual_row < (int)backpack->cols; actual_row++)
	{
		for (int actual_line = 0; actual_line < (int)backpack->rows; actual_line++)
		{
			suite = 0;
			actual = backpack->board[actual_line][actual_row].played_by;
			for (int i = 0; actual != Nobody && actual_line + i < (int)backpack->rows && actual_row - i >= 0; i++)
			{
				if (backpack->board[actual_line + i][actual_row - i].played_by == actual)
					suite++;
				else
					break;
				if (suite == 4)
					return true;
				
			}
			suite = 0;
			for (int i = 0; actual != Nobody && actual_line - i >= 0 && actual_row - i  >= 0; i++)
			{
				if (backpack->board[actual_line - i][actual_row - i].played_by == actual)
					suite++;
				else
					break;
				if (suite == 4)
					return true;
			}
		}
	}
	return false;
}