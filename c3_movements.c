/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:35:11 by ullorent          #+#    #+#             */
/*   Updated: 2023/04/19 17:35:31 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_move_up(t_game *game)
{
	if (game->map.map[(int)(game->player.pos.y - game->player.dir.y * MOVE)]
		[(int)game->player.pos.x] == '0')
	{
		game->player.pos.y = game->player.pos.y - game->player.dir.y * MOVE;
		mlx_clear_window(game->mlx.mlx, game->mlx.win);
		ft_send_ray(game);
	}
	if (game->map.map[(int)(game->player.pos.y)]
		[(int)(game->player.pos.x - game->player.dir.x * MOVE)] == '0')
	{
		game->player.pos.x = game->player.pos.x - game->player.dir.x * MOVE;
		mlx_clear_window(game->mlx.mlx, game->mlx.win);
		ft_send_ray(game);
	}
	return (0);
}

int	ft_move_down(t_game *game)
{
	if (game->map.map[(int)(game->player.pos.y
			+ game->player.dir.y * (double)MOVE)]
		[(int)game->player.pos.x] == '0')
	{
		game->player.pos.y = game->player.pos.y
			+ game->player.dir.y * (double)MOVE;
		mlx_clear_window(game->mlx.mlx, game->mlx.win);
		ft_send_ray(game);
	}
	if (game->map.map[(int)(game->player.pos.y)]
		[(int)(game->player.pos.x + game->player.dir.x * MOVE)] == '0')
	{
		game->player.pos.x = game->player.pos.x + game->player.dir.x * MOVE;
		mlx_clear_window(game->mlx.mlx, game->mlx.win);
		ft_send_ray(game);
	}
	return (0);
}

int	ft_move_right(t_game *game)
{
	double	dir_y;
	double	dir_x;

	dir_y = game->player.dir.x * sin(1.555) - game->player.dir.y * cos(1.555);
	if (game->map.map[(int)(game->player.pos.y - (dir_y) * MOVE)]
		[(int)game->player.pos.x] == '0')
	{
		game->player.pos.y = game->player.pos.y - (dir_y) * MOVE;
		mlx_clear_window(game->mlx.mlx, game->mlx.win);
		ft_send_ray(game);
	}
	dir_x = game->player.dir.x * cos(1.555) - game->player.dir.y * sin(1.555);
	if (game->map.map[(int)(game->player.pos.y)]
		[(int)(game->player.pos.x - (dir_x) * MOVE)] == '0')
	{
		game->player.pos.x = game->player.pos.x - (dir_x) * MOVE;
		mlx_clear_window(game->mlx.mlx, game->mlx.win);
		ft_send_ray(game);
	}
	return (0);
}

int	ft_move_left(t_game *game)
{
	double	dir_y;
	double	dir_x;

	dir_y = game->player.dir.x * sin(-1.555) - game->player.dir.y * cos(-1.555);
	if (game->map.map[(int)(game->player.pos.y - (dir_y) * MOVE)]
		[(int)game->player.pos.x] == '0')
	{
		game->player.pos.y = game->player.pos.y - (dir_y) * MOVE;
		mlx_clear_window(game->mlx.mlx, game->mlx.win);
		ft_send_ray(game);
	}
	dir_x = game->player.dir.x * cos(-1.555) - game->player.dir.y * sin(-1.555);
	if (game->map.map[(int)(game->player.pos.y)]
		[(int)(game->player.pos.x - (dir_x) * MOVE)] == '0')
	{
		game->player.pos.x = game->player.pos.x - (dir_x) * MOVE;
		mlx_clear_window(game->mlx.mlx, game->mlx.win);
		ft_send_ray(game);
	}
	return (0);
}
