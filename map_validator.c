#include "so_long.h"


//int	main(int argc, char **argv)
int	main(void)
{
	char *map_dir;
	//Quando for testar com argc, comentar este bloco
	map_dir = "map_test.ber";//tratar quando o arquivo não existir!!
	if (ft_strrncmp(map_dir, ".ber", 4) != 0)
	{
		printf("%s", INVALID_MAP);
		return (FALSE);
	}
	else
		map_verifier(map_dir);

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