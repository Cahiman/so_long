NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
HEADER = ./

SRCS = ./srcs/main.c ./srcs/map.c ./srcs/exit.c ./srcs/game.c ./srcs/movement.c ./srcs/imput.c ./srcs/flood_fill.c

LIBFTDIR = libs/libft/

LIBFTNAME = libft.a

LIBFT = $(LIBFTDIR)$(LIBFTNAME)

DEPS = libs/printf/libftprintf.a


all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(NAME): $(SRCS)
	make -C libs/mlx
	make -C libs/printf
	cc $(CFLAGS) $(SRCS) -g3 -I includes/ -L libs/mlx -l mlx -I mlx -L $(LIBFTDIR) -lft -lXext -lX11 -lm -lz -o $(NAME) $(DEPS)

clean:
	make -C libs/mlx clean
	make -C libs/libft clean
	make -C libs/printf clean

fclean: clean
	make -C libs/libft fclean
	make -C libs/printf fclean
	rm -f $(NAME)

re: fclean all
	make -C libs/libft re
	make -C libs/printf re
	make -C libs/mlx re

.PHONY: all clean fclean re
