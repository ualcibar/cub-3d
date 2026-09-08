/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_free_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:04:23 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/22 15:36:03 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_double_char_mem(char **str)
{
	char	**temp;

	temp = str;
	while (*temp)
		free(*temp++);
	free (str);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_height)
	{
		free(map->map[i]);
		i++;
	}
	free (map->map);
}

void	free_list(t_list *list)
{
	t_list	*current;
	t_list	*next;

	current = list;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	mlx_destroy_image(game->mlx.mlx, game->mlx.image.img);
	free_map(&game->map);
	free_list(game->map.head);
	exit (0);
	return (0);
}
