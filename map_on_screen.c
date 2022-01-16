#include "so_long.h"
/*
int	close_window(t_run_prog *run)
{
	mlx_destroy_window(run->ptr_mlx, run->ptr_win);
	mlx_destroy_display(run->ptr_mlx);
	free(run->ptr_mlx);
	//why do not I need to free win_ptr?
}

int	close_win_command(int keysym, t_run_prog *run)
{
	if (keysym == XK_Escape
		|| keysym == XK_Q
		|| keysym == XK_q)
		close_window(run);
	mlx_hook(run->ptr_win, 33, 1L<<1, &close_window, &run);//entender melhor essa função - fechar clicando no botão do mouse
	return (0);
}

int	open_window(t_run_prog *run, t_map *map)
{
	run->ptr_mlx = mlx_init();
	if (run->ptr_mlx == NULL)
		return(MLX_ERROR);
	run->ptr_win = mlx_new_window(run->ptr_mlx, map->width,
					map->height, WINDOW_TITLE);
		if (run->ptr_win == NULL)//Why here I need to free and in ptr_mlx I dont?
		{
			free(run->ptr_win);
			return (MLX_ERROR);
		}
	//mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(run->ptr_win, &close_win_command, &run);
	mlx_loop(run->ptr_mlx);
	return (0);
}

/* int	map_on_screen(t_run_prog *run, char **matrix)
{
	mlx_xpm_file_to_image;//ponteiro que apontará para a imagem que está no diretório
	mlx_put_image_to_window;//passar para a tela a imagem criada no ponteiro acima
}
mlx_xpm_file_to_image;//ponteiro que apontará para a imagem que está no diretório
mlx_put_image_to_window;//passar para a tela a imagem criada no ponteiro acima */

int	window_handler(t_run_prog *run, t_map *map)
{
	open_window(run, map);
	close_win_command(keysym, run);
}
*/