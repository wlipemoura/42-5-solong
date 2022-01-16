/* largura e altura da janela (mapa)
largura e altura da imagem 
mlx_xpm_file__to_image
mlx_put_image_to_window */

//Verify the flag '-fPIE' necessary to make libft works with get_next_line and file_to_array functions
//gcc -g map_validator.c map_verifier.c -L./42-1-libft/ -lft

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libraries/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/keysym.h>//it has the keyboard key codes

#define COLLECTIBLE 'C'
#define EXIT 'E'
#define WALL '1'
#define START 'P'
#define PATH '0'
#define TRUE 1 //?
#define FALSE 0 //?
#define MLX_ERROR 0

#define INVALID_MAP "Error\nPlease, input a valid map.\n"
#define MAP_PATH "./assets/maps/subject_bigger.ber"
#define WINDOW_TITLE "so_long"

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
	void	*ptr_mlx;
	void	*ptr_win;
	int		end_game;
}	t_run_prog;


int	player_pos(t_map *map);
int ft_matrix_element_swap (char **matrix, int a_row, int a_column,
							int b_row, int b_column);
int	move(t_map *map, int keysym, t_run_prog *run);
char	**map_validator(char *map_dir, t_map *map);
int ft_2d_array_print(char **matrix, t_map map);
int	open_window(t_run_prog *run, t_map *map);

#endif