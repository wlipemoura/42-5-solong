/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:46:07 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 07:34:21 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Verify the flag '-fPIE' necessary to make libft works 
//with get_next_line and file_to_array functions
//gcc -g map_validator.c map_verifier.c -L./42-1-libft/ -lft

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libraries/libft/libft.h"
# include <fcntl.h>//??
# include <stdio.h>//??
# include <mlx.h>//it has the mlx functions
# include <X11/keysym.h>//it has the keyboard key codes
# include <X11/X.h>//??

# define COLLECTIBLE 'C'
# define EXIT 'E'
# define WALL '1'
# define PLAYER 'P'
# define PATH '0'
# define TRUE 1 //?
# define FALSE 0 //?
# define MLX_ERROR 0
# define SIZE 64

# define INVALID_MAP "Error\nPlease, input a valid map.\n"
# define WINDOW_TITLE "so_long"

typedef struct s_sprite
{
	char	*up_path;
	void	*up_img;
	char	*down_path;
	void	*down_img;
	char	*left_path;
	void	*left_img;
	char	*right_path;
	void	*right_img;
	char	*floor_path;
	void	*floor_img;
	char	*colct_path;
	void	*colct_img;
	char	*wall_path;
	void	*wall_img;
	char	*exit_path;
	void	*exit_img;
	int		img_height;
	int		img_width;
}	t_sprite;

typedef struct s_plr_pos
{
	int	x;
	int	y;
	int	prev_x;
	int	prev_y;
}	t_plr_pos;

typedef struct s_map
{
	int			width;
	int			height;
	char		*map_path;
	char		**matrix;
	int			n_clct;
	int			n_steps;
	t_plr_pos	player;
}	t_map;

typedef struct s_run_prog
{
	void		*ptr_mlx;
	void		*ptr_win;
	int			end_game;
	t_map		map;
	t_sprite	sprt;
}	t_run_prog;

int		player_pos(t_map *map);
int		move(int keysym, t_run_prog *run);
char	**map_validator(t_run_prog *run);
int		open_window(t_run_prog *run);
int		handle_keyrelease(int keysym, void *data);
int		walk_right(t_run_prog *run);
int		walk_left(t_run_prog *run);
int		walk_up(t_run_prog *run);
int		walk_down(t_run_prog *run);
int		walk(int keysym, t_run_prog *run);
int		exit_handler(t_run_prog *run, int y_cur_pos, int x_cur_pos);
int		wall_handler(t_run_prog *run, int y_cur_pos, int x_cur_pos);
int		collectible_handler(t_map *map);
int		image_workflow(t_run_prog *run);
int		close_window(t_run_prog *run);
void	print_image(t_run_prog *run);
void	create_image(t_run_prog *run);
void	load_image(t_run_prog *run);
void	count_steps(int *n_steps);
void	free_matrix(t_run_prog *run);
int		ft_matrix_creator(t_map *map);

#endif