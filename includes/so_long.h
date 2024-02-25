/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:03:14 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/25 19:30:02 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
# include <stdbool.h>

# define YELLOW	"\e[1;93m"
# define RED		"\e[1;91m"
# define GREEN   "\e[1;92m"
# define RESET   "\e[0m"

typedef struct s_player {
	int	x;
	int	y;
	int	temp;
}	t_player;

typedef struct s_game {
	void		*mlx;
	void		*win;
	void		*img_wall;
	void		*img_player;
	void		*img_floor;
	void		*img_coin;
	void		*img_end;
	char		**split;
	char		**map;
	int			height;
	int			width;
	int			end_point;
	int			num_player;
	int			fd_map;
	int			collectible;
	t_player	player;
}		t_game;

enum e_keys {
	KEY_W = 119,
	KEY_S = 115,
	KEY_A = 97,
	KEY_D = 100,
	KEY_ESC = 65307,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363
};

void	get_map(char *filename, t_game *game);
void	last_map_verification(t_game *game);
void	ft_exit(t_game *game);
void	move_player_down(t_game *game, int *move);
void	move_player_up(t_game *game, int *move);
void	move_player_right(t_game *game, int *move);
void	move_player_left(t_game *game, int *move);
void	handle_input(int keycode, t_game *game, int *move);
void	flood_fill_verification(t_game *game, int x, int y);
bool	load_display_and_window(t_game *game);
bool	load_resources(t_game *game);
int		get_map_details(t_game *game);
int		check_utils(t_game *game);
int		validate_map(t_game *game);
int		is_well_closed(t_game *game);
int		extension_invalid(char *str);

#endif