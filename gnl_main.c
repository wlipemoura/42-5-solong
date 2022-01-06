#include "42-1-libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd = open("subject.ber", O_RDONLY);
	printf("O mapa em formato de array é: %s\n", ft_get_next_line(fd, 12));
/* 	char	*array;
	array = ft_file_to_array(fd);
	printf("O mapa em formato de array é: %s\n", array); */
	
}
