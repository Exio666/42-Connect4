/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:19:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/11 19:34:00 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"
#include <unistd.h>
#include <stdio.h>

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

void	drop_pawn(t_connect4 *game, t_position pos, Player player)
{
	game->board[pos.y][pos.x].played_by = player;
}

int first_player()
{
	srand (time(NULL));
	return rand() % 2;
}

int tab_is_full(t_connect4 *backpack)
{
	for (int actual_row = 0; actual_row < (int)backpack->cols; actual_row++)
	{
		for (int actual_line = 0; actual_line < (int)backpack->rows; actual_line++)
		{
			if (backpack->board[actual_line][actual_row].played_by == Nobody)
				return 0;
		}
	}
	return 1;
}

int main(int ac, char **av)
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
			if (check_win_row(&game, p.x, p.y, Human) || check_win_line(&game, p.x, p.y, Human) || check_win_diag(&game))
			{
				ft_printf("The humanity won\n");
				free_board(&game);
				return (0);
			}
		}
		{
			show_board(&game);
			p = add_pawn_player(&game, AI);
			if (check_win_row(&game, p.x, p.y, AI) || check_win_line(&game, p.x, p.y, AI) || check_win_diag(&game))
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
