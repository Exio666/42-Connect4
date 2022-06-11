/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:07:32 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/11 11:17:07 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int check_win_raw(t_connect4 *backpack)
{
	int counter_AI = 0;
	int counter_HU = 0;
	for (int i = 0; i < backpack->nb_raw && counter_AI != 4 && counter_HU != 4; i++)
	{
		counter_AI = 0;
		counter_HU = 0;
		for (int j = 0; i < backpack->nb_line && counter_AI != 4 && counter_HU; i++)
		{
			if (backpack->board[i][j].played_by == AI)
			{
				counter_AI++;
				counter_HU = 0;
			}
			if (backpack->board[i][j].played_by == Human)
			{
				counter_HU++;
				counter_AI = 0;
			}
		}
	}
}

int check_win_raw(t_connect4 *backpack)
{
	int counter_AI = 0;
	int counter_HU = 0;

	for (int i = 0; i < backpack->nb_line && counter_AI != 4 && counter_HU != 4; i++)
	{
		counter_AI = 0;
		counter_HU = 0;
		for (int j = 0; i < backpack->nb_raw && counter_AI != 4 && counter_HU; i++)
		{
			if (backpack->board[j][i].played_by == AI)
			{
				counter_AI++;
				counter_HU = 0;
			}
			if (backpack->board[j][i].played_by == Human)
			{
				counter_HU++;
				counter_AI = 0;
			}
		}
	}
}

int check_win(t_connect4 *backpack)
{
	if (check_win_raw(backpack) || check_win_line(backpack) || check_win_dAIg_up(backpack) || check_win_dAIg_down(backpack))
		return (1);
	return (0);
}