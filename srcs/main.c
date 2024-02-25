/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:37:42 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/25 19:14:30 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_img(t_game *game, void *img, int x, int y)
{
	x *= 64;
	y *= 64;
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

int	player_move(int keycode, t_game *game)
{
	int			old_x;
	int			old_y;
	static int	move = 0;

	old_x = game->player.x;
	old_y = game->player.y;
	handle_input(keycode, game, &move);
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->collectible--;
	}
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collectible == 0)
	{
		ft_printf(GREEN "CONGRATULATIONS ! YOU WON !\n" RESET);
		ft_exit(game);
	}
	if (game->map[old_y][old_x] != 'E')
		render_img(game, game->imgFloor, old_x, old_y);
	if (game->map[game->player.y][game->player.x] != 'E')
		render_img(game, game->imgPlayer, game->player.x, game->player.y);
	else
		render_img(game, game->imgEnd, game->player.x, game->player.y);
	return (0);
}

void	render_tile_get_player_pos_and_collectibles(t_game *game, int x, int y)
{
	if (game->map[y][x] != '1' && (game->map[y][x] != 'P')
		&& (game->map[y][x] != 'C') && (game->map[y][x] != 'E')
		&& (game->map[y][x] != '0'))
		ft_exit(game);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgWall, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgPlayer, x * 64, y * 64);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgFloor, x * 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgCoin, x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgEnd, x * 64, y * 64);
}

int	render(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_tile_get_player_pos_and_collectibles(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		count;
	int		n;

	count = 0;
	n = 64;
	if (ac != 2)
		return (ft_printf(RED "ERROR ! Incorrect number of args.\n" RESET), 0);
	ft_bzero(&game, sizeof(game));
	get_map(av[1], &game);
	last_map_verification(&game);
	render(&game);
	mlx_key_hook(game.win, player_move, &game);
	mlx_hook(game.win, 33, 131072, (void *)ft_exit, &game);
	mlx_loop(game.mlx);
}
