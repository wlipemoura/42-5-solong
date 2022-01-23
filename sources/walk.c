#include "../so_long.h"

void	count_steps(int *n_steps)
{
	(*n_steps)++;
	printf("You walked %d steps\n", *n_steps);
	return ;
}

int	walk_right(t_run_prog *run)
{
	int	x_cur_pos;
	int	y_cur_pos;

	x_cur_pos = run->map.player.x;
	y_cur_pos = run->map.player.y;
	if (wall_handler(run->map.matrix, run->map.player.y, run->map.player.x + 1) == TRUE
		|| (exit_handler(run, y_cur_pos, x_cur_pos + 1) == TRUE && run->end_game == 0))
			return (0);
	if (collectible_handler(run, y_cur_pos, x_cur_pos + 1) == TRUE
		||	run->map.matrix[y_cur_pos][x_cur_pos + 1] == PATH)
	{
		run->map.player.x++;
		run->map.matrix[y_cur_pos][x_cur_pos] = PATH;
		run->map.matrix[y_cur_pos][run->map.player.x] = PLAYER;
		count_steps(&run->map.n_steps);
	}
	return (0);
}

int	walk_left(t_run_prog *run)
{
	int	x_cur_pos;
	int	y_cur_pos;

	x_cur_pos = run->map.player.x;
	y_cur_pos = run->map.player.y;
	if (wall_handler(run->map.matrix, run->map.player.y, run->map.player.x - 1) == TRUE
		|| (exit_handler(run, y_cur_pos, x_cur_pos - 1) == TRUE && run->end_game == 0))
			return (0);
	if (collectible_handler(run, y_cur_pos, x_cur_pos - 1) == TRUE
		||	run->map.matrix[y_cur_pos][x_cur_pos - 1] == PATH)
	{
		run->map.player.x--;
		run->map.matrix[y_cur_pos][x_cur_pos] = PATH;
		run->map.matrix[y_cur_pos][run->map.player.x] = PLAYER;
		count_steps(&run->map.n_steps);
	}
	return (0);
}

int	walk_up(t_run_prog *run)
{
	int	x_cur_pos;
	int	y_cur_pos;

	x_cur_pos = run->map.player.x;
	y_cur_pos = run->map.player.y;
	if (wall_handler(run->map.matrix, run->map.player.y - 1, run->map.player.x) == TRUE
		|| (exit_handler(run, y_cur_pos - 1, x_cur_pos) == TRUE && run->end_game == 0))
			return (0);
	if (collectible_handler(run, y_cur_pos - 1, x_cur_pos) == TRUE
		||	run->map.matrix[y_cur_pos - 1][x_cur_pos] == PATH)
	{
		run->map.player.y--;
		run->map.matrix[y_cur_pos][x_cur_pos] = PATH;
		run->map.matrix[run->map.player.y][x_cur_pos] = PLAYER;
		count_steps(&run->map.n_steps);
	}
	return (0);
}

int	walk_down(t_run_prog *run)
{
	int	x_cur_pos;
	int	y_cur_pos;

	x_cur_pos = run->map.player.x;
	y_cur_pos = run->map.player.y;
	if (wall_handler(run->map.matrix, run->map.player.y + 1, run->map.player.x) == TRUE
		|| (exit_handler(run, y_cur_pos + 1, x_cur_pos) == TRUE && run->end_game == 0))
			return (0);
	if (collectible_handler(run, y_cur_pos + 1, x_cur_pos) == TRUE
		||	run->map.matrix[y_cur_pos + 1][x_cur_pos] == PATH)
	{
		run->map.player.y++;
		run->map.matrix[y_cur_pos][x_cur_pos] = PATH;
		run->map.matrix[run->map.player.y][x_cur_pos] = PLAYER;
		count_steps(&run->map.n_steps);
	}
	return (0);
}
