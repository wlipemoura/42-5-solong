/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:21:20 by coder             #+#    #+#             */
/*   Updated: 2022/01/22 17:00:35 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//char	**map_validator(char *map_dir, t_map *map);//(char *map_dir, t_map map)
//int		map_on_screen(t_game *game, char **matrix);
//clang -g ./sources/map_validator.c so_long.c movements.c ft_2d_array_print.c -L./libraries/libft/ -lft -lmlx -lXext -lX11

int	main(void)
{
	int		argc = 2;
	t_run_prog	run;

	ft_bzero(&run, sizeof(run));
	if (argc < 2 || ft_strrncmp(MAP_PATH, ".ber", 4) != 0)
	{
		printf("%s", INVALID_MAP);
		return (FALSE);
	}
	else
		map_validator(MAP_PATH, &run.map);//(t_game *game)
	//ft_2d_array_print(run->map.matrix, map);
	//map_on_screen(game, run->map.matrix);
	//mlx_loop(game->ptr_mlx);
	player_pos(&run.map);
	ft_2d_array_print(run.map.matrix, run.map);
	printf("p_x = %d, p_y = %d\n", run.map.player.x, run.map.player.y);
	//printf("matrix[1][1] = %c, matrix[1][2] = %c\n", run->map.matrix[1][1], run->map.matrix[1][2]);
	//ft_matrix_element_swap(run->map.matrix, 1, 1, 1, 2);
	//ft_2d_array_print(run->map.matrix, map);
	//printf("matrix[1][1] = %c, matrix[1][2] = %c\n", run->map.matrix[1][1], run->map.matrix[1][2]);
	//printf("player position X = %d, Y = %d\n", run->map.player.x, run->map.player.y);
	/* while (1)
	{
		move(&map, keysym, &run);
	} */
	open_window(&run);
	while (run.map.height > 0)//posso ter este while na função que fecha tudo, dentro de outra função (free_matrix)
	{
		free(run.map.matrix[run.map.height - 1]);
		run.map.height--;
	}
	free(run.map.matrix);
}

/* int	main(void)
{
	char	**matrix;
	int		height;
	int		argc = 2;
	t_game	*game;
	//t_map	map;

	height = 6;
	if (argc < 2 || ft_strrncmp(MAP_PATH, ".ber", 4) != 0)
	{
		printf("%s", INVALID_MAP);
		return (FALSE);
	}
	else
		matrix = map_validator(MAP_PATH);//(t_game *game)
	map_on_screen(game, matrix);
	mlx_loop(game->ptr_mlx);
	while (height > 0)
	{
		free(matrix[height - 1]);
		height--;
	}
	free(matrix);
} */

/* 
int	main(int argc, char **argv)
{
	char	**matrix;
	int		height;

	height = 6;
	if (argc < 2 || ft_strrncmp(MAP_PATH, ".ber", 4) != 0)
	{
		printf("%s", INVALID_MAP);
		return (FALSE);
	}
	else
		matrix = map_validator(MAP_PATH);
	while (height >= 0)
	{
		free(matrix[height - 1]);
		height--;
	}
	free(matrix);
}
 */
