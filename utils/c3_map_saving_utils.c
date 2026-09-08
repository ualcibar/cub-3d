/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_map_saving_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:52:13 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/19 18:04:22 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_map_list_saver(t_map *map, char *line)
{
	char	*temp;

	if (line != NULL)
	{
		temp = ft_strchr(line, '\n');
		if (temp != NULL)
			*temp = '\0';
		ft_lstadd_back(&map->head, ft_lstnew(line));
	}
}

void	ft_map_malloc_saver(t_map *map)
{
	int		i;
	t_list	*current;

	i = 0;
	map->map = malloc(sizeof(char *) * ft_lstsize(map->head) - 1);
	current = map->head->next;
	while (current != NULL)
	{
		map->map[i] = current->content;
		map->map_height++;
		current = current->next;
		i++;
	}
}

void	ft_mapchecker_action(t_game *game, char *line, int action)
{
	if (action == 1)
	{
		if (line[0] != '\n')
			ft_map_list_saver(&game->map, line);
		else
			map_error_returner(&game->map, 6);
	}
}
