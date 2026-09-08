/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:36:46 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/18 19:11:17 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_main_frame(t_game *game)
{
	if (game->player.move_down)
		ft_move_down(game);
	if (game->player.move_up)
		ft_move_up(game);
	if (game->player.move_right)
		ft_move_right(game);
	if (game->player.move_left)
		ft_move_left(game);
	if (game->player.rotate_right)
		ft_rotate_right(game);
	if (game->player.rotate_left)
		ft_rotate_left(game);
	ft_camera(game);
	ft_send_ray(game);
	return (0);
}

int	ft_rotate_left(t_game *game)
{
	double	dir_x;
	double	plane_x;

	dir_x = game->player.dir.x;
	game->player.dir.x = dir_x * cos(-ROTATE)
		- game->player.dir.y * sin(-ROTATE);
	game->player.dir.y = dir_x * sin(-ROTATE)
		+ game->player.dir.y * cos(-ROTATE);
	plane_x = game->player.plane_x;
	game->player.plane_x = plane_x * cos(-ROTATE)
		- game->player.plane_y * sin(-ROTATE);
	game->player.plane_y = plane_x * sin(-ROTATE)
		+ game->player.plane_y * cos(-ROTATE);
	return (0);
}

int	ft_rotate_right(t_game *game)
{
	double	dir_x;
	double	plane_x;

	dir_x = game->player.dir.x;
	game->player.dir.x = dir_x * cos(ROTATE) - game->player.dir.y * sin(ROTATE);
	game->player.dir.y = dir_x * sin(ROTATE) + game->player.dir.y * cos(ROTATE);
	plane_x = game->player.plane_x;
	game->player.plane_x = plane_x
		* cos(ROTATE) - game->player.plane_y * sin(ROTATE);
	game->player.plane_y = plane_x
		* sin(ROTATE) + game->player.plane_y * cos(ROTATE);
	return (0);
}
