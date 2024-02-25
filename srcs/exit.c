/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:57:22 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/25 19:00:07 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game)
{
	if (game->imgWall != NULL)
		mlx_destroy_image(game->mlx, game->imgWall);
	if (game->imgPlayer != NULL)
		mlx_destroy_image(game->mlx, game->imgPlayer);
	if (game->imgFloor != NULL)
		mlx_destroy_image(game->mlx, game->imgFloor);
	if (game->imgCoin != NULL)
		mlx_destroy_image(game->mlx, game->imgCoin);
	if (game->imgEnd != NULL)
		mlx_destroy_image(game->mlx, game->imgEnd);
	if (game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx != NULL)
		mlx_destroy_display(game->mlx);
	if (game->fd_map)
		close(game->fd_map);
	free(game->mlx);
	ft_free(game->split);
	ft_free(game->map);
	exit(0);
}

void	last_map_verification(t_game *game)
{
	if (validate_map(game) == 0)
	{
		ft_free(game->map);
		ft_free(game->split);
		exit(0);
	}
	if (load_display_and_window(game) == 0)
	{
		ft_free(game->map);
		ft_free(game->split);
		exit(0);
	}
	if (load_resources(game) == 0)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		ft_free(game->map);
		ft_free(game->split);
		exit(0);
	}
}
