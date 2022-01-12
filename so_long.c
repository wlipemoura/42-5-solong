/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:21:20 by coder             #+#    #+#             */
/*   Updated: 2022/01/13 00:35:12 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
char	**map_validator(char *map_dir);

int	main(void)
{
	char	**matrix;
	int		height;
	int		argc = 2;

	height = 6;
	if (argc < 2 || ft_strrncmp(MAP_FILE, ".ber", 4) != 0)
	{
		printf("%s", INVALID_MAP);
		return (FALSE);
	}
	else
		matrix = map_validator(MAP_FILE);
	while (height > 0)
	{
		free(matrix[height - 1]);
		height--;
	}
	free(matrix);
}

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
