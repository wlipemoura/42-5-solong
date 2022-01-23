#include "so_long.h"

void	load_image(t_run_prog *run)
{
	run->sprite.left_path = "./assets/images/char_left_64.xpm";
	run->sprite.right_path = "./assets/images/char_right_64.xpm";
	run->sprite.up_path = "./assets/images/char_up_64.xpm";
	run->sprite.down_path = "./assets/images/char_down_64.xpm";
	run->sprite.floor_path = "./assets/images/grass_64.xpm";
	run->sprite.wall_path = "./assets/images/wall_64.xpm";
	run->sprite.colct_path = "./assets/images/collect_64.xpm";
	run->sprite.exit_path = "./assets/images/hole_64.xpm";
}

void create_image(t_run_prog *run)
{
	run->sprite.left_img = mlx_xpm_file_to_image(run->ptr_mlx,
	 	run->sprite.left_path, &run->sprite.img_width, &run->sprite.img_height);
	run->sprite.right_img = mlx_xpm_file_to_image(run->ptr_mlx,
	 	run->sprite.right_path, &run->sprite.img_width, &run->sprite.img_height);
	run->sprite.up_img = mlx_xpm_file_to_image(run->ptr_mlx,
	 	run->sprite.up_path, &run->sprite.img_width, &run->sprite.img_height);
	run->sprite.down_img = mlx_xpm_file_to_image(run->ptr_mlx,
	 	run->sprite.down_path, &run->sprite.img_width, &run->sprite.img_height);
	run->sprite.floor_img = mlx_xpm_file_to_image(run->ptr_mlx,
	 	run->sprite.floor_path, &run->sprite.img_width, &run->sprite.img_height);
	run->sprite.wall_img = mlx_xpm_file_to_image(run->ptr_mlx,
	 	run->sprite.wall_path, &run->sprite.img_width, &run->sprite.img_height);
	run->sprite.colct_img = mlx_xpm_file_to_image(run->ptr_mlx,
	 	run->sprite.colct_path, &run->sprite.img_width, &run->sprite.img_height);
	run->sprite.exit_img = mlx_xpm_file_to_image(run->ptr_mlx,
	 	run->sprite.exit_path, &run->sprite.img_width, &run->sprite.img_height);
}

void	print_image(t_run_prog *run)
{
	int	len_array;
	int	i_matrix;
	int	i_array;

	i_matrix = 0;
	i_array = 0;
	len_array = run->map.width;
	while(i_matrix < run->map.height)
	{
		while (i_array < len_array)
		{
			 if (run->map.matrix[i_matrix][i_array] == 'P')
				mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
				run->sprite.right_img, i_array * TILE_SIZE, i_matrix * TILE_SIZE);
			else if (run->map.matrix[i_matrix][i_array] == 'C')
				mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
				run->sprite.colct_img, i_array * TILE_SIZE, i_matrix * TILE_SIZE);
			else if (run->map.matrix[i_matrix][i_array] == '1')
				mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
				run->sprite.wall_img, i_array * TILE_SIZE, i_matrix * TILE_SIZE);
			else if (run->map.matrix[i_matrix][i_array] == '0')
				mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
				run->sprite.floor_img, i_array * TILE_SIZE, i_matrix * TILE_SIZE);
			else if (run->map.matrix[i_matrix][i_array] == 'E')
				mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
				run->sprite.exit_img, i_array * TILE_SIZE, i_matrix * TILE_SIZE);
			i_array++;
		}
		i_array = 0;
		i_matrix++;
	}
}

int	image_workflow(t_run_prog *run)
{
	load_image(run);
	create_image(run);
	print_image(run);
	return (0);
}
