/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:22:09 by coder             #+#    #+#             */
/*   Updated: 2022/01/23 22:59:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//guarantee that it is a valid array (in new_gnl function)
int	elements_verifier(char *map_arrayed, int *n_clct)
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
	if (!ft_strchr(map_arrayed, 'E') || !ft_strchr(map_arrayed, 'C')
		|| !ft_strchr(map_arrayed, '1') || !ft_strchr(map_arrayed, 'P'))
		return (FALSE);
	while (*map_arrayed)
	{
		if (*map_arrayed == 'C')
			(*n_clct)++;
		if ((*(map_arrayed) != 'C' && *(map_arrayed) != 'E'
				&& *(map_arrayed) != '1' && *(map_arrayed) != 'P'
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
//guarantee that the array has at least one character before enter in this function
int	matrix_creator(t_map *map)
{
	int		index;
	int		map_fd;

	index = 0;
	map_fd = open(map->map_path, O_RDONLY);
	while (index < map->height)
	{
		map->matrix[index] = ft_get_next_line(map_fd, map->width + 1);
		index++;
	}
	return (TRUE);
}

int	map_border_verifier(t_map *map)
{
	int		i_row;
	int		i_column;

	i_row = 0;
	i_column = 0;
	while (i_row < map->height)
	{
		if ((i_row == 0 || i_row == map->height - 1 || i_column == 0
				|| i_column == map->width - 1)
			&& map->matrix[i_row][i_column] != '1')
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
/* 	if (!map_arrayed)
		return (FALSE); *///Confirm if I can put this condition to return INVALID_MAP below. It is to when a name that is not of a file is inputed (so, the map does not exist).
char	**map_validator(t_map *map)
{
	char	*map_arrayed;
	int		map_fd;
	
	map_arrayed = NULL;
	map_fd = open(map->map_path, O_RDONLY);
	map_arrayed = ft_file_to_array(map_fd);

	if (!map_arrayed 
		|| !(map->height = elements_verifier(map_arrayed, &map->n_clct))
		|| !(map->width = map_format_verifier(map_arrayed)))
	{
		printf("%s", INVALID_MAP);
		free(map_arrayed);
		return (FALSE);
	}
	free(map_arrayed);
	map->matrix = (char **) ft_calloc(map->height, sizeof(char *));
	matrix_creator(map);
	if (map_border_verifier(map) == FALSE)
	{
		printf("%s", INVALID_MAP);
		while (map->height > 0)
		{
			free(map->matrix[map->height - 1]);
			map->height--;
		}
		free(map->matrix);
		return (FALSE);
	}
	return (map->matrix);
}
