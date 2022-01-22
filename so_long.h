/* largura e altura da janela (mapa)
largura e altura da imagem 
mlx_xpm_file__to_image
mlx_put_image_to_window */

//Verify the flag '-fPIE' necessary to make libft works with get_next_line and file_to_array functions
//gcc -g map_validator.c map_verifier.c -L./42-1-libft/ -lft

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libraries/libft/libft.h"
# include <fcntl.h>//??
# include <stdio.h>//??
# include <mlx.h>//it has the mlx functions
# include <X11/keysym.h>//it has the keyboard key codes
# include <X11/X.h>//??

#define COLLECTIBLE 'C'
#define EXIT 'E'
#define WALL '1'
#define START 'P'
#define PATH '0'
#define TRUE 1 //?
#define FALSE 0 //?
#define MLX_ERROR 0

#define INVALID_MAP "Error\nPlease, input a valid map.\n"
#define MAP_PATH "./assets/maps/subject.ber"
#define WINDOW_TITLE "so_long"

#define IMAGE_PATH "/assets/images/Terriermon.xpm"

typedef struct s_sprite
{
	char	*path;
	void	*img;
	int		img_height;
	int		img_width;
}	t_sprite;

typedef struct s_plr_pos
{
	int	x;
	int	y;
}	t_plr_pos;

typedef struct s_map
{
	int			width;
	int			height;
	char		**matrix;
	int			n_clct;
	t_plr_pos	player;
}	t_map;

typedef struct s_run_prog
{
	void		*ptr_mlx;
	void		*ptr_win;
	int			end_game;
	t_map		map;
	t_sprite	sprite;
}	t_run_prog;


int	player_pos(t_map *map);
int	move(int keysym, t_run_prog *run);
char	**map_validator(char *map_dir, t_map *map);
int ft_2d_array_print(char **matrix, t_map map);
int	open_window(t_run_prog *run);
int	handle_keyrelease(int keysym, void *data);
int	walk_right(t_run_prog *run);
int	walk_left(t_run_prog *run);
int	walk_up(t_run_prog *run);
int	walk_down(t_run_prog *run);
int	exit_handler(t_run_prog *run, int x, int y);
int	wall_handler(char **matrix, int player_y, int player_x);
int	collectible_handler(t_run_prog *run, int y, int x);
int	image_workflow(t_run_prog *run);

#endif