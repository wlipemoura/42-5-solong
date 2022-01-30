/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:20:47 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 15:17:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_matrix_creator(t_map *map)
{
	int		index;
	int		map_fd;

	index = 0;
	map_fd = open(map->map_path, O_RDONLY);
	while (index < map->height)
	{
		map->matrix[index] = ft_get_next_line(map_fd, map->width + 1);
		index++;
	}
	return (TRUE);
}
