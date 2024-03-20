NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = ./

SRCS = 	ft_hexa.c \
		ft_printf_utils.c \
		ft_printf.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $^ -o $@

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re