NAME = so_long

#INC = libft.h

CC = clang

CFLAGS = -Wall -Wextra -Werror -c -g3
# compile with -g3 flag and run the follow to execute: valgrind ./a.out
MLX_FLAGS = -lmlx -lXext -lX11

SRC_PATH = ./sources

MLX_PATH = ./libraries/mlx_linux

LIBFT_PATH = ./libraries/libft

LIBFT_FLAGS = -L $(LIBFT_PATH) -lft

RM = rm -f

SRC = map_validator.c \
		so_long.c

OBJ = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make all -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)

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
