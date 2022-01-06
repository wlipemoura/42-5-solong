/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:14:24 by coder             #+#    #+#             */
/*   Updated: 2022/01/06 15:06:09 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./42-1-libft/libft.h"

/* 1. read a file 
- Is it empty? return error
- create a matrix to it;
- Is the map closed/surrounded by walls (1)? If dont, return error
- Do I have at least one exit (E)? If dont, return error
- Do I have at least one collectible (C)? If dont, return error
- Do I have at least one starting position? If dont, return error
- Is the map retangular? If dont, return error

1. What is the necessary number of rows and columns of the matrix? */

typedef struct s_map
{
	int	width;
	int	height;
}	t_map;

#define COLLECTIBLE 'C'
#define EXIT 'E'
#define WALL '1'
#define START 'P'
#define PATH '0'
#define TRUE 0 //?
#define FALSE 1 //?
//ONLY THE 5 EXPECTED ELEMENTS COMPOUND THE MAP?
int	elements_verifier(char *map_arrayed)
{
	if (!map_arrayed)
		return (FALSE);
	else
	{
		while (*map_arrayed)
		{
			if (*(map_arrayed + counter) != COLLECTIBLE
			&& *(map_arrayed + counter) != EXIT
			&& *(map_arrayed + counter) != WALL
			&& *(map_arrayed + counter) != START
			&& *(map_arrayed + counter) != PATH
			&& *(map_arrayed + counter) != '\n')
				return (FALSE);
			else
				return (TRUE);
			map_arrayed++;
		}
	}
}
//IS THE MAP RETANGULAR?
int	map_format_verifier(char *map_arrayed)//return width
{
	int	width_reference;
	int	i_element;
	int	i_row_begin;

	i_element = 0;
	while(*(map_arrayed + i_element) && *(map_arrayed + i_element) != '\n')
		i_element++;
	width_reference = i_element;
	while (*(map_arrayed + i_element))
	{
		i_row_begin = ++i_element;
		printf("i_row_begin = %d\n", i_row_begin);
		while (*(map_arrayed + i_element) != '\n' && *(map_arrayed + i_element))
			i_element++;
		printf("i_row_end = %d\n", i_element);
		if ((i_element - i_row_begin) != width_reference)
			return (FALSE);
	}
	if ((i_element - i_row_begin) != width_reference)
		return (FALSE);
	else
		return (width_reference);
}

int	matrix_height(char *map_arrayed)
{
	int	n_rows;
	int	index;

	n_rows = 1;
	index = 0;
	while (*(map_arrayed + index))
	{
		if (*(map_arrayed + index) == '\n')
			n_rows++;
		index++;
	}
	return (n_rows);
}

//CREATE A MATRIX TO VERIFY BORDERS
int	matrix_creator(char *map_arrayed, char **matrix, t_map map)//return height
{
	int		index;

	index = 0; //guarantee that the array has at least one character before enter in this function
	while (index < map.height)
	{
		matrix[index][0] = get_next_line(map_fd, map.width + 1);//adapt get_next_line to get buffer_size
		index++;
	}
	return (0);
}


//IS THE MAP ROUNDED BY WALLS?
int	map_border_verifier(char **map_matrix, t_map map)
{
	int		i_row;
	int		i_column;
	
	i_row = 0;
	i_column = 0;
	while (i_column < map.width)
	{
		if (map_matrix[i_line][i_column] != WALL)
			return (FALSE)
		else
			i_column++;
		if (i_line == 0)
		{
			i_line == map.height - 1;
			i_column == 0;
		}
	}
	while (i_line < map.height)
	{
		if (map_matrix[i_line][i_column] != WALL)
			return (FALSE)
		else
			i_line++;
		if (i_column == 0)
		{
			i_column == map.width - 1;
			i_line == 0;
		}
	}

}

int	map_verifier(int fd)
{
	static char	**matrix;
	char		*map_arrayed;
	t_map		map;
	int			i_row;

	map_arrayed = new_get_next_line(fd);
	if (!elements_verifier(map_arrayed))
		return (ERROR);
	else if (!(map_width=map_format_verifier(map_arrayed)))
		return (ERROR);
	map.height = map_height(map_arrayed);
	matrix = (char *) ft_calloc(map.height, sizeof(char *));
	matrix_creator(map_arrayed, matrix, (map){map.height, map.width});
}

