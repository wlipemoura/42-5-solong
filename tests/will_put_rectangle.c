#include <stdlib.h> //free function
#include <mlx.h> //minilibx functions
#include <X11/keysym.h> //keyboard rules
#include <X11/X.h> //List of event names and available masks (mlx_hook function parameters)
//#include <stdio.h> //????
//#include <string.h> //????

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 750

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0x00FF00
#define BLUE_PIXEL 0x0000FF
#define WHITE_PIXEL 0xFFFFFF

#define MLX_ERROR 1

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int heigth;
	int	color;
}	t_rect;

int	handle_keypress(int keysym,t_data *data) //why these are the function's param?
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr); //study this
		data->win_ptr = NULL; //study this
	}
	return (0);
}

void	render_rect(t_data *data, t_rect rect)
{
	int i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.heigth)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, rect.color);
			j++;
		}
		i++;
	}
	return ;
}

int	render(t_data *data)
{
	render_rect(data, (t_rect){WINDOW_WIDTH / 3, WINDOW_HEIGHT / 3, 
	WINDOW_WIDTH / 3, WINDOW_HEIGHT / 3, GREEN_PIXEL});
	return(0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if(data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
	"My window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data.mlx_ptr, render, &data);
	//não entendi de onde vieram estes KeyPress e KeyPressMask
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}