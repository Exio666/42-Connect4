/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:07:32 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/11 18:00:03 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

bool	check_win_row(t_connect4 *backpack, int x, int y, Player player)
{
	int suite = 0;
	
	(void)y;
	for (unsigned int i = 0; i < backpack->nb_line && suite != 4; i++)
	{
		if (backpack->board[i][x].played_by == player)
			suite++;
		else if (suite != 4)
			suite = 0;
	}
	if (suite == 4)
		return true;
	return false;
}

bool	check_win_line(t_connect4 *backpack, int x, int y, Player player)
{
	int suite = 0;
	
	(void)x;
	for (unsigned int i = 0; i < backpack->nb_row && suite != 4; i++)
	{
		if (backpack->board[y][i].played_by == player)
			suite++;
		else
			suite = 0;
	}
	if (suite == 4)
		return true;
	return false;
}

bool check_win_diag(t_connect4 *backpack)
{
	int suite = 0;
	Player actual;
	for (int actual_row = 0; actual_row < (int)backpack->nb_row; actual_row++)
	{
		for (int actual_line = 0; actual_line < (int)backpack->nb_line; actual_line++)
		{
			suite = 0;
			actual = backpack->board[actual_line][actual_row].played_by;
			for (int i = 0; actual != Nobody && actual_line + i < (int)backpack->nb_line && actual_row - i >= 0; i++)
			{
				if (backpack->board[actual_line + i][actual_row - i].played_by == actual)
					suite++;
				else
					break;
				if (suite == 4)
					return true;
				
			}
			suite = 0;
			for (int i = 0; actual != Nobody && actual_line - i >= 0 && actual_row + i < (int)backpack->nb_row; i++)
			{
				if (backpack->board[actual_line - i][actual_row + i].played_by == actual)
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