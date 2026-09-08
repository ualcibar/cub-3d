/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_init_funs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:11:42 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/18 16:46:20 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_map_first_values_steps(t_game *game)
{
	game->map.no_text_path = NULL;
	game->map.so_text_path = NULL;
	game->map.we_text_path = NULL;
	game->map.ea_text_path = NULL;
	game->map.floor_color[0] = -1;
	game->map.floor_color[1] = -1;
	game->map.floor_color[2] = -1;
	game->map.sky_color[0] = -1;
	game->map.sky_color[1] = -1;
	game->map.sky_color[2] = -1;
	game->map.player_bool = 0;
	game->map.player_count = 0;
	game->map.map_height = 0;
	game->map.config[0] = "NO";
	game->map.config[1] = "SO";
	game->map.config[2] = "WE";
	game->map.config[3] = "EA";
	game->map.config[4] = "F";
	game->map.config[5] = "C";
	game->map.head = ft_lstnew(NULL);
}

void	init_final_color_vals(t_game *game)
{
	game->map.floor_hex = rgb_to_hex(game->map.floor_color);
	game->map.sky_hex = rgb_to_hex(game->map.sky_color);
}

void	init_move_bools(t_game *game)
{
	game->ray.first_mouse_time = 0;
	game->player.move_down = 0;
	game->player.move_up = 0;
	game->player.move_left = 0;
	game->player.move_right = 0;
	game->player.rotate_left = 0;
	game->player.rotate_right = 0;
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.map_height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map.map[i]))
		{
			if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'S'
			|| game->map.map[i][j] == 'E' || game->map.map[i][j] == 'W')
			{
				game->player.pos.x = j + 0.7;
				game->player.pos.y = i + 0.5;
				init_player_dir(&game->player, game->map.map[i][j]);
				game->map.map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	init_final_color_vals(game);
	init_move_bools(game);
	ft_createwin(game);
}

void	ft_createwin(t_game *game)
{
	game->mlx.mlx = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIDTH,
			HEIGHT, "./cub3d");
	game->mlx.image.img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	game->mlx.image.add = (int *)mlx_get_data_addr(game->mlx.image.img,
			&game->mlx.image.bpp, &game->mlx.image.w, &game->mlx.image.endian);
}
