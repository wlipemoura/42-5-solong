/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:22:09 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 04:58:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//guarantee that it is a valid array (in new_gnl function)
//map == map_arreyed here. number of lines was not favorable with that name.
int	elements_verifier(char *map, int *n_clct)
{
	int	n_row;
	int	index;

	n_row = 1;
	index = 0;
	while (*(map + index))
	{
		if (*(map + index) == '\n')
			n_row++;
		index++;
	}
	if (!ft_strchr(map, 'E') || !ft_strchr(map, 'C') || !ft_strchr(map, '1')
		|| !ft_strchr(map, 'P'))
		return (FALSE);
	while (*map)
	{
		if (*map == 'C')
			(*n_clct)++;
		if ((*(map) != 'C' && *(map) != 'E' && *(map) != '1' && *(map) != 'P'
				&& *(map) != PATH && *(map) != '\n'))
			return (FALSE);
		else
			map++;
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
//guarantee that the array has at least one character before enter in 
//this function

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

char	**map_validator(t_run_prog *run)
{
	char	*map_arrayed;
	int		map_fd;

	map_fd = open(run->map.map_path, O_RDONLY);
	map_arrayed = ft_file_to_array(map_fd);
	run->map.height = elements_verifier(map_arrayed, &run->map.n_clct);
	run->map.width = map_format_verifier(map_arrayed);
	if (!map_arrayed || !run->map.height || !run->map.width)
	{
		printf("%s", INVALID_MAP);
		free(map_arrayed);
		return (FALSE);
	}
	free(map_arrayed);
	run->map.matrix = (char **) ft_calloc(run->map.height, sizeof(char *));
	ft_matrix_creator(&run->map);
	if (map_border_verifier(&run->map) == FALSE)
	{
		printf("%s", INVALID_MAP);
		free_matrix(run);
		return (FALSE);
	}
	return (run->map.matrix);
}
