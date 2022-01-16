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
		return (FALSE);
	else
		return (TRUE);
}
/*
int	collectible_handler(t_map *map)
{
	if (map->matrix[map->player.y][map->player.x] == COLLECTIBLE)
		//put an empty background on this position
	return (0);
}

int	exit_handler()
{

}

int	enemy_handler()
{

}
*/
int	move(t_map *map, int keysym)
{
	int	x_cur_pos;
	int	y_cur_pos;

	x_cur_pos = map->player.x;
	y_cur_pos = map->player.y;
	if (keysym == XK_Right || keysym == XK_d || keysym == XK_D)
		map->player.x++;
	if (keysym == XK_Left || keysym == XK_a || keysym == XK_A)
		map->player.x--;
	if (keysym == XK_Up || keysym == XK_w || keysym == XK_W)
		map->player.y--;
	if (keysym == XK_Down || keysym == XK_s || keysym == XK_S)
		map->player.y++;
	ft_matrix_element_swap(map->matrix, y_cur_pos, x_cur_pos,
							map->player.x, map->player.y);
	
}
/* 
int	main(void)
{
	t_plr_pos	position;

	player_pos(blabla, &position, map);
	printf("Posição X = %d", position.x);
	printf("Posição Y = %d", position.y);
	return ;
} */