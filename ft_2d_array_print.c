#include <stdio.h>
#include "so_long.h"

size_t	ft_strlen(const char *s);

int ft_2d_array_print(char **matrix, t_map map)//função apenas para testar
{
	int	len_array;
	int	i_matrix;
	int	i_array;

	i_matrix = 0;
	i_array = 0;
	len_array = map.width;
	while(i_matrix < map.height)
	{
		while (i_array < len_array)
		{
			printf("%c", matrix[i_matrix][i_array]);
			i_array++;
		}
		i_array = 0;
		i_matrix++;
		printf("\n");
	}
	printf("--------------------\n");
}
