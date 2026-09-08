/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:11:34 by ullorent          #+#    #+#             */
/*   Updated: 2023/05/22 15:23:23 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>

# define ALLSET 0b00111111

# define WIDTH  1920
# define HEIGHT 1080

# define MOVE 0.15
# define DIFF 0.2
# define ANGLE 0.66
# define ROTATE 0.07
# define MOUSE_ROTATE -0.0019

# define TEX_WIDTH  64
# define TEX_HEIGHT 64

# define TEX_IMG_WIDTH  1920
# define TEX_IMG_HEIGHT 1440

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_ray
{
	t_vector	pos;
	t_vector	dir;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		raydir_x;
	double		raydir_y;
	double		map_y;
	double		map_x;
	int			step_x;
	int			step_y;
	int			side;

	int			first_mouse_time;
}	t_ray;

typedef struct s_image
{
	void	*img;
	int		*add;
	int		bpp;
	int		w;
	int		h;
	int		endian;
	int		*color;
	int		check;
}				t_image;

typedef struct mlxData
{
	void		*mlx;
	void		*win;
	t_image		image;
}	t_mlxData;

typedef struct map
{
	int		map_height;
	int		map_width;
	char	**map;
	int		floor_color[3];
	int		sky_color[3];
	int		floor_hex;
	int		sky_hex;
	int		color;

	char	*no_text_path;
	char	*so_text_path;
	char	*we_text_path;
	char	*ea_text_path;

	t_image	no_texture;
	t_image	so_texture;
	t_image	we_texture;
	t_image	ea_texture;

	int		player_bool;
	int		player_count;

	char	*config[6];

	t_list	*head;
}	t_map;

typedef struct player
{
	t_vector	pos;
	t_vector	dir;
	double		plane_x;
	double		plane_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		m_speed;
	double		r_speed;

	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;

	int			rotate_right;
	int			rotate_left;
}	t_player;

typedef struct wall
{
	double		wall_x;
	int			tex_x;
	double		wall_y;
	int			tex_y;
	double		wall_start;
	double		wall_end;
	double		wall_height;
}	t_wall;

typedef struct game
{
	t_player	player;
	t_map		map;
	t_mlxData	mlx;
	t_ray		ray;
	t_wall		wall;
}				t_game;

/* --- Render functions --- */
void		ft_createwin(t_game *game);
int			ft_frame(t_game *game);
void		ft_img_clean(t_game *game);

/* --- Ray casting functions --- */
void		ft_send_ray(t_game *game);
void		ft_send_ray_steptwo(t_game *game);
void		set_step(t_game *game, double raydir_x, double raydir_y);
void		check_hit(t_game *game, int x, double raydir_x, double raydir_y);

void		calc_wall(t_game *game, int i, double raydir_x, double raydir_y);
double		calc_wall_xy(t_game *game, double rdir_x,
				double rdir_y, double w_dist);
void		draw_wall_texture(t_game *game, int start, int end, int x);
int			set_texture(t_game *game);

int			ft_move_up(t_game *game);
int			ft_move_down(t_game *game);
int			ft_move_right(t_game *game);
int			ft_move_left(t_game *game);

int			ft_rotate_left(t_game *game);
int			ft_rotate_right(t_game *game);

/* --- Mouse hook and movement functions --- */
void		ft_camera(t_game *game);
int			ft_mouse_rotate_right(t_game *game, double rotate_x);

/* ---  Hook functions --- */
int			ft_main_frame(t_game *game);
int			ft_first_move(int keyhook, t_game *game);
int			ft_second_move(int keyhook, t_game *game);

/* --- Args and map checker --- */
char		*ft_cleanline(char *line);
int			ft_fread(char *file, char *ext);

void		ft_mapchecker(t_game *game, int fd);
void		ft_mapchecker_action(t_game *game, char *line, int action);

int			map_line_checker(char *line, char *char_tosearch);
int			map_first_check(t_game *game, int fd);

int			map_texture_finder(t_game *game, char *line);
int			map_texture_opener(char *path);
int			map_texture_is_assigned(t_game *game, int bool);
int			map_texture_is_not_assigned(t_game *game);
int			map_colors_are_assigned(t_game *game, int bool);
int			map_colors_are_not_assigned(t_game *game);

int			is_map_closed(t_game *game, int height);
int			is_map_with_pos(t_game *game, int x, int y);
int			is_map_closed_conditions(t_game *game, int x, int y, int height);
int			is_map_firstline_closed(t_map *map);

void		map_error_returner(t_map *map, int bool);
void		ft_map_printer(t_game *game);

/* --- Map data saver --- */
void		ft_readmap(t_game	*game, char **argv);

int			map_texture_saver(t_game *game, char *line, int bool);
void		map_texture_saver_part2(t_game *game, char *path, int bool);
void		map_color_saver(t_game *game, char *line, int bool);

void		ft_map_list_saver(t_map *map, char *line);
void		ft_map_malloc_saver(t_map *map);

/* --- Values initialization functions --- */
int			init_texture_ea_we(t_game *game);
int			init_texture_so_no(t_game *game);
void		init_map_first_values_steps(t_game *game);
void		init_final_color_vals(t_game *game);
void		init_move_bools(t_game *game);
void		init_player(t_game *game);

void		init_player_dir(t_player *player, char dir);
void		init_player_dir_es(t_player *player, char dir);

/* ---  Utils functions --- */
char		*ft_strjoin_c3(char *s1, char *s2, int width, int width2);
char		*ft_strtrim_modified(char const *s1);
void		free_double_char_mem(char **str);
void		free_map(t_map *map);
int			ft_close(t_game *game);
int			rgb_to_hex(int *RGB);
int			ft_isspace(int c);

#endif