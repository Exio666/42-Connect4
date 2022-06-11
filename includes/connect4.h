/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:54:29 by plouvel           #+#    #+#             */
/*   Updated: 2022/06/11 10:18:08 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

#include "all_lib.h"

# define COLOR_BLUE   "\033[94;1m"
# define COLOR_YELLOW "\033[93;1m"
# define MIN_SIZE_LINE 6
# define MAX_SIZE_LINE 10
# define MIN_SIZE_RAW 7
# define MAX_SIZE_RAW 10

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

int		check_int(char *str);
int		first_check(int ac, char **av);

#endif
