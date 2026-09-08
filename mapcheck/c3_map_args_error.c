/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_map_args_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:34:04 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/19 18:16:19 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_error_returner(t_map *map, int bool)
{
	printf("Error\n");
	if (bool == 0)
		printf("Malformed texture line\n");
	if (bool == 1)
		printf("Malformed/duplicated floor/ceiling colors line.\n");
	if (bool == 2)
	{
		printf("Readed map contains errors! Please, check your map.\n");
		free_map(map);
	}
	if (bool == 3)
		printf("Readed map does not contain any valid map values.\n");
	if (bool == 4)
		printf("Readed texture is corrupted or not valid.\n");
	if (bool == 5)
	{
		printf("There is not a player on the map or it is duplicated.\n");
		free_map(map);
	}
	if (bool == 6)
		printf("There is a next line in map or something similar to it.\n");
	exit (1);
}

int	map_texture_is_assigned(t_game *game, int bool)
{
	if (game->map.no_text_path && bool == 0)
		return (1);
	else if (game->map.so_text_path && bool == 1)
		return (1);
	else if (game->map.we_text_path && bool == 2)
		return (1);
	else if (game->map.ea_text_path && bool == 3)
		return (1);
	return (0);
}

int	map_texture_is_not_assigned(t_game *game)
{
	if (!game->map.no_text_path)
		return (1);
	else if (!game->map.so_text_path)
		return (1);
	else if (!game->map.we_text_path)
		return (1);
	else if (!game->map.ea_text_path)
		return (1);
	return (0);
}

int	map_colors_are_assigned(t_game *game, int bool)
{
	int	i;

	i = 0;
	while (i < 3 && bool == 0)
	{
		if (game->map.floor_color[i] != -1)
			return (1);
		i++;
	}
	while (i < 3 && bool == 1)
	{
		if (game->map.sky_color[i] != -1)
			return (1);
		i++;
	}
	return (0);
}

int	map_colors_are_not_assigned(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->map.floor_color[i] == -1)
			return (1);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (game->map.sky_color[i] == -1)
			return (1);
		i++;
	}
	return (0);
}
