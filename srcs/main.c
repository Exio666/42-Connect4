/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:19:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/12 13:45:12 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

int	first_player()
{
	srand (time(NULL));
	return rand() % 2;
}

int	main(int ac, char **av)
{
	t_connect4	game;
	int first;

	if (!first_check(ac, av))
		return (1);
	first = first_player();
	game.rows = ft_atoi(av[1]);
	game.cols = ft_atoi(av[2]);
	game.board = create_board(&game, game.rows, game.cols);
	if (!game.board)
		return (1);
	while (!tab_is_full(&game))
	{
		if (first)
		{
			show_board(&game);
			add_pawn_player(&game, Human);
			if (check_win_row(&game) || check_win_line(&game) || check_win_diag(&game))
			{
				show_board(&game);
				ft_printf("The humanity won\n");
				free_board(&game);
				return (0);
			}
		}
		{
			show_board(&game);
			add_pawn(&game, pick_best_move(&game, AI), AI);
			if (check_win_row(&game) || check_win_line(&game) || check_win_diag(&game))
			{
				show_board(&game);
				ft_printf("The IA is just superior\n");
				free_board(&game);
				return (0);
			}
		}
		first = 1;
	}
	show_board(&game);
	ft_printf("Nobody won, try again\n");
	free_board(&game);
	return (0);
}
