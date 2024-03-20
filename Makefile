NAME = so_long

C_FILES = main.c exit.c flood_fill.c game.c input.c map.c movement.c
SRCS = $(addprefix srcs/,$(C_FILES))

CFLAGS = -Wall -Wextra -Werror

LIBS = printf/libftprintf.a libft/libft.a
DEPS = $(addprefix libs/,$(LIBS))

all: $(NAME)

$(NAME):
	make -C libs/mlx
	make -C libs/printf
	make -C libs/libft
	cc $(SRCS) -g3 -I includes/ -L libs/mlx -l mlx -I mlx -lXext -lX11 -lm -lz -o $(NAME) $(DEPS)

clean:
	make -C libs/mlx clean
	make -C libs/printf clean
	make -C libs/libft clean

fclean: clean
	make -C libs/printf fclean
	make -C libs/libft fclean
	rm -f $(NAME)

re: fclean all