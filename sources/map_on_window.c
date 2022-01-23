/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_on_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:54:12 by coder             #+#    #+#             */
/*   Updated: 2022/01/23 22:59:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_no_event(void *data) //Não faz sentido para o Dudu
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

void	free_matrix(t_run_prog *run)
{
	while (run->map.height > 0)
	{
		free(run->map.matrix[run->map.height - 1]);
		run->map.height--;
	}
	free(run->map.matrix);
	return ;
}

int	close_window(t_run_prog *run)
{
	mlx_destroy_window(run->ptr_mlx, run->ptr_win);
	mlx_destroy_display(run->ptr_mlx);
	free(run->ptr_mlx);
	free_matrix(run);
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

int	open_window(t_run_prog *run)
{
	run->ptr_mlx = mlx_init();
	if (run->ptr_mlx == NULL)
		return(MLX_ERROR);
	run->ptr_win = mlx_new_window(run->ptr_mlx, run->map.width * TILE_SIZE,
					run->map.height * TILE_SIZE, WINDOW_TITLE);
		if (run->ptr_win == NULL)//Why here I need to free and in ptr_mlx I dont?
		{
			free(run->ptr_win);
			return (MLX_ERROR);
		}
	image_workflow(run);
	mlx_hook(run->ptr_win, 9, 1L << 21, &image_workflow, run);
	mlx_hook(run->ptr_win, KeyRelease, KeyReleaseMask, &move, run);
	mlx_hook(run->ptr_win, KeyPress, KeyPressMask, &close_win_command, run); /* ADDED */
	mlx_hook(run->ptr_win, 33, 1L<<1, &close_window, run);//entender melhor essa função - fechar clicando no botão do mouse
	mlx_loop(run->ptr_mlx);
	return (0);
}
