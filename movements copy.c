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

int	move(int keysym, t_run_prog *run)
{
	int	x_cur_pos;
	int	y_cur_pos;

	x_cur_pos = run->map.player.x;
	y_cur_pos = run->map.player.y;
	if (keysym == XK_Right || keysym == XK_d || keysym == XK_D)
	{
		run->map.player.x++;
		run->map.matrix[y_cur_pos][x_cur_pos] = PATH;
		run->map.matrix[y_cur_pos][run->map.player.x] = START;
	}
	if (keysym == XK_Left || keysym == XK_a || keysym == XK_A)
		run->map.player.x--;
	if (keysym == XK_Up || keysym == XK_w || keysym == XK_W)
		run->map.player.y--;
	if (keysym == XK_Down || keysym == XK_s || keysym == XK_S)
		run->map.player.y++;
	//collectible_handler(&run->map);
	printf("p_x = %d, p_y = %d\n", run->map.player.x, run->map.player.y);
	printf("x_cur = %d, y_cur = %d\n", x_cur_pos, y_cur_pos);
	//ft_matrix_element_swap(run->map.matrix, y_cur_pos, x_cur_pos,
	//							run->map.player.x, run->map.player.y);
	ft_2d_array_print(run->map.matrix, run->map);
	/* if (exit_handler(&run->map, run) == TRUE && run->end_game == 1)
		return (TRUE);
	if (wall_handler(&run->map) == FALSE
		&& (exit_handler(&run->map, run) == FALSE && run->end_game == 0))
	{
		ft_matrix_element_swap(run->map.matrix, y_cur_pos, x_cur_pos,
								run->map.player.x, run->map.player.y);
		//ft_2d_array_print(run->map.matrix, *map);
	} */
	//mlx_hook(run->ptr_win, KeyRelease, KeyReleaseMask, &move, &run);
	//mlx_hook(run->ptr_win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &run);
	//mlx_loop(run->ptr_mlx);
	return (0);
}
