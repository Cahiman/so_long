/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:25:02 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/23 16:45:32 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_verification(t_game *game, int x, int y)
{
	game->split[y][x] = 'G';
	if (game->split[y - 1][x] != '1' && game->split[y - 1][x] != 'G')
		flood_fill_verification(game, x, y - 1);
	if (game->split[y + 1][x] != '1' && game->split[y + 1][x] != 'G')
		flood_fill_verification(game, x, y + 1);
	if (game->split[y][x - 1] != '1' && game->split[y][x - 1] != 'G')
		flood_fill_verification(game, x - 1, y);
	if (game->split[y][x + 1] != '1' && game->split[y][x + 1] != 'G')
		flood_fill_verification(game, x + 1, y);
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
			{
				ft_printf(ANSI_COLOR_RED "ERROR ! Invalid map.\n" ANSI_COLOR_RESET);
				ft_exit(game);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	is_well_closed(t_game *game)
{
	int	i;

	i = 0;
	while(game->map[0][i])
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			return(ft_printf(ANSI_COLOR_RED "ERROR ! Invalid map.\n" ANSI_COLOR_RESET), 0);
		i++;
	}
	i = 0;
	while(game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return(ft_printf(ANSI_COLOR_RED "ERROR ! Invalid map.\n" ANSI_COLOR_RESET), 0);
		i++;
	}
	return(1);
}
