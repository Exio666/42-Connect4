/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:19:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/12 15:33:55 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

Player	first_player()
{
	srand (time(NULL));
	if (rand() % 2 == 0)
		return AI;
	return Human;
}

bool	can_continue(t_connect4 *game)
{
	if (game->current_player == Human)
		show_board(game);
	if (check_win_move(game, game->board, AI))
	{
		ft_putstr_fd("AI Won !\n", 0);
		return (false);
	}
	else if (check_win_move(game, game->board, Human))
	{
		ft_putstr_fd("You won !\n", 0);
		return (false);
	}
	else if (board_is_full(game))
	{
		ft_putstr_fd("The game is over.\n", 0);
		return (false);
	}
	return (true);
}

int	get_user_input(t_connect4 *game)
{
	char	*line;
	int		col;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			continue ;
		line[ft_strlen(line) - 1] = 0;
		col = ft_atoi(line) - 1;
		if (check_int(line) && check_valid_col(game, game->board, col))
		{
			free(line);
			return (col);
		}
		else
			ft_putstr_fd("Invalid position.\n", 0);
		free(line);
	}
}

int	main(int ac, char **av)
{
	t_connect4	game;

	if (!first_check(ac, av, &game))
		return (1);
	game.current_player = first_player();
	game.board = create_board(&game);
	game.board[0][game.cols - 1].played_by = Nobody;
	if (!game.board)
		return (1);
	while (can_continue(&game))
	{
		t_position	playing_pos;

		if (game.current_player == Human)
			playing_pos.x = get_user_input(&game);
		else
		{
			t_minimax	ret_minimax;

			ret_minimax = minimax(&game, game.board, 5, true);
			playing_pos.x = ret_minimax.col;
		}
		playing_pos.y = get_valid_row(&game, game.board, playing_pos.x);
		drop_pawn(game.board, playing_pos, game.current_player);
		(game.current_player == AI) ? (game.current_player = Human) : (game.current_player = AI);
	}
	free_board(&game, game.board);
	return (0);
}
