/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_map_is_closed_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:48:43 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/18 14:07:47 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_map_firstline_closed(t_map *map)
{
	int	x;

	x = 0;
	while (map->map[0][x])
	{
		if (map->map[0][x] == '0' || map->map[0][x] == 'N'
			|| map->map[0][x] == 'S' || map->map[0][x] == 'E'
			|| map->map[0][x] == 'W')
			return (2);
		x++;
	}
	return (0);
}

int	is_map_closed_conditions(t_game *game, int x, int y, int height)
{
	if (x == 0 || y == 0)
		return (is_map_firstline_closed(&game->map));
	if ((x == 0 || x == (int)ft_strlen(game->map.map[y]) - 1)
		&& (y == 0 || y == height)
		&& game->map.map[y][x] != '1')
		return (3);
	if (!game->map.map[y][x + 1] || game->map.map[y][x + 1] == ' ')
		return (4);
	if (!game->map.map[y][x - 1] || game->map.map[y][x - 1] == ' ')
		return (5);
	if (x >= (int)ft_strlen(game->map.map[y + 1]) - 1
		|| game->map.map[y + 1][x] == ' ')
		return (6);
	if (x >= (int)ft_strlen(game->map.map[y - 1]) - 1
		|| game->map.map[y - 1][x] == ' ')
		return (7);
	if (game->map.map[y + 1][x + 1] == ' ')
		return (8);
	if (game->map.map[y - 1][x + 1] == ' ')
		return (9);
	if (game->map.map[y + 1][x - 1] == ' ')
		return (10);
	if (game->map.map[y - 1][x - 1] == ' ')
		return (11);
	return (1);
}

int	is_map_with_pos(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'N' || game->map.map[y][x] == 'S'
		|| game->map.map[y][x] == 'E' || game->map.map[y][x] == 'W')
	{
		game->map.player_bool = 1;
		game->map.player_count += 1;
	}
	if (game->map.map[y][x] != ' ' && game->map.map[y][x] != '0'
		&& game->map.map[y][x] != '1' && game->map.map[y][x] != 'N'
		&& game->map.map[y][x] != 'S' && game->map.map[y][x] != 'E'
		&& game->map.map[y][x] != 'W')
		return (1);
	return (0);
}

int	is_map_closed(t_game *game, int height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map.map[y]))
		{
			if (is_map_with_pos(game, x, y))
				return (1);
			if (game->map.map[y][x] == '0' || game->map.map[y][x] == 'N'
				|| game->map.map[y][x] == 'S' || game->map.map[y][x] == 'W'
				|| game->map.map[y][x] == 'E')
			{
				if ((is_map_closed_conditions(game, x, y, height)) >= 2)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
