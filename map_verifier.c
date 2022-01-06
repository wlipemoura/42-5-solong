#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./42-1-libft/libft.h"

#define COLLECTIBLE 'C'
#define EXIT 'E'
#define WALL '1'
#define START 'P'
#define PATH '0'
#define TRUE 0 //?
#define FALSE 1 //?

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

char	*new_get_next_line(int fd);

int	elements_verifier(char *map_arrayed)//return height
{
	int	n_rows;
	int	index;

	n_rows = 1;
	index = 0;
	if (!map_arrayed)
		return (FALSE);
	while (*(map_arrayed + index))
	{
		if (*(map_arrayed + index) == '\n')
			n_rows++;
		index++;
	}
	while (*map_arrayed)
	{
		if (*(map_arrayed) != COLLECTIBLE
		&& *(map_arrayed) != EXIT && *(map_arrayed) != WALL
		&& *(map_arrayed) != START && *(map_arrayed) != PATH
		&& *(map_arrayed) != '\n')
			return (FALSE);
		else
			map_arrayed++;
	}
	return (n_rows);
}

int	matrix_creator(char *map_arrayed, char **matrix, t_map map)//return height
{
	int		index;
	int		map_fd;

	index = 0; //guarantee that the array has at least one character before enter in this function
	map_fd = open("mini_map.ber", O_RDONLY);//this one is just for a test. I need to put argc, argv
	while (index < map.height)
	{
		matrix[index] = get_next_line(map_fd, map.width + 1);//adapt get_next_line to get buffer_size
		index++;
	}
	return (0);
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

int	map_border_verifier(char **map_matrix, t_map map)
{
	int		i_row;
	int		i_column;
	
	i_row = 0;
	i_column = 0;
	
	while (i_row < map.height)
	{
		if((i_row == 0 || i_row == map.height - 1 || i_column == 0
		|| i_column == map.width - 1) && map_matrix[i_row][i_column] != WALL)
			return (FALSE);
		i_column++;
		if (i_column == map.width)
		{
			i_column = 0;
			i_row++;
		}
	}
	return (TRUE);
}

int	main(void)
{
	char		*map_arrayed;
	static char	**matrix;
	t_map		map;
	int			map_fd;

	map_fd = open("mini_map.ber", O_RDONLY);
	map_arrayed = new_get_next_line(map_fd);
	map.height = elements_verifier(map_arrayed);
	map.width = map_format_verifier(map_arrayed);
	printf("Matrix height will be: %d\n", map.height);
	printf("Matrix width will be: %d\n", map.width);
	matrix = (char **) ft_calloc(map.height, sizeof(char *));
	matrix_creator(map_arrayed, matrix, (t_map){map.height, map.width});
	///printf("Matrix[0][0] = %c\n", matrix[0][0]);
	//printf("Matrix[0][1] = %c\n", matrix[2][1]);
	//printf("Is it closed by walls? %d\n", (map_border_verifier(matrix, map)));
}
