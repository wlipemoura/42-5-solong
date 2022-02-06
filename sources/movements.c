/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 07:05:28 by coder             #+#    #+#             */
/*   Updated: 2022/02/06 04:14:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_pos(t_map *map)
{
	map->player.x = 1;
	map->player.y = 1;
	while (map->matrix[map->player.y][map->player.x] != PLAYER)
	{
		if (map->player.x == map->width - 1)
		{
			map->player.x = 1;
			map->player.y++;
			continue ;
		}
		map->player.x ++;
	}
	return (0);
}

int	wall_handler(t_run_prog *run, int y_cur_pos, int x_cur_pos)
{
	if (run->map.matrix[run->map.player.y][run->map.player.x] == WALL)
	{
		run->map.player.y = y_cur_pos;
		run->map.player.x = x_cur_pos;
		return (TRUE);
	}
	else
		return (FALSE);
}

int	collectible_handler(t_map *map)
{
	if (map->matrix[map->player.y][map->player.x] == COLLECTIBLE)
	{
		map->matrix[map->player.y][map->player.x] = PATH;
		(map->n_clct)--;
		printf("Collectibles left: %d\n", map->n_clct);
		return (map->n_clct);
	}
	return (FALSE);
}

int	exit_handler(t_run_prog *run, int y_cur_pos, int x_cur_pos)
{
	if (run->map.matrix[run->map.player.y][run->map.player.x] == EXIT)
	{
		if (run->map.n_clct == 0)
		{
			run->end_game = 1;
			return (TRUE);
		}
		else
		{
			run->map.player.y = y_cur_pos;
			run->map.player.x = x_cur_pos;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	movement_handler(int keysym, t_run_prog *run)
{
	run->map.player.prev_x = run->map.player.x;
	run->map.player.prev_y = run->map.player.y;
	if (walk(keysym, run) == TRUE)
	{
		collectible_handler(&run->map);
		if (wall_handler(run, run->map.player.prev_y,
				run->map.player.prev_x) == FALSE
			&& (exit_handler(run, run->map.player.prev_y,
					run->map.player.prev_x) == FALSE))
		{
			ft_matrix_element_swap(run);
			count_steps(&run->map.n_steps);
		}
		if (run->end_game == 1)
		{
			count_steps(&run->map.n_steps);
			printf("YOU WON!\n");
			close_window(run);
		}
		print_image(run);
	}
	return (0);
}
