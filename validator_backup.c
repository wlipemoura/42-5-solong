#include "so_long.h"

//int	main(int argc, char **argv)
int	main(void)
{
	char	*map_arrayed;
	char	**matrix;
	t_map	map;
	int		map_fd;

	//tratar quando o arquivo não existir!!
	if (ft_strrncmp(MAP_FILE, ".ber", 4) != 0)
	{
		printf("%s", INVALID_MAP);
		return (FALSE);
	}
	else
	{
		map_fd = open(MAP_FILE, O_RDONLY);
		map_arrayed = ft_file_to_array(map_fd);
	/* 	if (!map_arrayed)
			return (FALSE); *///Confirm if I can put this condition to return INVALID_MAP below. It is to when a name that is not of a file is inputed (so, the map does not exist).
		if (!map_arrayed ||!(map.height = elements_verifier(map_arrayed))
			|| !(map.width = map_format_verifier(map_arrayed)))
		{
			printf("%s", INVALID_MAP);
			free(map_arrayed);
			return (FALSE);
		}
		free(map_arrayed);
		map_arrayed = NULL;
		//printf("Array = %s\n", map_arrayed);
		matrix = (char **) ft_calloc(map.height, sizeof(char *));//why do I need this +1 to correct the errors?
		matrix_creator(matrix, (t_map){map.width, map.height}, MAP_FILE);
		printf("Matrix[0][0] = %c\n", matrix[0][0]);
		//printf("Matrix[0][1] = %c\n", matrix[2][1]);
		if (map_border_verifier(matrix, map) == FALSE)
		{
			printf("%s", INVALID_MAP);
			free(matrix);
			return (FALSE);
		}
		free(matrix);
		//Quando for testar com argc, comentar este bloco
		

		/* if (argc < 2 || ft_strrncmp(argv[1], ".ber", 4) != 0)
		{
			printf("%s", INVALID_MAP);
			return (FALSE);
		}
		else
			map_verifier(argv[1]); */
		//gcc -g map_validator.c map_verifier.c ./42-1-libft/*.c -fsanitize=address && ./a.out mini_map.ber
		//or gcc -g map_validator.c map_verifier.c -L./42-1-libft/ -lft
	}
	
}
