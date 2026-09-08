/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_mouse_camera_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:47:11 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/18 18:41:18 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_mouse_rotate_right(t_game *game, double rotate_x)
{
	double	dir_x;
	double	plane_x;

	dir_x = game->player.dir.x;
	game->player.dir.x = dir_x * cos(rotate_x)
		- game->player.dir.y * sin(rotate_x);
	game->player.dir.y = dir_x * sin(rotate_x)
		+ game->player.dir.y * cos(rotate_x);
	plane_x = game->player.plane_x;
	game->player.plane_x = plane_x
		* cos(rotate_x) - game->player.plane_y * sin(rotate_x);
	game->player.plane_y = plane_x
		* sin(rotate_x) + game->player.plane_y * cos(rotate_x);
	return (0);
}

void	ft_camera(t_game *game)
{
	static int		old_x;
	static int		old_y;
	int				x;
	int				y;

	if (game->ray.first_mouse_time == 0)
	{
		mlx_mouse_get_pos(game->mlx.win, &old_x, &old_y);
		game->ray.first_mouse_time = 1;
	}
	else
	{
		mlx_mouse_get_pos(game->mlx.win, &x, &y);
		if (abs(old_x - x) > 0.01 || abs(old_y - y) > 0.01)
			ft_mouse_rotate_right(game, (old_x - x) * MOUSE_ROTATE);
		mlx_mouse_move(game->mlx.win, old_x, old_y);
	}
}
