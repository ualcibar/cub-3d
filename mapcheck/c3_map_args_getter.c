/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_map_args_getter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:36:51 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/17 17:13:46 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_texture_opener(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		if (ft_fread(path, ".xpm") == 0)
		{
			printf("Error\n");
			printf("An error ocurred reading a texture path.\n");
		}
		printf("Which is this bad path? %s\n", path);
		exit (1);
	}
	return (0);
}

int	map_color_args_checker(char **tokens)
{
	int	i;
	int	c;
	int	arg_len;
	int	num;

	i = -1;
	c = 0;
	arg_len = 0;
	num = 0;
	while (++i < 3)
	{
		c = -1;
		arg_len = ft_strlen(tokens[i]);
		while (++c < arg_len)
		{
			if ((!ft_isdigit(tokens[i][c]) || ft_isspace(tokens[i][c]))
				&& tokens[i][c] != '\n')
				return (1);
		}
		num = ft_atoi(tokens[i]);
		if (num > 255 || num < 0)
			return (1);
	}
	return (0);
}

void	map_color_saver(t_game *game, char *line, int bool)
{
	char	**tokens;
	int		i;

	i = 0;
	tokens = ft_split(line + 2, ',');
	if (!tokens[0] || !tokens[1] || !tokens[2]
		|| tokens[3] || map_colors_are_assigned(game, bool))
		map_error_returner(&game->map, 1);
	if (map_color_args_checker(tokens))
		map_error_returner(&game->map, 1);
	while (bool == 4 && i < 3)
	{
		game->map.floor_color[i] = ft_atoi(tokens[i]);
		i++;
	}
	while (bool == 5 && i < 3)
	{
		game->map.sky_color[i] = ft_atoi(tokens[i]);
		i++;
	}
	free_double_char_mem(tokens);
}

void	map_texture_saver_part2(t_game *game, char *path, int bool)
{
	if (bool == 0 && !map_texture_opener(path))
	{
		free(game->map.no_text_path);
		game->map.no_text_path = ft_strdup(path);
	}
	if (bool == 1 && !map_texture_opener(path))
	{
		free(game->map.so_text_path);
		game->map.so_text_path = ft_strdup(path);
	}
	if (bool == 2 && !map_texture_opener(path))
	{
		free(game->map.we_text_path);
		game->map.we_text_path = ft_strdup(path);
	}
	if (bool == 3 && !map_texture_opener(path))
	{
		free(game->map.ea_text_path);
		game->map.ea_text_path = ft_strdup(path);
	}
}

int	map_texture_saver(t_game *game, char *line, int bool)
{
	char	*trimed_line;
	char	*espacios;
	char	*path;

	if (map_texture_is_assigned(game, bool))
		return (1);
	trimed_line = ft_strtrim_modified(line + 2);
	espacios = trimed_line;
	if (!espacios)
		map_error_returner(&game->map, 0);
	path = ft_strtrim_modified(espacios);
	map_texture_saver_part2(game, path, bool);
	free(trimed_line);
	free(path);
	return (0);
}
