/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:14:15 by bsavinel          #+#    #+#             */
/*   Updated: 2022/06/12 16:17:48 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	check_int(char *str)
{
	int			len;
	int			i;
	long int	nb;

	i = 0;
	len = ft_strlen(str);
	while (str[i] == '0' && i < len - 1)
		i++;
	len = ft_strlen(&str[i]);
	if (len > 10 || len <= 0)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	nb = ft_atoi_long(str);
	if (nb > 2147483647)
		return (0);
	return (1);
}

int first_check(int ac, char **av, t_connect4 *backpack)
{
	if (ac != 3)
	{
		ft_printf("Bad number of argument\n%s <cols> <rows>\n", av[0]);
		return (0);
	}
	backpack->cols = ft_atoi(av[1]);
	backpack->rows = ft_atoi(av[2]);
	if ((!check_int(av[1])) || backpack->cols < MIN_SIZE_COL || backpack->cols > MAX_SIZE_COL)
	{
		ft_printf("The first argument is bad, you have to choose a number between %d and %d\n", MIN_SIZE_COL, MAX_SIZE_COL);
		return (0);
	}
	if ((!check_int(av[2])) || backpack->rows < MIN_SIZE_ROW || backpack->rows > MAX_SIZE_ROW)
	{
		ft_printf("The second argument is bad, you have to choose a number between %d and %d\n", MIN_SIZE_ROW, MAX_SIZE_ROW);
		return (0);
	}
	return (1);
}
