#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd = open("subject.ber", O_RDONLY);
	printf("O mapa em formato de array é: %s\n", get_next_line(fd));
}