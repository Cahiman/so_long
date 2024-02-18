/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:25:02 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/17 22:27:02 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TODO: fix flood fill for when player is in the corner, 
// and return value if map is valid
void	is_map_correctly_bounded(t_game *game, int x, int y)
{
	game->split[y][x] = 'G';
	if (game->split[y - 1][x] != '1' && game->split[y - 1][x] != 'G')
		is_map_correctly_bounded(game, x, y - 1);
	if (game->split[y + 1][x] != '1' && game->split[y + 1][x] != 'G')
		is_map_correctly_bounded(game, x, y + 1);
	if (game->split[y][x - 1] != '1' && game->split[y][x - 1] != 'G')
		is_map_correctly_bounded(game, x - 1, y);
	if (game->split[y][x + 1] != '1' && game->split[y][x + 1] != 'G')
		is_map_correctly_bounded(game, x + 1, y);
}
