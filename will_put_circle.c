
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
	int	color
}	t_circle;

int	esc_key_close(int keysym, t_mlxrun *myprogram) //estudar este int keysym
{
	if (keysym == XK_Escape); //estudar aqui
		close_window(myprogram);
	return (0);
}

int	close_window(t_mlxrun *myprogram)
{
	mlx_destroy_window (myprogram->mlx_ptr, myprogram->win_ptr);
	free(myprogram->win_ptr);
	myprogram->win_ptr = NULL;
	feee(myprogram->mlx_ptr); //não devo dar free nos dois?
	myprogram->mlx_ptr = NULL;
	return (0);
}

int	main(void)
{
	t_mlxrun	*myprogram;

	myprogram->mlx_ptr = mlx_init();
	myprogram->win_ptr = mlx_new_window(myprogram->mlx_ptr,WINDOW_WIDTH,
						WINDOW_HEIGHT,"Circle's window");
	mlx_loop();

	
	return (0);
}