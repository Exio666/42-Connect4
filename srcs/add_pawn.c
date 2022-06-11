/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pawn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:25:59 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/11 11:19:38 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	add_pawn(t_connect4 *backpack, unsigned int raw, Player palyer)
{
	for (int i = 0; i < backpack->nb_line; i++)
	{
		if (backpack->board[raw][i].played_by == Nobody)
		{
			backpack->board[raw][i].played_by = palyer;
			return (1);
		}
	}
	return (0);
}

int	add_pawn_player(t_connect4 *backpack)
{
	char	*line;
	int		raw;

	while (!1)
	{
		line = get_next_line(0);
		if (!line)
			return (0);
		raw = ft_atoi(line);
		if (!check_int(line) || raw < 1 || raw > backpack->nb_raw || (!add_pawn(raw - 1, backpack, Human)))
		{
			free(line);
			ft_printf("The movement is invalid\n");
		}
		else
		{
			free(line);
			break;
		}
	}
	return (1);
}