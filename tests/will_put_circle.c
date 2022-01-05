#include <mlx.h>//to access minilibx functions
#include <X11/keysym.h>
#include <stdlib.h> //free function

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
#define MLX_ERROR 1

typedef struct s_mlxrun
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlxrun;

typedef struct s_circle
{
	int	center_x;
	int	center_y;
	int	radius;
	int	color;
}	t_circle;

int	close_window(t_mlxrun *myprogram)
{
	mlx_destroy_window(myprogram->mlx_ptr, myprogram->win_ptr);
	mlx_destroy_display(myprogram->mlx_ptr); //Is destroy display necessary?
	free(myprogram->win_ptr);
	myprogram->win_ptr = NULL;
	free(myprogram->mlx_ptr); //não devo dar free nos dois?
	myprogram->mlx_ptr = NULL;
	return (0);
}

int	esc_key_close(int keysym, t_mlxrun *myprogram) //estudar este int keysym
{
	if (keysym == XK_Escape) //estudar aqui
		close_window(myprogram);
	printf("Keypress: %d\n", keysym); //keysym de novo
	return (0);
}

int	handle_keyrelease(int keysym, void *myprogram)
{
	printf("Keyrelease: %d\n", keysym); //keysym aparece de novo
	return (0);
}

int	handle_no_event(void *myprogram)
	return (0); //understand why this function needs to exist

/* int	render(t_circle circle, t_mlxrun *myprogram)
{

} shift + alt + a*/

int	main(void)
{
	t_mlxrun	*myprogram;

	myprogram->mlx_ptr = mlx_init();
	if (myprogram->mlx_ptr == NULL)
		return (MLX_ERROR);
	myprogram->win_ptr = mlx_new_window(myprogram->mlx_ptr,WINDOW_WIDTH,
						WINDOW_HEIGHT,"Circle's window");
	if (myprogram->win_ptr == NULL)
	{
		free(myprogram->win_ptr);
		return (MLX_ERROR);
	}
	mlx_loop_hook(myprogram.mlx_ptr, &handle_no_event, &myprogram);//I did not understand why I need this function besides mlx_loop below
	//mlx_key_hook(myprogram->win_ptr, &esc_key_close, &myprogram);//how esc_key_close function take its parameters from here?
	mlx_hook(myprogram->win_ptr, KeyPress, KeyPressMask, &esc_key_close, &myprogram);
	mlx_hook(myprogram->win_ptr, KeyRelease, KeyPressMask, &esc_key_close, &myprogram);
	
	mlx_loop(myprogram->mlx_ptr);

	return (0);
}