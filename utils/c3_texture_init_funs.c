/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_texture_init_funs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:37:26 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/17 17:14:33 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_texture_so_no(t_game *game)
{
	game->map.so_texture.img = mlx_xpm_file_to_image(game->mlx.mlx,
			game->map.so_text_path, &game->map.so_texture.w,
			&game->map.so_texture.h);
	if (game->map.so_texture.img == NULL)
		return (1);
	game->map.so_texture.add = (int *)mlx_get_data_addr(
			game->map.so_texture.img, &game->map.so_texture.bpp,
			&game->map.so_texture.w, &game->map.so_texture.endian);
	game->map.no_texture.img = mlx_xpm_file_to_image(game->mlx.mlx,
			game->map.no_text_path, &game->map.no_texture.w,
			&game->map.no_texture.h);
	if (game->map.no_texture.img == NULL)
		return (1);
	game->map.no_texture.add = (int *)mlx_get_data_addr(
			game->map.no_texture.img, &game->map.no_texture.bpp,
			&game->map.no_texture.w, &game->map.no_texture.endian);
	return (0);
}

int	init_texture_ea_we(t_game *game)
{
	game->map.ea_texture.img = mlx_xpm_file_to_image(game->mlx.mlx,
			game->map.ea_text_path, &game->map.ea_texture.w,
			&game->map.ea_texture.h);
	if (game->map.ea_texture.img == NULL)
		return (1);
	game->map.ea_texture.add = (int *)mlx_get_data_addr(
			game->map.ea_texture.img, &game->map.ea_texture.bpp,
			&game->map.ea_texture.w, &game->map.ea_texture.endian);
	game->map.we_texture.img = mlx_xpm_file_to_image(game->mlx.mlx,
			game->map.we_text_path, &game->map.we_texture.w,
			&game->map.we_texture.h);
	if (game->map.we_texture.img == NULL)
		return (1);
	game->map.we_texture.add = (int *)mlx_get_data_addr(
			game->map.we_texture.img, &game->map.we_texture.bpp,
			&game->map.we_texture.w, &game->map.we_texture.endian);
	return (0);
}
