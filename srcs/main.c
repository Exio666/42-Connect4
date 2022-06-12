/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:19:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/12 14:17:00 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

Player	first_player()
{
	srand (time(NULL));
	if (rand() % 2 == 0)
		return AI;
	return Human;
}

void play(t_connect4 *game, Player player)
{
	show_board(game);
	if (player == Human)
		add_pawn_player(game, player);
	else
		add_pawn(&game, pick_best_move(&game, player), player);
	if (check_win_row(game) || check_win_line(game) || check_win_diag(game))
		
	return Nobody;
}

int	main(int ac, char **av)
{
	t_connect4	game;

	if (!first_check(ac, av, &game))
		return (1);
	game.current_player = first_player();
	game.board = create_board(&game);
	if (!game.board)
		return (1);
	while (!tab_is_full(&game))
	{
		if (game.current_player == Human)
		{
			show_board(&game);
			add_pawn_player(&game, Human);
			if (check_win_row(&game) || check_win_line(&game) || check_win_diag(&game))
			{
				show_board(&game);
				ft_printf("The humanity won\n");
				free_board(&game, game.board);
				return (0);
			}
		}
		else
		{
			show_board(&game);
			add_pawn(&game, pick_best_move(&game, AI), AI);
			if (check_win_row(&game) || check_win_line(&game) || check_win_diag(&game))
			{
				show_board(&game);
				ft_printf("The IA is just superior\n");
				free_board(&game, game.board);
				return (0);
			}
		}
		(game.current_player == AI) ? (game.current_player = Human) : (game.current_player = AI);
	}
	show_board(&game);
	free_board(&game, game.board);
	if 
	ft_printf("Nobody won, try again\n");
	return (0);
}
