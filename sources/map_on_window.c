/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_on_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:54:12 by coder             #+#    #+#             */
/*   Updated: 2022/02/05 03:49:44 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_run_prog *run)
{
	mlx_destroy_image(run->ptr_mlx, run->sprt.colct_img);
	mlx_destroy_image(run->ptr_mlx, run->sprt.exit_img);
	mlx_destroy_image(run->ptr_mlx, run->sprt.floor_img);
	mlx_destroy_image(run->ptr_mlx, run->sprt.left_img);
	mlx_destroy_image(run->ptr_mlx, run->sprt.right_img);
	mlx_destroy_image(run->ptr_mlx, run->sprt.up_img);
	mlx_destroy_image(run->ptr_mlx, run->sprt.down_img);
	mlx_destroy_image(run->ptr_mlx, run->sprt.wall_img);
	return ;
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
	destroy_images(run);
	mlx_destroy_window(run->ptr_mlx, run->ptr_win);
	mlx_destroy_display(run->ptr_mlx);
	free(run->ptr_mlx);
	free_matrix(run);
	exit (0);
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
		return (MLX_ERROR);
	run->ptr_win = mlx_new_window(run->ptr_mlx, run->map.width * SIZE,
			run->map.height * SIZE, WINDOW_TITLE);
	if (run->ptr_win == NULL)
	{
		free(run->ptr_win);
		return (MLX_ERROR);
	}
	load_image(run);
	create_image(run);
	mlx_hook(run->ptr_win, FocusIn, FocusChangeMask, &print_image, run);
	mlx_expose_hook(run->ptr_win, &print_image, run);
	mlx_hook(run->ptr_win, KeyRelease, KeyReleaseMask, &move, run);
	mlx_hook(run->ptr_win, KeyPress, KeyPressMask, &close_win_command, run);
	mlx_hook(run->ptr_win, ClientMessage, KeyReleaseMask, &close_window, run);
	mlx_loop(run->ptr_mlx);
	return (0);
}
