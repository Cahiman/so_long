NAME = so_long

C_FILES = main.c exit.c flood_fill.c game.c input.c map.c movement.c
SRCS = $(addprefix srcs/,$(C_FILES))

CFLAGS = -Wall -Wextra -Werror

LIBS = printf/libftprintf.a libft/libft.a
DEPS = $(addprefix libs/,$(LIBS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Iincludes -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME): $(OBJS)
	make -C libs/mlx
	make -C libs/printf
	make -C libs/libft
	$(CC) $(OBJS) -Llibs/mlx -lmlx -Llibs/printf -lftprintf -Llibs/libft -lft -Iincludes  -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make -C libs/mlx clean
	make -C libs/printf clean
	make -C libs/libft clean

fclean: clean
	make -C libs/printf fclean
	make -C libs/libft fclean
	rm -f $(NAME)

re: fclean all