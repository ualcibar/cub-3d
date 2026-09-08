/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_other_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:24:36 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/11 17:34:40 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb_to_hex(int *RGB)
{
	return (0 << 24 | RGB[0] << 16 | RGB[1] << 8 | RGB[2]);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	map_line_checker(char *line, char *char_tosearch)
{
	int		line_len;
	char	*line_tosearch;

	line_len = ft_strlen(line);
	line_tosearch = ft_strnstr(line, char_tosearch, line_len);
	if (line_tosearch != NULL)
		return (1);
	else
		return (0);
}

int	ft_fread(char *file, char *ext)
{
	int		file_len;
	char	*ext_check;

	file_len = ft_strlen(file);
	ext_check = ft_strchr(file, '.');
	if (!ext_check || ft_strncmp(ext_check, ext, 4) != 0
		|| ext_check - file != file_len - 4)
	{
		printf("Error\n");
		printf("The file extension or type, is invalid.\n");
		return (1);
	}
	return (0);
}

void	ft_map_printer(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.map_height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map.map[i]))
		{
			printf("%c", game->map.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
