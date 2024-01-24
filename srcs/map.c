/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:36:58 by baiannon          #+#    #+#             */
/*   Updated: 2024/01/22 18:41:55 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(int fd)
{
	char 		*file;
	char		*buff;
	char		*tmp;
	int			n;

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

void	get_map(char *filename, t_game *game)
{
	char *line;
	int fd_map;
	int i;

	i = 0;
	fd_map = open(filename, O_RDONLY);
	line = read_file(fd_map);
	game->map = ft_split(line, '\n');
	// while (game->map[i])
	// {
	// 	//printf("%s", game->map[i]);
	// 	i++;
	// };
}