/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:59:40 by hsebille          #+#    #+#             */
/*   Updated: 2023/07/31 17:42:53 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "MLX42/MLX42_Int.h"
# include "MLX42/MLX42.h"

# define WIN_W 1920
# define WIN_H 1080
# define FOV 1

typedef enum e_errors
{
	MLX,
	ARGS,
	EXTENSION,
	DIRECTORY,
	BAD_FILE,
	TEXTURES,
	COLORS,
	MAP,
}	t_errors;

typedef struct s_texture
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	mlx_texture_t	*north_t;
	mlx_texture_t	*south_t;
	mlx_texture_t	*west_t;
	mlx_texture_t	*east_t;
}	t_texture;

typedef struct s_colors
{
	int		i_floor[3];
	int		i_ceiling[3];
	char	*c_floor;
	char	*c_ceiling;
}	t_colors;

typedef struct s_player
{
	float	px;
	float	py;
	float	dir_x;
	float	dir_y;
	float	old_dir_x;
}	t_player;

typedef struct s_screen
{
	float	width;
	float	plane_x;
	float	plane_y;
	float	cam_x;
	float	old_plane_x;
}	t_screen;

typedef struct s_rays
{
	int				step_x;
	int				step_y;
	int				tex_x;
	int				tex_y;
	int				ray_x;
	int				ray_y;
	int				hit;
	int				hit_side;
	int				y;
	float			dir_x;
	float			dir_y;
	float			deltadist_x;
	float			deltadist_y;
	float			sidedist_x;
	float			sidedist_y;
	float			perp_wall_dist;
	float			wall_x;
	struct s_rays	*prev;
	struct s_rays	*next;
}	t_rays;

typedef struct s_images
{
	int				draw_start;
	int				draw_end;
	int				line_height;
	int				x;
	mlx_image_t		*n_wall;
	mlx_image_t		*s_wall;
	mlx_image_t		*w_wall;
	mlx_image_t		*e_wall;
	mlx_image_t		*main_img;
}	t_images;

typedef struct s_program
{
	int			fd;
	char		**map;
	char		**map_content;
	void		*mlx;
	t_colors	colors;
	t_images	images;
	t_player	player;
	t_screen	screen;
	t_texture	textures;
}	t_program;

/* ************************************************************************** */
/*                                  GAMEPLAY                                  */
/* ************************************************************************** */

int		find_player(t_program *data);
void	key_hook(void *param);

/* ************************************************************************** */
/*                                    INIT                                    */
/* ************************************************************************** */

int		init_data(t_program *data);
int		init_images(t_program *data);
int		init_mlx(t_program *data);
int		load_png(t_program *data);
void	init_colors(t_program *data);
void	init_minimap(t_program *data);
void	init_player(t_program *data);
void	init_screen(t_program *data);
void	init_textures(t_program *data);

/* ************************************************************************** */
/*                                  PARSING                                   */
/* ************************************************************************** */

int		get_lines(char **map);
int		colors_parsing(t_colors *colors);
int		get_fd(char *file);
int		get_textures(t_colors *colors, t_texture *textures, char **map);
int		get_all_map(t_program *data);
int		got_colors(t_colors *colors);
int		got_walls(t_texture *textures);
int		pre_parsing(int argc, char **argv);
int		spacechr(char *str);
char	**get_map(int fd);
char	**get_map_content(char **map, int i);
void	error(int type, char *arg);
void	middle_free(t_program *data);
void	skip_blank(char **map, int *start);

/* ************************************************************************** */
/*                                 RENDERING                                  */
/* ************************************************************************** */

int		delete_image(t_program *data, int x);
void	draw_image(t_program *data, int x, int side);
void	launch_ray(t_rays *ray, t_program *data);
void	ray_init(t_rays *ray, t_program *data);
void	raycasting(t_program *data);
void	set_line_height(t_rays *ray, t_program *data);
void	set_sidedist(t_rays *ray, t_program *data);

/* ************************************************************************** */
/*                                  TEXTURES                                  */
/* ************************************************************************** */

int		get_color(mlx_image_t *wall, int y, int x);
void	define_tex_x(t_program *data, t_rays *ray);
void	define_wall_x(t_program *data, t_rays *ray);
void	textures(t_program *data, t_rays *ray, t_colors *colors);
int		rgba_to_int(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
void	free_textures(t_texture *textures, t_colors *colors);

/* ************************************************************************** */
/*                                   UTILS                                    */
/* ************************************************************************** */

void	free_list(t_rays *ray);
void	rays_lstadd_back(t_rays **lst, t_rays *new);
t_rays	*rays_lstnew(void);

#endif