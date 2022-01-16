#include "so_long.h"

int	player_pos(t_map *map)
{
	map->player.x = 1;
	map->player.y = 1;
	while(map->matrix[map->player.y][map->player.x] != 'P')
	{
		if(map->player.x == map->width - 1)
		{
			map->player.x  = 1;
			map->player.y++;
			continue ;
		}
		map->player.x ++;
	}
	return (0);
}

int	wall_handler(t_map *map)
{
	if (map->matrix[map->player.y][map->player.x] == WALL)
		return (TRUE);
	else
		return (FALSE);
}

int	collectible_handler(t_map *map)
{
	if (map->matrix[map->player.y][map->player.x] == COLLECTIBLE)
	{
		map->matrix[map->player.y][map->player.x] = PATH;
		(map->n_clct)--;
		return (map->n_clct);
	}
	return (FALSE);
}

int	exit_handler(t_map *map, t_run_prog *run)
{
	if (map->matrix[map->player.y][map->player.x] == EXIT)
	{
		if (map->n_clct == 0)
		{
			printf("YOU WON!");
			run->end_game = 1;//END_GAME
			return (TRUE);//TRUE = end game
		}
		else
			return (TRUE);
	}
	return (FALSE);
}

/* int	enemy_handler()
{

} */
/*
int	move(t_map *map, int keysym, t_run_prog *run)
{
	int	x_cur_pos;
	int	y_cur_pos;

	x_cur_pos = map->player.x;
	y_cur_pos = map->player.y;
	while (1)
	{
		if (keysym == XK_Right || keysym == XK_d || keysym == XK_D)
			map->player.x++;
		if (keysym == XK_Left || keysym == XK_a || keysym == XK_A)
			map->player.x--;
		if (keysym == XK_Up || keysym == XK_w || keysym == XK_W)
			map->player.y--;
		if (keysym == XK_Down || keysym == XK_s || keysym == XK_S)
			map->player.y++;
		collectible_handler(map);
		if (exit_handler(map, run) == TRUE && run->end_game == 1)
			return (TRUE);
		if (wall_handler(map) == FALSE
			&& (exit_handler(map, run) == FALSE && run->end_game == 0))
		{
			ft_matrix_element_swap(map->matrix, y_cur_pos, x_cur_pos,
									map->player.x, map->player.y);
			ft_2d_array_print(map->matrix);
		}
	}
}*/
