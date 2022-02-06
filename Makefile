NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -c

MLX_FLAGS = -L. -lXext -lX11

INC = ./includes/

MLX_PATH = ./libraries/mlx_linux

MLX = $(MLX_PATH)/libmlx.a

LIBFT_PATH = ./libraries/libft

LIBFT = $(LIBFT_PATH)/libft.a

OBJ_PATH = ./objects

SRC_PATH = ./sources

RM = rm -f

SRC = ft_matrix_creator.c \
	images.c \
	map_on_window.c \
	map_validator.c \
	movements.c \
	walk.c \
	ft_matrix_element_swap.c\
	so_long.c \
	ft_count_2chars.c \

OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)

VPATH = sources

$(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INC) -I $(MLX_PATH)

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(OBJ) $(MLX) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(MLX):
	make all -C $(MLX_PATH)

$(LIBFT):
	make all -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
