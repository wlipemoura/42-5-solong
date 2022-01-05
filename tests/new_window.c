#include <stdlib.h>
#include <mlx.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define MLX_ERROR 1

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if (mlx == NULL) //new
		return (MLX_ERROR);
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (mlx_win == NULL) //new
	{
		free(mlx_win);
		return (MLX_ERROR);
	}
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win); //new
	mlx_destroy_display(mlx); //new
	free(mlx); //new
}