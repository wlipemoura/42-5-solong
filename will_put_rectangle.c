#include <stdlib.h> //free function
#include <mlx.h> //minilibx functions
#include <X11/keysym.h> //keyboard rules
#include <X11/X.h> //List of event names and available masks (mlx_hook function parameters)
//#include <stdio.h> //????
//#include <string.h> //????

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

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

void	handle_keypress(int keysym,t_data *data) //why these are the function's param?
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr); //study this
		data->win_ptr = NULL; //study this
	}
	return ;
}

int render_point()

void	main(void)
{

	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My window");
	mlx_key_hook(win_ptr, )

	mlx_loop(mlx_ptr);

}