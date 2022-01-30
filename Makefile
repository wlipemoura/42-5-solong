NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -c
#clang -g ./sources/map_validator.c map_on_window.c ft_2d_array_print.c so_long.c movements.c -L./libraries/libft/ -lft -lmlx -lXext -lX11
#clang -g3 ./sources/*.c so_long.c -L./libraries/libft/ -lft -lmlx -lXext -lX11

MLX_FLAGS = -L. -lXext -lX11

INC = ./includes/

MLX_PATH = ./libraries/mlx_linux

MLX = $(MLX_PATH)/libmlx.a

LIBFT_PATH = ./libraries/libft

LIBFT = $(LIBFT_PATH)/libft.a

OBJ_PATH = ./objects

SRC_PATH = ./sources

#LIBFT_FLAGS = -L $(LIBFT_PATH) -lft

RM = rm -f

SRC = ft_matrix_creator.c \
	images.c \
	map_on_window.c \
	map_validator.c \
	movements.c \
	walk.c \
	ft_matrix_element_swap.c\
	so_long.c \

#OBJ = $(SRC:.c=.o)
OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)

VPATH = sources

#.c.o:
#	$(CC) $(CFLAGS) $< -o $(<:.c=.o)
$(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INC)

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT)

#	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)
	$(CC) $(OBJ) $(MLX) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(MLX):
	make all -C $(MLX_PATH)

$(LIBFT):
	make all -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJ_PATH)/$(OBJ)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

git:
	git status
	git add .
	git status
	git commit -m "segmentation fault solved"

push:
	git push

.PHONY: all clean fclean re
