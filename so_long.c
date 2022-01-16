/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:21:20 by coder             #+#    #+#             */
/*   Updated: 2022/01/16 17:58:06 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//char	**map_validator(char *map_dir, t_map *map);//(char *map_dir, t_map map)
//int		map_on_screen(t_game *game, char **matrix);
//clang -g ./sources/map_validator.c so_long.c movements.c ft_2d_array_print.c -L./libraries/libft/ -lft -lmlx -lXext -lX11

int	main(void)
{
	int		argc = 2;
	t_map		map;
	t_run_prog	run;

	map.height = 0;
	map.width = 0;
	map.n_clct = 0;
	if (argc < 2 || ft_strrncmp(MAP_PATH, ".ber", 4) != 0)
	{
		printf("%s", INVALID_MAP);
		return (FALSE);
	}
	else
		map.matrix = map_validator(MAP_PATH, &map);//(t_game *game)
	//ft_2d_array_print(map.matrix, map);
	//map_on_screen(game, map.matrix);
	//mlx_loop(game->ptr_mlx);
	player_pos(&map);
	//printf("matrix[1][1] = %c, matrix[1][2] = %c\n", map.matrix[1][1], map.matrix[1][2]);
	//ft_matrix_element_swap(map.matrix, 1, 1, 1, 2);
	//ft_2d_array_print(map.matrix, map);
	//printf("matrix[1][1] = %c, matrix[1][2] = %c\n", map.matrix[1][1], map.matrix[1][2]);
	//printf("player position X = %d, Y = %d\n", map.player.x, map.player.y);
	/* while (1)
	{
		move(&map, keysym, &run);
	} */
	open_window(&run, &map);
	while (map.height > 0)
	{
		free(map.matrix[map.height - 1]);
		map.height--;
	}
	free(map.matrix);
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
