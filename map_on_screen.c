#include "so_long.h"

int	map_on_screen(t_game *game, char **matrix)
{
	game->ptr_mlx = mlx_init();
	game->ptr_win = mlx_new_window(game->ptr_win, game->map.width,
					game->map.height, WINDOW_TITLE);
	return (0);
}

mlx_xpm_file_to_image;//ponteiro que apontará para a imagem que está no diretório
mlx_put_image_to_window;//passar para a tela a imagem criada no ponteiro acima
