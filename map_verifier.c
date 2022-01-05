/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:14:24 by coder             #+#    #+#             */
/*   Updated: 2022/01/05 22:35:40 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./42-1-libft/libft.h"

1. read a file 
- Is it empty? return error
- create a matrix to it;
- Is the map closed/surrounded by walls (1)? If dont, return error
- Do I have at least one exit (E)? If dont, return error
- Do I have at least one collectible (C)? If dont, return error
- Do I have at least one starting position? If dont, return error
- Is the map retangular? If dont, return error

1. What is the necessary number of rows and columns of the matrix?

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
//CREATE A MATRIX TO VERIFY FORMAT AND BORDERS
int	matrix_creator(char *map_arrayed, int map_fd, char **matrix)//return height
{
	t_map		map;
	int			t_map.height;
	int			t_map.width;
	int			index;
	int			buffer_size;

	index = 0;
	t_map.height = 1; //guarantee that the array has at least one character before enter in this function
	buffer_size = ft_strlen(map_arrayed);
	while (*(map_arrayed + index))
	{
		if (*(map_arrayed + index) == '\n')
			t_map.height++;
	}
	index = 0;
	matrix = (*char) ft_calloc(t_map.height, sizeof(char *));
	while (t_map.height)
	{
		matrix[index][0] = get_next_line(map_fd, buffer_size);
		t_map.height--;
		index++;
	}
	t_map.height = index;
	return (t_map.height);
}
//IS THE MAP RETANGULAR?
int	map_format_verifier(char **map_matrix, int map_height)//return width
{
	int	*n_char_per_row;
	int	row_index;
	int	width_reference;

	row_index = 0;
	row_index_conference = 0;
	width_reference = ft_strlen(*map_matrix[row_index])
	while (row_index != map_height)
	{
		if(width_reference != ft_strlen(*map_matrix[row_index]))
			return (FALSE);
		else
			row_index++;
	}
	return (width_reference);
}
//IS THE MAP ROUNDED BY WALLS?
int	map_border_verifier(char **map_matrix, int map_height, int map_width)
{
	int		i_row;
	int		i_column;
	
	i_row = 0;
	i_column = 0;
	while (i_column < map_width)
	{
		if (map_matrix[i_line][i_column] != WALL)
			return (FALSE)
		else
			i_column++;
		if (i_line == 0)
		{
			i_line == map_height - 1;
			i_column == 0;
		}
	}
	while (i_line < map_height)
	{
		if (map_matrix[i_line][i_column] != WALL)
			return (FALSE)
		else
			i_line++;
		if (i_column == 0)
		{
			i_column == map_width - 1;
			i_line == 0;
		}
	}

}

char	*new_get_next_line(int fd)
{
	static char	*line = NULL;
	char		*auxiliar;
	int			end_file_identifier;

	end_file_identifier = 1;
	auxiliar = ft_calloc (1 + 1, sizeof(char));
	end_file_identifier = read(fd, auxiliar, BUFFER_SIZE);
	if (fd < 0 || (!*auxiliar && !line) || !auxiliar || read(fd, auxiliar, 0))
		return (ft_strjoin_and_free(&auxiliar, &auxiliar, 1));
	if (line && *auxiliar)
		line = ft_strjoin_and_free(&line, &auxiliar, 0);
	else if (*auxiliar)
		line = ft_strjoin_and_free(&auxiliar, &line, 0);
	else if (end_file_identifier == 0 && line)
		return (ft_strjoin_and_free(&line, &auxiliar, 0));
	return (get_next_line(fd));
}

int	map_verifier(int fd)
{
	static char	**matrix;
	static char	*map_arrayed;
	char		*auxiliar;
	int			end_file_identifier;

	end_file_identifier = 1;
	map_arrayed = get_next_line(fd);

	end_file_identifier = read(fd, auxiliar, 1);

	while (read())
	
}

