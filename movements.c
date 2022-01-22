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

int	wall_handler(char **matrix, int player_y, int player_x)
{
	if (matrix[player_y][player_x] == WALL)
		return (TRUE);
	else
		return (FALSE);
}

int	collectible_handler(t_run_prog *run, int y, int x)
{
	if (run->map.matrix[y][x] == COLLECTIBLE)
	{
		(run->map.n_clct)--;
		printf("Number of collectible left: %d\n", run->map.n_clct);
		return (TRUE);
	}
	return (FALSE);
}

int	exit_handler(t_run_prog *run, int x, int y)
{
	if (run->map.matrix[y][x] == EXIT)
	{
		if (run->map.n_clct == 0)
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
	
	if (keysym == XK_Right || keysym == XK_d || keysym == XK_D)
		walk_right(run);
	if (keysym == XK_Left || keysym == XK_a || keysym == XK_A)
		walk_left(run);
	if (keysym == XK_Up || keysym == XK_w || keysym == XK_W)
		walk_up(run);
	if (keysym == XK_Down || keysym == XK_s || keysym == XK_S)
		walk_down(run);
	ft_2d_array_print(run->map.matrix, run->map);
	image_workflow(run);
	return (0);
}
