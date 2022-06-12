/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:19:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/12 13:36:26 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

int main(int ac, char **av)
{
	t_connect4	game;
	(void) ac;
	(void) av;

	srand(time(NULL));
	game.current_player = Human;
	game.board = create_board(&game, 7, 6);
	while (1)
	{
		char			input[5] = {0};
		t_position		selected_pos;

		show_board(&game);
		if (game.current_player == Human)
		{
			read(STDOUT_FILENO, input, 8);
			selected_pos.x = atoi(input) - 1;
			if (!check_valid_col(&game, game.board, selected_pos.x))
				printf("Invalid position\n");
		}
		else
		{
			t_minimax	minmax;

			minmax = minimax(&game, game.board, 5, true);
			selected_pos.x = minmax.col;
			printf("%d\n", selected_pos.x);
		}
		if (!check_valid_col(&game, game.board, selected_pos.x))
			continue ;
		selected_pos.y = get_valid_row(&game, game.board, selected_pos.x);
		drop_pawn(game.board, selected_pos, game.current_player);
		if (check_win_move(&game, game.board, game.current_player))
		{
			printf("%d won !\n", game.current_player);
			show_board(&game);
			return (0);
		}
		if (game.current_player == AI)
			game.current_player = Human;
		else
			game.current_player = AI;
	}
}
