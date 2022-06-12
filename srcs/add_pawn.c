/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pawn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:11:42 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/12 10:04:59 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void	drop_pawn(t_pawn **board, t_position pos, Player player)
{
	board[pos.y][pos.x].played_by = player;
}

int	add_pawn(t_connect4 *backpack, unsigned int row, Player player)
{
	for (int i = (int)backpack->rows - 1; i >= 0; i--)
	{
		if (backpack->board[i][row].played_by == Nobody)
		{
			backpack->board[i][row].played_by = player;
			return (i);
		}
	}
	return (-1);
}

t_position	add_pawn_player(t_connect4 *backpack, Player player)
{
	char		*line;
	t_position	point;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (point);
		line[ft_strlen(line) - 1] = 0;
		point.x = ft_atoi(line) - 1;
		if (!(!check_int(line) || point.x < 0 || point.x >= (int)backpack->cols))
			point.y = add_pawn(backpack, point.x, player);
		if (!check_int(line) || point.x < 0 || point.x >= (int)backpack->cols || point.y == -1)
		{
			free(line);
			ft_printf("invalid position\n");
			continue ;
		}
		else
		{
			free(line);
			return (point);
		}
	}
}