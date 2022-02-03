/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_element_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 08:29:36 by coder             #+#    #+#             */
/*   Updated: 2022/02/03 03:46:43 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_matrix_element_swap(t_run_prog *run)
{
	char	a;
	char	p;

	if (!run->map.matrix)
		return (0);
	else if (!run->map.matrix[run->map.player.prev_y]
		|| !run->map.matrix[run->map.player.y])
		return (0);
	a = run->map.matrix[run->map.player.prev_y][run->map.player.prev_x];
	p = run->map.matrix[run->map.player.y][run->map.player.x];
	run->map.matrix[run->map.player.prev_y][run->map.player.prev_x] = p;
	run->map.matrix[run->map.player.y][run->map.player.x] = a;
	return (1);
}
