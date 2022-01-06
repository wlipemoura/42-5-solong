/* largura e altura da janela (mapa)
largura e altura da imagem 
mlx_xpm_file__to_image
mlx_put_image_to_window */
#ifndef SO_LONG_H
# define SO_LONG_H
# include "42-1-libft/libft.h"

#define COLLECTIBLE 'C'
#define EXIT 'E'
#define WALL '1'
#define START 'P'
#define PATH '0'
#define TRUE 1 //?
#define FALSE 0 //?
#define INVALID_MAP "Error\nPlease, input a valid map.\n"

typedef struct s_map
{
	int	width;
	int	height;
}	t_map;

#endif