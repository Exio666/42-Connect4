/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:50:42 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/07 11:43:41 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}
