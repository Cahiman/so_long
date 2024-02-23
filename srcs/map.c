/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:36:58 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/23 17:19:50 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(int fd)
{
	char	*file;
	char	*buff;
	char	*tmp;
	int		n;

	buff = ft_calloc((10000 + 1), sizeof(char));
	if (!buff)
		return (NULL);
	n = 1;
	file = NULL;
	if (!file)
		file = ft_strdup("");
	while (n)
	{
		n = read(fd, buff, 10000);
		if (n == -1)
			return (free(buff), free(file), NULL);
		buff[n] = '\0';
		tmp = file;
		file = ft_strjoin(file, buff);
		free(tmp);
	}
	if (!file[0])
		return (free(file), free(buff), NULL);
	return (free(buff), close(fd), file);
}

void	get_map(char *filename, t_game *game)
{
	char	*line;
	int		fd_map;

	if (extension_invalid(filename))
	{
		ft_printf(RED "ERROR ! Invalid map file.\n" RESET);
		exit(0);
	}
	fd_map = open(filename, O_RDONLY);
	if (fd_map == -1)
		ft_exit(game);
	line = read_file(fd_map);
	if (!line)
	{
		ft_printf(RED "ERROR ! Map file empty.\n" GREEN);
		ft_exit(game);
	}
	game->map = ft_split(line, '\n');
	game->split = ft_split(line, '\n');
	free(line);
}

int	get_map_details(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->numPlayer += 1;
				game->player = (t_player){.x = x, .y = y};
			}
			else if (game->map[y][x] == 'C')
				game->collectible++;
			else if (game->map[y][x] == 'E')
				game->endPoint += 1;
			if (ft_strlen(game->map[0]) != ft_strlen(game->map[y]))
				return (0);
			x++;
		}
		y++;
	}
	return (game->width = x, game->height = y, 1);
}

int	validate_map(t_game *game)
{
	if (!get_map_details(game))
		return (ft_printf(RED "ERROR ! The map isn't rectangular !\n" RESET), 0);
	if (is_well_closed(game) == 0)
		return (0);
	if (game->endPoint != 1 || game->numPlayer != 1 || game->collectible == 0)
		return (ft_printf(RED "ERROR ! Invalid map !\n" RESET), 0);
	flood_fill_verification(game, game->player.x, game->player.y);
	check_utils(game);
	return (1);
}
