/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_textures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:34:38 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/31 17:24:55 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceiling(t_program *data, t_rays *ray, t_colors *colors)
{
	int	color;

	color = rgba_to_int(colors->i_ceiling[0], colors->i_ceiling[1], \
		colors->i_ceiling[2], 255);
	while (ray->y < data->images.draw_start)
	{
		mlx_put_pixel(data->images.main_img, data->images.x, ray->y, \
			color);
		ray->y++;
	}
}

static void	draw_textures(t_program *data, t_rays *ray)
{
	float		step;
	float		tex_pos;

	step = 1.0 * data->images.n_wall->height / data->images.line_height;
	tex_pos = (data->images.draw_start - (1080 / 2) \
		+ data->images.line_height / 2) * step;
	ray->y = data->images.draw_start;
	while (ray->y < data->images.draw_end)
	{
		ray->tex_y = (int)tex_pos & (data->images.n_wall->height - 1);
		tex_pos += step;
		if (ray->hit_side == 1 && ray->step_y < 0)
			mlx_put_pixel(data->images.main_img, data->images.x, ray->y, \
			get_color(data->images.s_wall, ray->tex_y, ray->tex_x));
		else if (ray->hit_side == 1 && ray->step_y > 0)
			mlx_put_pixel(data->images.main_img, data->images.x, ray->y, \
			get_color(data->images.n_wall, ray->tex_y, ray->tex_x));
		else if (ray->hit_side == 0 && ray->step_x < 0)
			mlx_put_pixel(data->images.main_img, data->images.x, ray->y, \
			get_color(data->images.w_wall, ray->tex_y, ray->tex_x));
		else if (ray->hit_side == 0 && ray->step_x > 0)
			mlx_put_pixel(data->images.main_img, data->images.x, ray->y, \
			get_color(data->images.e_wall, ray->tex_y, ray->tex_x));
		ray->y++;
	}
}

static void	draw_floor(t_program *data, t_rays *ray, t_colors *colors)
{
	int	color;

	color = rgba_to_int(colors->i_floor[0], colors->i_floor[1], \
		colors->i_floor[2], 255);
	while (ray->y < 1080)
	{
		mlx_put_pixel(data->images.main_img, data->images.x, ray->y, \
			color);
		ray->y++;
	}
}

void	textures(t_program *data, t_rays *ray, t_colors *colors)
{
	define_wall_x(data, ray);
	define_tex_x(data, ray);
	draw_ceiling(data, ray, colors);
	draw_textures(data, ray);
	draw_floor(data, ray, colors);
}
