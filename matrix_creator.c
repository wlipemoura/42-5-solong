
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 0 //?
#define FALSE 1 //?
/* int	matrix_creator(char *map_arrayed, char **matrix, t_map map)//return height
{
	int		index;

	index = 0; //guarantee that the array has at least one character before enter in this function
	while (index < map.height)
	{
		matrix[index][0] = get_next_line(map_fd, map.width + 1);//adapt get_next_line to get buffer_size
		index++;
	}
	return (0);
} */

typedef struct s_map
{
	int	width;
	int	height;
}	t_map;

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

int	main(void)
{
	char		*map_arrayed = "11111\n1EC11\n1P011\n11111";
	static char	**matrix;
	t_map		map;

	map.height = matrix_height(map_arrayed);
	map.width = map_format_verifier(map_arrayed);
	printf("Matrix height will be: %d\n", map.height);
	printf("Matrix width will be: %d\n", map.width);
	//matrix = (char *) ft_calloc(map.height, sizeof(char *));
	//matrix_creator(map_arrayed, matrix, (map){map.height, map.width});
}