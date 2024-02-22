/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:25:02 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/22 21:18:34 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_verification(char **split, int x, int y)
{
	split[y][x] = 'G';
	if (split[y - 1][x] != '1' && split[y - 1][x] != 'G')
		flood_fill_verification(split, x, y - 1);
	if (split[y + 1][x] != '1' && split[y + 1][x] != 'G')
		flood_fill_verification(split, x, y + 1);
	if (split[y][x - 1] != '1' && split[y][x - 1] != 'G')
		flood_fill_verification(split, x - 1, y);
	if (split[y][x + 1] != '1' && split[y][x + 1] != 'G')
		flood_fill_verification(split, x + 1, y);
}

int	is_well_closed(t_game *game)
{
	int	i;

	i = 0;
	while(game->map[0][i])
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			return(ft_printf("Erreur ! Map invalide !\n"), 0);
		i++;
	}
	i = 0;
	while(game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return(ft_printf("Erreur ! Map invalide !\n"), 0);
		i++;
	}
	return(1);
}
