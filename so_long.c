/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:21:20 by coder             #+#    #+#             */
/*   Updated: 2022/01/14 01:48:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_validator(char *map_dir, t_map *map);//(char *map_dir, t_map map)
//int		map_on_screen(t_game *game, char **matrix);

int	main(void)
{
	int		argc = 2;
	//t_game	*game;
	t_map	map;

	map.height = 0;
	map.width = 0;
	if (argc < 2 || ft_strrncmp(MAP_FILE, ".ber", 4) != 0)
	{
		printf("%s", INVALID_MAP);
		return (FALSE);
	}
	else
		map.matrix = map_validator(MAP_FILE, &map);//(t_game *game)
	//map_on_screen(game, map.matrix);
	//mlx_loop(game->ptr_mlx);
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
	if (argc < 2 || ft_strrncmp(MAP_FILE, ".ber", 4) != 0)
	{
		printf("%s", INVALID_MAP);
		return (FALSE);
	}
	else
		matrix = map_validator(MAP_FILE);//(t_game *game)
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
	if (argc < 2 || ft_strrncmp(MAP_FILE, ".ber", 4) != 0)
	{
		printf("%s", INVALID_MAP);
		return (FALSE);
	}
	else
		matrix = map_validator(MAP_FILE);
	while (height >= 0)
	{
		free(matrix[height - 1]);
		height--;
	}
	free(matrix);
}
 */
