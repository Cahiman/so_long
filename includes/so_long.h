#ifndef so_long
# define so_long

# include <X11/Xlib.h>
# include <X11/keysym.h>
# include "ft_printf.h"
# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_player {
	int x;
	int y;
	int	temp;
} 	t_player;

typedef struct	s_game {
	//static int		move;
	int		collectible;
	void	*mlx;
	void	*win;
	void	*imgWall;
	void	*imgPlayer;
	void	*imgFloor;
	void	*imgCoin;
	void	*imgEnd;
	char	**map;
	t_player player;
	
}		t_game;

enum keys {
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_S = 115,
	KEY_A = 97,
	KEY_D = 100,
	KEY_RIGHT = 65363,
	KEY_LEFT = 65361,
	KEY_UP = 65362,
	KEY_DOWN = 65364
};

void	get_map(char *filename, t_game *game);


#endif