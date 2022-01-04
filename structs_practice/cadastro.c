#include <stdio.h>
#include <stdlib.h> //alocação de memória
#include <string.h>

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
	t_livro	*livro_fav;
}	t_aluno;

t_livro	*create_livro(const char *titulo, unsigned int paginas, float preco)
{
	t_livro	*livro_reg;

	livro_reg = (t_livro *) calloc(1, sizeof(t_livro));
	strcpy(livro_reg->titulo, titulo);
	livro_reg->paginas = paginas;
	livro_reg->preco = preco;
	return (livro_reg);
}

void	print_livro(const t_livro *livro)
{
	printf("Titulo: %s\n", livro->titulo);
	printf("N paginas: %d\n", livro->paginas);
	printf("Preco: R$%.2f\n", livro->preco);
	return ;
}

void	destroy_livro(t_livro **livro)
{
	free(*livro);
	*livro = NULL;
}

t_aluno	*create_aluno(const char *nome, int idade, t_livro *livro_fav)
{
	t_aluno *aluno_reg;
	
	aluno_reg = (t_aluno *) calloc(1, sizeof(t_aluno));
	strcpy(aluno_reg->nome, nome);
	aluno_reg->idade = idade;
	aluno_reg->livro_fav = livro_fav;
	return (aluno_reg);
}

void	print_aluno(const t_aluno *aluno)
{
	printf("Nome: %s\n", aluno->nome);
	printf("Idade: %d\n", aluno->idade);
	print_livro(aluno->livro_fav);
	return ;
}

void	destroy_aluno(t_aluno **aluno)
{
	free(*aluno);
	*aluno = NULL;
}

int	main(void)
{
	t_livro *hp;
	t_livro *apocalipse;
	t_aluno *will;

	hp = create_livro("Harry Potter", 500, 150.25);
	apocalipse = create_livro("A batalha do apocalipse", 350, 120);
	will = create_aluno("Will", 24, apocalipse);
	print_aluno(will);
	//destroy_aluno(&will);
	//print_livro(hp);
	//destroy_livro(&hp);
	//print_aluno(will);

	return (0);
}

