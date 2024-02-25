/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:57:22 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/25 19:26:49 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game)
{
	if (game->img_wall != NULL)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_player != NULL)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_floor != NULL)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_coin != NULL)
		mlx_destroy_image(game->mlx, game->img_coin);
	if (game->img_end != NULL)
		mlx_destroy_image(game->mlx, game->img_end);
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
