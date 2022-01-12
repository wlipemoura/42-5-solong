#include "so_long.h"

int	player_pos(char **matrix, t_plr_pos *position, t_map map)
{
	position->x = 0;
	position->y = 1;
	while(matrix[position->x][position->y] != 'P')
	{
		x++;
		if(position->x == map.width - 1)
		{
			x = 0;
			y++;
		}

	}

}

int	main(void)
{
	t_plr_pos	position;

	player_pos(blabla, &position, map);
	printf("Posição X = %d", position.x);
	printf("Posição Y = %d", position.y);
	return ;
}