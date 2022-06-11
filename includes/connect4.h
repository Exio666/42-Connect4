/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:54:29 by plouvel           #+#    #+#             */
/*   Updated: 2022/06/11 10:09:59 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

# define COLOR_BLUE   "\033[94;1m"
# define COLOR_YELLOW "\033[93;1m"

typedef enum e_player
{
	Nobody,
	AI,
	Human
}			Player;

typedef struct e_pawn
{
	Player	played_by;
}				t_pawn;

typedef struct e_connect4
{
	t_pawn	**board;
}				t_connect4;

void	*free_board(t_pawn **board, unsigned int lines);

#endif
