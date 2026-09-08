/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:13:49 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/18 16:31:23 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_hit(t_game *game, int x, double raydir_x, double raydir_y)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game->ray.sidedist_x < game->ray.sidedist_y)
		{
			game->ray.sidedist_x += game->ray.deltadist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedist_y += game->ray.deltadist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map.map[(int)floor(game->ray.map_y)]
			[(int)floor(game->ray.map_x)] == '1')
		{
			hit = 1;
			calc_wall(game, x, raydir_x, raydir_y);
		}
	}	
}

void	set_step(t_game *game, double raydir_x, double raydir_y)
{
	if (raydir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.sidedist_x = (game->player.pos.x
				- game->ray.map_x) * game->ray.deltadist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.sidedist_x = (game->ray.map_x + 1.0
				- game->player.pos.x) * game->ray.deltadist_x;
	}
	if (raydir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.sidedist_y = (game->player.pos.y
				- game->ray.map_y) * game->ray.deltadist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.sidedist_y = (game->ray.map_y + 1.0
				- game->player.pos.y) * game->ray.deltadist_y;
	}	
}

void	ft_send_ray_steptwo(t_game *game)
{
	if (game->ray.raydir_x == 0)
		game->ray.deltadist_x = exp(30);
	else
		game->ray.deltadist_x = fabs(1.0 / game->ray.raydir_x);
	if (game->ray.raydir_y == 0)
		game->ray.deltadist_y = exp(30);
	else
		game->ray.deltadist_y = fabs(1.0 / game->ray.raydir_y);
}

void	ft_send_ray(t_game *game)
{
	int		i;
	double	camera_x;

	i = 0;
	while (i <= WIDTH)
	{
		camera_x = 2 * i / (double)WIDTH - 1;
		game->ray.raydir_x = (game->player.dir.x
				+ game->player.plane_x * camera_x);
		game->ray.raydir_y = (game->player.dir.y
				+ game->player.plane_y * camera_x);
		game->ray.map_y = (int)game->player.pos.y;
		game->ray.map_x = (int)game->player.pos.x;
		ft_send_ray_steptwo(game);
		set_step(game, game->ray.raydir_x, game->ray.raydir_y);
		check_hit(game, i, game->ray.raydir_x, game->ray.raydir_y);
		i++;
	}
	mlx_put_image_to_window(game->mlx.mlx,
		game->mlx.win, game->mlx.image.img, 0, 0);
}
