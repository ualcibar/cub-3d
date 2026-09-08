/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:30:09 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/11 17:29:03 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_first_move(int keyhook, t_game *game)
{
	if (keyhook == 13)
		game->player.move_down = 1;
	else if (keyhook == 1)
		game->player.move_up = 1;
	else if (keyhook == 0)
		game->player.move_right = 1;
	else if (keyhook == 2)
		game->player.move_left = 1;
	else if (keyhook == 124)
		game->player.rotate_right = 1;
	else if (keyhook == 123)
		game->player.rotate_left = 1;
	else if (keyhook == 53)
		ft_close(game);
	return (0);
}

int	ft_second_move(int keyhook, t_game *game)
{
	if (keyhook == 13)
		game->player.move_down = 0;
	else if (keyhook == 1)
		game->player.move_up = 0;
	else if (keyhook == 0)
		game->player.move_right = 0;
	else if (keyhook == 2)
		game->player.move_left = 0;
	else if (keyhook == 124)
		game->player.rotate_right = 0;
	else if (keyhook == 123)
		game->player.rotate_left = 0;
	return (0);
}
