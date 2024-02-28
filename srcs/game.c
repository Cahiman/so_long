/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:15:52 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/28 17:20:29 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdbool.h>

bool	load_display_and_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (false);
	if (game->height > 16 || game->width > 30)
		return (ft_printf(RED "ERROR ! Map too big.\n"RESET), 0);
	game->win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "so_long");
	if (!game->win)
		return (false);
	return (true);
}

bool	load_resources(t_game *game)
{
	int		_ignored;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm",
			&_ignored, &_ignored);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./assets/player.xpm",
			&_ignored, &_ignored);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./assets/floor.xpm",
			&_ignored, &_ignored);
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "./assets/coin.xpm",
			&_ignored, &_ignored);
	game->img_end = mlx_xpm_file_to_image(game->mlx, "./assets/end.xpm",
			&_ignored, &_ignored);
	if (!game->img_end || !game->img_wall || !game->img_player
		|| !game->img_floor || !game->img_coin)
		return (false);
	return (true);
}
