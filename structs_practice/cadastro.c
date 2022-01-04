#include <stdio.h>
#include <stdlib.h> //alocação de memória

typedef struct s_livro
{
	char			titulo[100];
	unsigned int	paginas;
	float			preco;
}	t_livro;

typedef struct s_aluno
{
	char	nome[100];
	int		idade;
	t_livro	*livro;
}	t_aluno;

t_livro *create(const char *titulo, unsigned int paginas, float preco)
{

}

int delete

int print