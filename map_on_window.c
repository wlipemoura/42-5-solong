/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_on_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:54:12 by coder             #+#    #+#             */
/*   Updated: 2022/01/22 16:41:13 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data) //Não faz sentido para o Dudu
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	close_window(t_run_prog *run)
{
	mlx_destroy_window(run->ptr_mlx, run->ptr_win);
	mlx_destroy_display(run->ptr_mlx);
	free(run->ptr_mlx);
	exit (0);//Avisar que o programa está sendo fechado e tudo ocorreu bem - verificar mais a fundo essa função
	return (1);
}

int	close_win_command(int keysym, t_run_prog *run)
{
	if (keysym == XK_Escape
		|| keysym == XK_Q
		|| keysym == XK_q)
		close_window(run);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	open_window(t_run_prog *run)
{
	run->ptr_mlx = mlx_init();
	if (run->ptr_mlx == NULL)
		return(MLX_ERROR);
	run->ptr_win = mlx_new_window(run->ptr_mlx, run->map.width * 32,
					run->map.height * 32, WINDOW_TITLE);
		if (run->ptr_win == NULL)//Why here I need to free and in ptr_mlx I dont?
		{
			free(run->ptr_win);
			return (MLX_ERROR);
		}
	mlx_hook(run->ptr_win, KeyRelease, KeyReleaseMask, &move, run);
	mlx_hook(run->ptr_win, KeyPress, KeyPressMask, &close_win_command, run); /* ADDED */
	mlx_hook(run->ptr_win, 33, 1L<<1, &close_window, run);//entender melhor essa função - fechar clicando no botão do mouse
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
/*
int	window_handler(t_run_prog *run, t_map *map)
{
	open_window(run, map);
	close_win_command(keysym, run);
}
*/