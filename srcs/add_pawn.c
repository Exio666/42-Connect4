/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pawn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:25:59 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/11 14:54:45 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	add_pawn(t_connect4 *backpack, unsigned int row, Player player)
{
	for (int i = (int)backpack->nb_line - 1; i >= 0; i--)
	{
		if (backpack->board[i][row].played_by == Nobody)
		{
			backpack->board[i][row].played_by = player;
			return (i);
		}
	}
	return (-1);
}

t_point	add_pawn_player(t_connect4 *backpack, Player player)
{
	char	*line;
	t_point	point;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (point);
		line[ft_strlen(line) - 1] = 0;
		point.x = ft_atoi(line) - 1;
		point.y = add_pawn(backpack, point.x, player);
		if (!check_int(line) || point.x < 0 || point.x >= (int)backpack->nb_row || point.y == -1)
		{
			printf("invalid position\n");
			continue ;
		}
		else
			return (point);
	}
}