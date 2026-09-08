/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:26:29 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/22 15:36:24 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_dir_es(t_player *player, char dir)
{
	if (dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}

void	init_player_dir(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (dir == 'E' || dir == 'S')
		init_player_dir_es(player, dir);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (ft_fread(argv[1], ".cub"))
			exit (1);
		ft_readmap(&game, argv);
		init_player(&game);
		if (init_texture_ea_we(&game) || init_texture_so_no(&game))
			map_error_returner(&game.map, 4);
		mlx_mouse_hide();
		mlx_hook(game.mlx.win, 2, 1L << 0, ft_first_move, &game);
		mlx_hook(game.mlx.win, 3, 1L << 0, ft_second_move, &game);
		mlx_loop_hook(game.mlx.mlx, ft_main_frame, &game);
		mlx_hook(game.mlx.win, 17, 1L << 5, ft_close, &game);
		mlx_loop(game.mlx.mlx);
	}
	else
	{
		printf("Error\n");
		printf("Incorrect arguments!\n");
		return (1);
	}
	return (0);
}
