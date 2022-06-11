/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:07:32 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/11 14:23:56 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

bool	check_win_row(t_connect4 *backpack, int x, int y, Player player)
{
	ssize_t i;
	
	for (i = y + 1; i  < backpack->nb_row && backpack->board[y][x].played_by == player; i++)
		;
	if (i >= (y + 3))
		return (true);
	for (i = y - 1; i  >= 0 && backpack->board[y][x].played_by == player; i--)
		;
	if (i <= (y - 3))
		return (true);
	return (false);
}