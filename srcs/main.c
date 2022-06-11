/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:19:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/11 16:54:36 by plouvel          ###   ########.fr       */
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

int main(int ac, char **av)
{
	t_connect4	game;

	game.current_player = Human;
	game.rows = 7;
	game.cols = 6;
	game.board = create_board(&game, 7, 6);
	while (1)
	{
		char			input[5] = {0};
		t_position		selected_pos;

		show_board(&game);
		read(STDOUT_FILENO, input, 5);
		selected_pos.x = atoi(input) - 1;
		if (check_valid_col(&game, selected_pos.x))
		{
			selected_pos.y = get_valid_row(&game, selected_pos.x);
			drop_pawn(&game, selected_pos, game.current_player);
		}
		else
			printf("Invalid position\n");
	}
}
