/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:22:09 by coder             #+#    #+#             */
/*   Updated: 2022/01/16 15:57:03 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	elements_verifier(char *map_arrayed, int *n_clct)//guarantee that it is a valid array (in new_gnl function)
{
	int	n_row;
	int	index;

	n_row = 1;
	index = 0;
	while (*(map_arrayed + index))
	{
		if (*(map_arrayed + index) == '\n')
			n_row++;
		index++;
	}
	if (!ft_strchr(map_arrayed, EXIT) || !ft_strchr(map_arrayed, COLLECTIBLE)
			|| !ft_strchr(map_arrayed, WALL) || !ft_strchr(map_arrayed, START))
			return (FALSE);
	while (*map_arrayed)
	{
		if(*(map_arrayed) == COLLECTIBLE)
			n_clct++;
		if ((*(map_arrayed) != COLLECTIBLE && *(map_arrayed) != EXIT
			&& *(map_arrayed) != WALL && *(map_arrayed) != START
			&& *(map_arrayed) != PATH && *(map_arrayed) != '\n'))
				return (FALSE);
		else
			map_arrayed++;
	}
	return (n_row);
}

int	map_format_verifier(char *map_arrayed)
{
	int	width_reference;
	int	i_element;
	int	i_row_begin;

	i_element = 0;
	while (*(map_arrayed + i_element) && *(map_arrayed + i_element) != '\n')
		i_element++;
	width_reference = i_element;
	while (*(map_arrayed + i_element))
	{
		i_row_begin = ++i_element;
		while (*(map_arrayed + i_element) != '\n' && *(map_arrayed + i_element))
			i_element++;
		if ((i_element - i_row_begin) != width_reference)
			return (FALSE);
	}
	if ((i_element - i_row_begin) != width_reference)
		return (FALSE);
	else
		return (width_reference);
}

int	matrix_creator(char **matrix, t_map *map, char *map_dir)
{
	int		index;
	int		map_fd;

	index = 0; //guarantee that the array has at least one character before enter in this function
	map_fd = open(map_dir, O_RDONLY);//this one is just for a test. I need to put argc, argv
	while (index < map->height)
	{
		matrix[index] = ft_get_next_line(map_fd, map->width + 1);//adapt get_next_line to get buffer_size
		index++;
	}
	return (TRUE);
}

int	map_border_verifier(char **map_matrix, t_map *map)
{
	int		i_row;
	int		i_column;

	i_row = 0;
	i_column = 0;
	printf("n_row = %d, n_column = %d\n", map->height, map->width);
	while (i_row < map->height)
	{
		//printf("i_row = %d, i_column = %d\n", i_row, i_column);
		//printf("element[%d][%d] =%c\n", i_row, i_column, map_matrix[i_row][i_column]);
		if ((i_row == 0 || i_row == map->height - 1 || i_column == 0
				|| i_column == map->width - 1)
			&& map_matrix[i_row][i_column] != WALL)
				return (FALSE);
		i_column++;
		if (i_column == map->width)
		{
			i_column = 0;
			i_row++;
		}
	}
	return (TRUE);
}

char	**map_validator(char *map_dir, t_map *map)
{
	char	*map_arrayed;
	int		map_fd;
	
	map_arrayed = NULL;
	map_fd = open(map_dir, O_RDONLY);
	map_arrayed = ft_file_to_array(map_fd);
	/* 	if (!map_arrayed)
			return (FALSE); *///Confirm if I can put this condition to return INVALID_MAP below. It is to when a name that is not of a file is inputed (so, the map does not exist).
	if (!map_arrayed || !(map->height = elements_verifier(map_arrayed, &map->n_clct))
		|| !(map->width = map_format_verifier(map_arrayed)))
	{
		printf("%s", INVALID_MAP);
		free(map_arrayed);
		return (FALSE);
	}
	free(map_arrayed);
	map->matrix = (char **) ft_calloc(map->height, sizeof(char *));//why do I need this +1 to correct the errors?
	matrix_creator(map->matrix, map, MAP_FILE);
	if (map_border_verifier(map->matrix, map) == FALSE)
	{
		printf("%s", "INVALID_MAP");
		while (map->height >= 0)
		{
			free(map->matrix[map->height - 1]);
			map->height--;
		}
		free(map->matrix);
		return (FALSE);
	}
	return (map->matrix);
}
