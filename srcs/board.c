/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:00:08 by plouvel           #+#    #+#             */
/*   Updated: 2022/06/11 14:10:58 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

t_pawn	**create_board(unsigned int rows, unsigned int lines)
{
	t_pawn	**board;
	size_t	i;

	board = ft_calloc(lines + 1, sizeof(t_pawn *));
	if (!board)
		return (NULL);
	for (i = 0; i < lines; i++)
	{
		board[i] = ft_calloc(rows + 1, sizeof(t_pawn));
		if (!board[i])
			return (free_board(board));
		board[i][rows].endl = true;
	}
	board[lines] = NULL;
	return (board);
}

void	*free_board(t_pawn **board)
{
	for (size_t y = 0; board[y]; y++)
		free(board[y]);
	free(board);
	*board = NULL;
	return (NULL);
}

static void	print_col_indicator(unsigned int rows)
{
	ft_putstr_fd("\n\t", STDOUT_FILENO);
	for (size_t x = 0; x < rows; x++)
	{
		ft_putstr_fd("  ", STDOUT_FILENO);
		ft_putstr_fd(COLOR_CYAN, STDOUT_FILENO);
		ft_putnbr_fd((int) x + 1, STDOUT_FILENO);
		ft_putstr_fd(COLOR_RESET, STDOUT_FILENO);
		ft_putstr_fd(" ", STDOUT_FILENO);
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	show_board(t_pawn **board)
{
	bool	drow_line = true;
	size_t	x, y;

	ft_putstr_fd(HEADER, STDOUT_FILENO);
	for (y = 0; board[y];)
	{
		ft_putstr_fd("\t", STDOUT_FILENO);
		for (x = 0; !board[y][x].endl; x++)
		{
			if (drow_line)
				ft_putstr_fd("+---", STDOUT_FILENO);
			else
			{
				ft_putstr_fd("+ ", STDOUT_FILENO);
				if (board[y][x].played_by == AI)
					ft_putstr_fd(STR_PAWN_AI, STDOUT_FILENO);
				else if (board[y][x].played_by == Human)
					ft_putstr_fd(STR_PAWN_HUMAN, STDOUT_FILENO);
				else
					ft_putstr_fd(" ", STDOUT_FILENO);
				ft_putstr_fd(" ", STDOUT_FILENO);
			}
		}
		if (drow_line)
			drow_line = false;
		else
		{
			drow_line = true;
			y++;
		}
		ft_putstr_fd("+\n", STDOUT_FILENO);
	}

	/* Finish the board */ 

	ft_putstr_fd("\t", STDOUT_FILENO);
	for (size_t i = 0; i < x; i++)
		ft_putstr_fd("+---", STDOUT_FILENO);
	ft_putstr_fd("+\n", STDOUT_FILENO);

	print_col_indicator(x);
}
