# include <unistd.h>
# include <stdlib.h>
#include "get_next_line.h"

char	*ft_strjoin_and_free(char **s1, char **s2, int return_flag)
{
	char	*newstring;
	int		lens1;
	int		lens2;

	lens1 = ft_strlen (*s1);
	lens2 = ft_strlen (*s2);
	newstring = ft_calloc ((lens1 + lens2 + 1), sizeof (char));
	if (!newstring)
		return (NULL);
	ft_memmove(newstring, *s1, lens1);
	ft_memmove(newstring + lens1, *s2, lens2);
	free(*s2);
	*s2 = NULL;
	free(*s1);
	*s1 = NULL;
	if (return_flag)
	{
		free(newstring);
		newstring = NULL;
	}
	return (newstring);
}

char	*new_get_next_line(int fd)
{
	static char	*line = NULL;
	char		*auxiliar;
	int			end_file_identifier;

	end_file_identifier = 1;
	auxiliar = ft_calloc (1 + 1, sizeof(char));
	end_file_identifier = read(fd, auxiliar, 1);
	if (fd < 0 || (!*auxiliar && !line) || !auxiliar || read(fd, auxiliar, 0))
		return (ft_strjoin_and_free(&auxiliar, &auxiliar, 1));
	while(end_file_identifier != 0)
	{
		if (line && *auxiliar)
			line = ft_strjoin_and_free(&line, &auxiliar, 0);
		else if (*auxiliar)
			line = ft_strjoin_and_free(&auxiliar, &line, 0);
	}
	return (ft_strjoin_and_free(&line, &auxiliar, 0));
}

int	main(void)
{
	
	printf("O mapa em formato de array é: %s", new_get_next_line())
}
