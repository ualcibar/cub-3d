/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:04:04 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/18 14:11:36 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_is_everything_assigned(t_game *game)
{
	if (map_texture_is_not_assigned(game)
		|| map_colors_are_not_assigned(game))
	{
		printf("Error\n");
		printf("A texture or color is missing\n");
		exit (1);
	}
}

int	ft_fileopener(char **argv)
{
	int	fd;
	int	i;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	if (fd < 0)
	{
		printf("Error\n");
		printf("The map could not be readed\n");
		exit (1);
	}
	return (fd);
}

int	ft_map_config_check(t_game *game, char *line, uint8_t flag)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		if (map_line_checker(line, game->map.config[i]))
		{
			if (flag & (1 << i))
				map_error_returner(&game->map, 4);
			flag |= (1 << i);
			if (i > 3)
				map_color_saver(game, line, i);
			map_texture_saver(game, line, i);
			break ;
		}
		i++;
	}
	return (flag);
}

void	ft_mapchecker(t_game *game, int fd)
{
	char		*line;
	uint8_t		flag;
	uint8_t		action;

	line = get_next_line(fd);
	flag = 0;
	action = 0;
	while (line != NULL)
	{
		if (flag != ALLSET)
		{
			flag = ft_map_config_check(game, line, flag);
			free (line);
		}
		else if (flag == ALLSET && line[0] != '\n')
			action = 1;
		else if (flag == ALLSET && line[0] == '\n')
			free (line);
		ft_mapchecker_action(game, line, action);
		line = get_next_line(fd);
	}
	free (line);
}

void	ft_readmap(t_game *game, char **argv)
{
	int		fd;

	init_map_first_values_steps(game);
	fd = ft_fileopener(argv);
	ft_mapchecker(game, fd);
	ft_is_everything_assigned(game);
	ft_map_malloc_saver(&game->map);
	close(fd);
	ft_map_printer(game);
	if (is_map_closed(game, game->map.map_height))
		map_error_returner(&game->map, 2);
	if (game->map.player_bool == 0 || game->map.player_count > 1)
		map_error_returner(&game->map, 5);
}
