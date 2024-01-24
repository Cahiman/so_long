/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:37:42 by baiannon          #+#    #+#             */
/*   Updated: 2024/01/24 19:21:43 by baiannon         ###   ########.fr       */
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

    ft_printf("Program quit successfully !");
    exit(0);
	
}

// int	collectible(t_game *game)
// {
// 	int	i;
// 	int	count;
	
// 	i = 0;
// 	count = 0;
// 	while (game->map[i])
// 	{
// 		if(game->map[i] == 'C')
// 			count++;
// 		i++;
// 	}
// 	ft_printf("COLLECTIBLE : %d", count);
// 	return(0);
// }

int	player_move(int	keycode, t_game *game)
{
	int old_x = game->player.x;
    int old_y = game->player.y;
	static int move = 0;
	if (keycode == KEY_ESC)
		ft_exit(game);
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		if ((game->map[game->player.y + 1][game->player.x]) != '1')
			{game->player.y += 1;
			move++;}
	}
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		if (game->map[game->player.y - 1][game->player.x] != '1')
			{game->player.y -= 1;
			move++;}
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		if (game->map[game->player.y][game->player.x - 1] != '1')
			{game->player.x -= 1;
			move++;}
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		if (game->map[game->player.y][game->player.x + 1] != '1')
			{game->player.x += 1;
			move++;}
	}
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->collectible--;
	}

	if (game->map[game->player.y][game->player.x] == 'E' && game->collectible == 0)
		ft_exit(game);
		
	if (game->map[old_y][old_x] != 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->imgFloor, old_x * 64, old_y * 64);
			
	if (game->map[game->player.y][game->player.x] != 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->imgPlayer, game->player.x * 64, game->player.y * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->imgCoin, game->player.x * 64, game->player.y * 64);

	//ft_printf("NOMBRE COLLECTIBLE : %d", game->collectible);
	ft_printf("NOMBRE MOUVEMENT : %d\n", move);
	return (0);
}
int	render(t_game *game) 
{
	int	y;
	int	x;

	game->collectible = 0;
	if (game->win)
	{
		y = 0;
		while(game->map[y])
		{
			x = 0;
			while (game->map[y][x])
			{
				if (game->map[y][x] == '1')
					mlx_put_image_to_window(game->mlx, game->win, game->imgWall, x * 64, y * 64);
				else if (game->map[y][x] == 'P')
				{
					game->player.x = x;
					game->player.y = y;
					mlx_put_image_to_window(game->mlx, game->win, game->imgPlayer, x * 64, y * 64);
				}
				else if (game->map[y][x] == '0')
				 	mlx_put_image_to_window(game->mlx, game->win, game->imgFloor, x * 64, y * 64);	
				else if (game->map[y][x] == 'C')
				{
					mlx_put_image_to_window(game->mlx, game->win, game->imgCoin, x * 64, y * 64);
					game->collectible++;
				}
				else if (game->map[y][x] == 'E')
					mlx_put_image_to_window(game->mlx, game->win, game->imgEnd, x * 64, y * 64);
				x++;
			}
			y++;
		}
	}
	ft_printf("NOMBRE COLLECTIBLE : %d", game->collectible);
	return (0);
}

int	main(void)
{
		
	t_game game;
	int count;
	int n;
	
	count = 0;
	n = 64;
	get_map("./maps/maptest.ber", &game);
	game.player.x = 0;
	game.player.y = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1920, 1080, "so_long");
	game.imgWall = mlx_xpm_file_to_image(game.mlx, "./assets/wall.xpm", &n, &n);
	game.imgPlayer = mlx_xpm_file_to_image(game.mlx, "./assets/player.xpm", &n, &n);
	game.imgFloor = mlx_xpm_file_to_image(game.mlx, "./assets/floor.xpm", &n, &n);
	game.imgCoin = mlx_xpm_file_to_image(game.mlx, "./assets/coin.xpm", &n, &n);
	game.imgEnd = mlx_xpm_file_to_image(game.mlx, "./assets/end.xpm", &n, &n);
	//mlx_put_image_to_window(game.mlx, game.win, game.imgWall, 0, 0);
	// mlx_loop_hook(game.mlx, &render, &game);
	render(&game);
	mlx_key_hook(game.win, player_move, &game);
	mlx_hook(game.win, 33, 131072, (void *)ft_exit, &game);
	mlx_loop(game.mlx);
	}