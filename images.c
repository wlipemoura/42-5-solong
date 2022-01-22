#include "so_long.h"

void	load_image(t_run_prog *run)
{
	run->sprite.path = "./assets/images/Terriermon.xpm";
}

void create_image(t_run_prog *run)
{
	run->sprite.img = mlx_xpm_file_to_image(run->ptr_mlx, run->sprite.path,
					&run->sprite.img_width, &run->sprite.img_height);
	printf("endereço = %p\n", run->sprite.img);
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
			if (run->map.matrix[i_matrix][i_array] == WALL)
				mlx_put_image_to_window(run->ptr_mlx, run->ptr_win,
				run->sprite.img, i_array * 32, i_matrix * 32);
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