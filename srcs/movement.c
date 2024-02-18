/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:15:42 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/17 22:56:21 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_down(t_game *game, int *move)
{
	if ((game->map[game->player.y + 1][game->player.x]) != '1')
	{
		game->player.y += 1;
		(*move)++;
	}
}

void	move_player_up(t_game *game, int *move)
{
	if (game->map[game->player.y - 1][game->player.x] != '1')
	{
		game->player.y -= 1;
		(*move)++;
	}
}

void	move_player_right(t_game *game, int *move)
{
	if (game->map[game->player.y][game->player.x + 1] != '1')
	{
		game->player.x += 1;
		(*move)++;
	}
}

void	move_player_left(t_game *game, int *move)
{
	if (game->map[game->player.y][game->player.x - 1] != '1')
	{
		game->player.x -= 1;
		(*move)++;
	}
}
