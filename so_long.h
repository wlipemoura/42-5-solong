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

#define COLLECTIBLE 'C'
#define EXIT 'E'
#define WALL '1'
#define START 'P'
#define PATH '0'
#define TRUE 1 //?
#define FALSE 0 //?

#define INVALID_MAP "Error\nPlease, input a valid map.\n"
#define MAP_FILE "./assets/maps/subject_bigger.ber"

typedef struct s_map
{
	int	width;
	int	height;
}	t_map;

typedef struct s_plr_pos
{
	int	x;
	int	y;
}	t_plr_pos;

#endif