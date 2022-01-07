#include "so_long.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	while (*(s1 + len_s1 - n) && *(s2 + len_s2 - n) && n != 0
		&& (*(s1 + len_s1 - n) == *(s2 + len_s2 - n)))
		n--;
	if ((*(s1 + len_s1 - n) != *(s2 + len_s2 - n) && n))
		return (*(unsigned char *)(s1 + len_s1 - n)
		- *(unsigned char *)(s2 + len_s2 - n));
	return (0);
}

//int	main(int argc, char **argv)
int	main(void)
{
	char *map_dir;
	//Quando for testar com argc, comentar este bloco
	map_dir = "map_test.ber";
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
	
}