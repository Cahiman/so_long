/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:37:42 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/01 15:12:10 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game)
{
	mlx_destroy_image(game->mlx, game->imgWall);
	mlx_destroy_image(game->mlx, game->imgPlayer);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->map);
	exit(0);
}

int	check_utils(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->split[y])
	{
		x = 0;
		while (game->split[y][x])
		{
			if (game->split[y][x] == 'C' || game->split[y][x] == 'E')
				ft_exit(game);
			x++;
		}
		y++;
	}
	return (0);
}

int	count_endpoint(t_game *game)
{
	int	x;
	int	y;

	game->endPoint = 0;
	game->numPlayer = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				game->endPoint += 1;
			x++;
		}
		y++;
	}
	if (game->endPoint != 1)
		ft_exit(game);
	return (0);
}

void	check_map(t_game *game, int x, int y)
{
	game->split[y][x] = 'G';
	if (game->split[y - 1][x] != '1' && game->split[y - 1][x] != 'G')
		check_map(game, x, y - 1);
	if (game->split[y + 1][x] != '1' && game->split[y + 1][x] != 'G')
		check_map(game, x, y + 1);
	if (game->split[y][x - 1] != '1' && game->split[y][x - 1] != 'G')
		check_map(game, x - 1, y);
	if (game->split[y][x + 1] != '1' && game->split[y][x + 1] != 'G')
		check_map(game, x + 1, y);
}

int	player_move(int keycode, t_game *game)
{
	int			old_x;
	int			old_y;
	static int	move = 0;

	old_x = game->player.x;
	old_y = game->player.y;
	count_endpoint(game);
	if (keycode == KEY_ESC)
		ft_exit(game);
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		if ((game->map[game->player.y + 1][game->player.x]) != '1')
		{
			game->player.y += 1;
			move++;
		}
	}
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		if (game->map[game->player.y - 1][game->player.x] != '1')
		{
			game->player.y -= 1;
			move++;
		}
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		if (game->map[game->player.y][game->player.x - 1] != '1')
		{
			game->player.x -= 1;
			move++;
		}
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		if (game->map[game->player.y][game->player.x + 1] != '1')
		{
			game->player.x += 1;
			move++;
		}
	}
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->collectible--;
	}
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collectible == 0)
	{
		ft_printf(ANSI_COLOR_GREEN "YOU WON !\n" ANSI_COLOR_RESET);
		ft_exit(game);
	}
	if (game->map[old_y][old_x] != 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->imgFloor, old_x
			* 64, old_y * 64);
	if (game->map[game->player.y][game->player.x] != 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->imgPlayer,
			game->player.x * 64, game->player.y * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->imgEnd,
			game->player.x * 64, game->player.y * 64);
	ft_printf("NOMBRE MOUVEMENT : %d\n", move);
	return (0);
}

int	render(t_game *game)
{
	int	y;
	int	x;

	game->numPlayer = 0;
	game->collectible = 0;
	if (game->win)
	{
		y = 0;
		while (game->map[y])
		{
			x = 0;
			while (game->map[y][x])
			{
				if (game->map[y][x] == '1')
					mlx_put_image_to_window(game->mlx, game->win, game->imgWall,
						x * 64, y * 64);
				else if (game->map[y][x] == 'P')
				{
					game->numPlayer += 1;
					game->player.x = x;
					game->player.y = y;
					mlx_put_image_to_window(game->mlx, game->win,
						game->imgPlayer, x * 64, y * 64);
					check_map(game, x, y);
					check_utils(game);
				}
				else if (game->map[y][x] == '0')
					mlx_put_image_to_window(game->mlx, game->win,
						game->imgFloor, x * 64, y * 64);
				else if (game->map[y][x] == 'C')
				{
					mlx_put_image_to_window(game->mlx, game->win, game->imgCoin,
						x * 64, y * 64);
					game->collectible++;
				}
				else if (game->map[y][x] == 'E')
					mlx_put_image_to_window(game->mlx, game->win, game->imgEnd,
						x * 64, y * 64);
				x++;
			}
			y++;
		}
	}
	if (game->numPlayer != 1)
	{
		ft_printf("Erreur ! Nombre de joueur incorrecte !");
		ft_exit(game);
	}
	if (game->collectible <= 0)
	{
		ft_printf("Erreur ! Aucun collectible sur la map !");
		ft_exit(game);
	}
	return (0);
}

int	main(void)
{
	t_game	game;
	int		count;
	int		n;

	count = 0;
	n = 64;
	get_map("./maps/maptest.ber", &game);
	game.player.x = 0;
	game.player.y = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1920, 1080, "so_long");
	game.imgWall = mlx_xpm_file_to_image(game.mlx, "./assets/wall.xpm", &n, &n);
	game.imgPlayer = mlx_xpm_file_to_image(game.mlx, "./assets/player.xpm", &n,
			&n);
	game.imgFloor = mlx_xpm_file_to_image(game.mlx, "./assets/floor.xpm", &n,
			&n);
	game.imgCoin = mlx_xpm_file_to_image(game.mlx, "./assets/coin.xpm", &n, &n);
	game.imgEnd = mlx_xpm_file_to_image(game.mlx, "./assets/end.xpm", &n, &n);
	render(&game);
	mlx_key_hook(game.win, player_move, &game);
	mlx_hook(game.win, 33, 131072, (void *)ft_exit, &game);
	mlx_loop(game.mlx);
}
