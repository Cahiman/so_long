/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:36:58 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/28 18:42:27 by baiannon         ###   ########.fr       */
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
	if (!file || !file[0])
		return (free(file), free(buff), NULL);
	return (free(buff), close(fd), file);
}

int	get_map(char *filename, t_game *game)
{
	char	*line;

	if (extension_invalid(filename))
		return (ft_printf(RED "ERROR ! Add a map file : .ber !\n" RESET),
			ft_exit(game), 0);
	game->fd_map = open(filename, O_RDONLY);
	if (game->fd_map == -1)
		return (ft_printf(RED "ERROR ! Map does not exist !\n" RESET),
			ft_exit(game), 0);
	line = read_file(game->fd_map);
	if (!line)
		return (ft_printf(RED "ERROR ! Map file empty.\n" RESET),
			ft_exit(game), 0);
	if (ft_strnstr(line, "\n\n", ft_strlen(line)) != NULL)
		return (ft_printf(RED "ERROR ! Map file contains unexpected newline.\n"
				RESET), free(line), ft_exit(game), 0);
	game->map = ft_split(line, '\n');
	game->split = ft_split(line, '\n');
	if (!game->map || !game->split)
		return (free(line), ft_exit(game), 0);
	return (free(line), 0);
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
				game->num_player += 1;
				game->player = (t_player){.x = x, .y = y};
			}
			else if (game->map[y][x] == 'C')
				game->collectible++;
			else if (game->map[y][x] == 'E')
				game->end_point += 1;
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
	if (!get_map_infos(game))
		return (ft_printf(RED "ERROR ! Invalid map !\n" RESET), 0);
	if (!get_map_details(game))
		return (ft_printf(RED "ERROR ! The map isn't rectangular !\n" RESET), 0);
	if (is_well_closed(game) == 0)
		return (ft_printf(RED "ERROR ! Invalid map.\n" RESET), 0);
	if (game->end_point != 1 || game->num_player != 1 || game->collectible == 0)
		return (ft_printf(RED "ERROR ! Invalid map !\n" RESET), 0);
	if (game->height < 16 && game->width < 30)
		flood_fill_verification(game, game->player.x, game->player.y);
	else
		return (ft_printf(RED "ERROR ! Map too big.\n"RESET), 0);
	check_utils(game);
	return (1);
}

int	get_map_infos(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '1' && (game->map[y][x] != 'P')
				&& (game->map[y][x] != 'C') && (game->map[y][x] != 'E')
				&& (game->map[y][x] != '0'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
