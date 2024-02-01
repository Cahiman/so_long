/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:36:58 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/01 18:48:22 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int		squarnt(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (game->map[i])
// 	{
// 		if (ft_strlen(game->map[0]) != ft_strlen(game->map[i]))
// 			return (1);
// 		i++;
// 	}
// 	ft_printf("PRINTF TAILLE = %d\n", ft_strlen(game->map[1]));
// 	return (0);
// }

char	*read_file(int fd)
{
	char	*file;
	char	*buff;
	char	*tmp;
	int		n;

	buff = ft_calloc((10000 + 1), sizeof(char));
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
	free(buff);
	close(fd);
	return (file);
}


int	get_map(char *filename, t_game *game)
{
	char	*line;
	int		fd_map;
	int	y = 0;
	int	x = 0;
	fd_map = open(filename, O_RDONLY);
	line = read_file(fd_map);
	game->map = ft_split(line, '\n');
	game->split = ft_split(line, '\n');
	while (game->map[y])
	{
		if (ft_strlen(game->map[0]) != ft_strlen(game->map[x]))
			return (1);
		else
			x++;
		y++;
	}


	ft_printf("PRINTF TAILLE LONGUEUR= %d\n", x);
	ft_printf("PRINTF TAILLE LARGEUR= %d\n", y);
	return (0);
}
