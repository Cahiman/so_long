/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:07:14 by baiannon          #+#    #+#             */
/*   Updated: 2024/02/18 15:13:04 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_input(int keycode, t_game *game, int *move)
{
	if (keycode == KEY_ESC)
		ft_exit(game);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player_down(game, move);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player_up(game, move);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player_left(game, move);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player_right(game, move);
}

// int		verify_extension(char **av)
// {
// 	int	i;

// 	i = 0;
// 	if (av[1])
// 		i = ft_strlen(av[1]) - 4;
	
// 	}
// }
