NAME = libftprintf.a

INC = ft_printf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror
#compile using:		 clang main.c -lX11 -lXext -lmlx

RM = rm -f

SRC = \
	ft_printf.c \
	ft_itoa_address.c \
	ft_putsomething.c

OBJ = $(SRC:.c=.o)

INCLUDE = libft

LIBRARIES = make -C libft

TESTER = ./tester

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
#.c.o:
#	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

#$(NAME): $(OBJ)
#	$(LIBRARIES)
#	cp $(INCLUDE)/libft.a ./$(NAME)
#	ar rcs $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) *.o
	$(LIBRARIES) clean

fclean:
	$(RM) *.o
	$(RM) $(NAME)
	$(LIBRARIES) fclean

re:	fclean all

.PHONY:	all clean fclean re

libftexec:
	$(LIBRARIES)

test: all
	$(TESTER)/tester m

main:
	$(CC) $(CFLAGS) ../apps/main.c $(NAME)