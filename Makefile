NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
HEADER = ./

SRCS = ./srcs/exit.c ./srcs/flood_fill.c ./srcs/game.c ./srcs/input.c ./srcs/main.c ./srcs/map.c ./srcs/movement.c

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
	make -C libs/libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
