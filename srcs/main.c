/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:19:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/11 14:49:43 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int main(int ac, char **av)
{
	t_connect4 backpack;

	if (!first_check(ac, av))
		return (1);
	backpack.nb_line = ft_atoi(av[2]);
	backpack.nb_row = ft_atoi(av[1]);
	backpack.board = create_board(backpack.nb_row, backpack.nb_line);
	while (1)
	{
		{
			show_board(backpack.board);
			t_point p = add_pawn_player(&backpack, Human);
			printf("(%u %u)\n", p.x, p.y);
		}
		{
			show_board(backpack.board);
			t_point p = add_pawn_player(&backpack, AI);
			printf("(%u %u)\n", p.x, p.y);
		}
	}
	
}
