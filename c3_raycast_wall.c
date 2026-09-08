/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_raycast_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:56:41 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/19 17:46:33 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_texture(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.raydir_x > 0)
			return (game->map.ea_texture.add[game->wall.tex_y
					* TEX_WIDTH + (TEX_WIDTH - 1 - game->wall.tex_x)]);
		else
			return (game->map.we_texture.add[game->wall.tex_y
					* TEX_WIDTH + (TEX_WIDTH - 1 - game->wall.tex_x)]);
	}
	else
	{
		if (game->ray.raydir_y < 0)
			return (game->map.so_texture.add[game->wall.tex_y
					* TEX_WIDTH + (TEX_WIDTH - 1 - game->wall.tex_x)]);
		else
			return (game->map.no_texture.add[game->wall.tex_y
					* TEX_WIDTH + (TEX_WIDTH - 1 - game->wall.tex_x)]);
	}
}

void	draw_wall_texture(t_game *game, int start, int end, int x)
{
	int	color;
	int	y;

	y = -1;
	if (x < 0 || x >= WIDTH)
		return ;
	while (++y < HEIGHT)
	{
		if (y >= start && y <= end)
		{
			game->wall.tex_y = (int)((((double)y - game->wall.wall_start)
						/ game->wall.wall_height) * (double)TEX_HEIGHT);
			if (game->wall.tex_y >= TEX_HEIGHT)
				game->wall.tex_y = TEX_HEIGHT - 1;
			color = set_texture(game);
		}
		else
		{
			if (y < (HEIGHT / 2))
				color = game->map.sky_hex;
			else
				color = game->map.floor_hex;
		}
		game->mlx.image.add[(y * WIDTH) + x] = color;
	}
}

double	calc_wall_xy(t_game *game, double rdir_x, double rdir_y, double w_dist)
{
	if (game->ray.side == 0)
	{
		w_dist = (game->ray.sidedist_x - game->ray.deltadist_x);
		game->wall.wall_x = (game->player.pos.y + w_dist * rdir_y);
	}
	else
	{
		w_dist = (game->ray.sidedist_y - game->ray.deltadist_y);
		game->wall.wall_x = (game->player.pos.x + w_dist * rdir_x);
	}
	game->wall.wall_x -= floor(game->wall.wall_x);
	game->wall.tex_x = (int)(game->wall.wall_x * (double)TEX_WIDTH);
	if ((rdir_x > 0 && game->ray.side == 0)
		|| (rdir_y < 0 && game->ray.side != 0))
		game->wall.tex_x = TEX_WIDTH - game->wall.tex_x - 1;
	return (w_dist);
}

void	calc_wall(t_game *game, int i, double raydir_x, double raydir_y)
{
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;

	wall_dist = 0.0;
	wall_dist = calc_wall_xy(game, raydir_x, raydir_y, wall_dist);
	line_height = (int)(HEIGHT / wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	game->wall.wall_start = draw_start;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	game->wall.wall_end = draw_end;
	game->wall.wall_height = game->wall.wall_end - game->wall.wall_start;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	draw_wall_texture(game, draw_start, draw_end, i);
}
