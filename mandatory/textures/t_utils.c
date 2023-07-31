/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:32:55 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/26 15:03:17 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgba_to_int(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	return ((red << 24) | (green << 16) | (blue << 8) | alpha);
}

int	get_color(mlx_image_t *wall, int y, int x)
{
	uint32_t	index;
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;

	index = (y * wall->width + x) * 4;
	red = wall->pixels[index];
	green = wall->pixels[index + 1];
	blue = wall->pixels[index + 2];
	return (rgba_to_int(red, green, blue, 255));
}

void	define_wall_x(t_program *data, t_rays *ray)
{
	if (ray->hit_side == 0)
		ray->wall_x = data->player.py + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = data->player.px + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	define_tex_x(t_program *data, t_rays *ray)
{
	ray->tex_x = (int)(ray->wall_x * (float)data->images.n_wall->width);
	if ((ray->hit_side == 1 && ray->step_y > 0) \
			|| (ray->hit_side == 0 && ray->step_x < 0))
		ray->tex_x = data->images.n_wall->width - ray->tex_x - 1;
}
