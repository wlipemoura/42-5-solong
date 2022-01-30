/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 05:04:56 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 07:30:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_image(t_run_prog *run)
{
	run->sprt.left_path = "./assets/images/char_left_64.xpm";
	run->sprt.right_path = "./assets/images/char_right_64.xpm";
	run->sprt.up_path = "./assets/images/char_up_64.xpm";
	run->sprt.down_path = "./assets/images/char_down_64.xpm";
	run->sprt.floor_path = "./assets/images/grass_64.xpm";
	run->sprt.wall_path = "./assets/images/wall_64.xpm";
	run->sprt.colct_path = "./assets/images/collect_64.xpm";
	run->sprt.exit_path = "./assets/images/hole_64.xpm";
}

void	create_image(t_run_prog *run)
{
	run->sprt.left_img = mlx_xpm_file_to_image(run->ptr_mlx,
			run->sprt.left_path, &run->sprt.img_width, &run->sprt.img_height);
	run->sprt.right_img = mlx_xpm_file_to_image(run->ptr_mlx,
			run->sprt.right_path, &run->sprt.img_width, &run->sprt.img_height);
	run->sprt.up_img = mlx_xpm_file_to_image(run->ptr_mlx,
			run->sprt.up_path, &run->sprt.img_width, &run->sprt.img_height);
	run->sprt.down_img = mlx_xpm_file_to_image(run->ptr_mlx,
			run->sprt.down_path, &run->sprt.img_width, &run->sprt.img_height);
	run->sprt.floor_img = mlx_xpm_file_to_image(run->ptr_mlx,
			run->sprt.floor_path, &run->sprt.img_width, &run->sprt.img_height);
	run->sprt.wall_img = mlx_xpm_file_to_image(run->ptr_mlx,
			run->sprt.wall_path, &run->sprt.img_width, &run->sprt.img_height);
	run->sprt.colct_img = mlx_xpm_file_to_image(run->ptr_mlx,
			run->sprt.colct_path, &run->sprt.img_width, &run->sprt.img_height);
	run->sprt.exit_img = mlx_xpm_file_to_image(run->ptr_mlx,
			run->sprt.exit_path, &run->sprt.img_width, &run->sprt.img_height);
}

void	player_direction(t_run_prog *run, int *i_array, int *i_matrix)
{
	if (run->map.player.x > run->map.player.prev_x)
		mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
			run->sprt.right_img, *i_array * SIZE, *i_matrix * SIZE);
	else if (run->map.player.x < run->map.player.prev_x)
		mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
			run->sprt.left_img, *i_array * SIZE, *i_matrix * SIZE);
	else if (run->map.player.y > run->map.player.prev_y)
		mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
			run->sprt.down_img, *i_array * SIZE, *i_matrix * SIZE);
	else if (run->map.player.y < run->map.player.prev_y)
		mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
			run->sprt.up_img, *i_array * SIZE, *i_matrix * SIZE);
}

void	char_handler(t_run_prog *run, int *i_array, int *i_matrix)
{
	if (run->map.matrix[*i_matrix][*i_array] == 'P')
		player_direction(run, i_array, i_matrix);
	else if (run->map.matrix[*i_matrix][*i_array] == 'C')
		mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
			run->sprt.colct_img, *i_array * SIZE, *i_matrix * SIZE);
	else if (run->map.matrix[*i_matrix][*i_array] == '1')
		mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
			run->sprt.wall_img, *i_array * SIZE, *i_matrix * SIZE);
	else if (run->map.matrix[*i_matrix][*i_array] == '0')
		mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
			run->sprt.floor_img, *i_array * SIZE, *i_matrix * SIZE);
	else if (run->map.matrix[*i_matrix][*i_array] == 'E')
		mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
			run->sprt.exit_img, *i_array * SIZE, *i_matrix * SIZE);
}

void	print_image(t_run_prog *run)
{
	int	len_array;
	int	i_matrix;
	int	i_array;

	i_matrix = 0;
	i_array = 0;
	len_array = run->map.width;
	while (i_matrix < run->map.height)
	{
		while (i_array < len_array)
		{
			char_handler(run, &i_array, &i_matrix);
			i_array++;
		}
		i_array = 0;
		i_matrix++;
	}
}
