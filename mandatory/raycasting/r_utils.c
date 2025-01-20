/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:19:38 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/28 15:25:02 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_rays *ray, t_program *data)
{
	ray->dir_x = data->player.dir_x + data->screen.plane_x \
		* data->screen.cam_x;
	ray->dir_y = data->player.dir_y + data->screen.plane_y \
		* data->screen.cam_x;
	ray->deltadist_x = sqrt(1 + (ray->dir_y * ray->dir_y) \
		/ (ray->dir_x * ray->dir_x));
	ray->deltadist_y = sqrt(1 + (ray->dir_x * ray->dir_x) \
		/ (ray->dir_y * ray->dir_y));
	if ((ray->dir_x == 0 || ray->dir_y == 0) && (data->screen.plane_x != 0))
	{
		ray->deltadist_x = 1e45;
		ray->deltadist_y = 1e45;
	}
	ray->ray_x = data->player.px;
	ray->ray_y = data->player.py;
	ray->wall_x = 0.0;
	ray->tex_x = 0;
	ray->tex_y = 0;
	ray->y = 0;
}

void	set_sidedist(t_rays *ray, t_program *data)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (data->player.px - (double)ray->ray_x) \
			* ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = ((double)ray->ray_x + 1.0 - data->player.px) \
			* ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (data->player.py - (double)ray->ray_y) \
			* ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = ((double)ray->ray_y + 1.0 - data->player.py) \
			* ray->deltadist_y;
	}
}

void	launch_ray(t_rays *ray, t_program *data)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->ray_x += ray->step_x;
			ray->hit_side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->ray_y += ray->step_y;
			ray->hit_side = 1;
		}
		if (data->map_content[ray->ray_y][ray->ray_x] == '1')
			ray->hit = 1;
	}
	if (ray->hit_side == 0)
		ray->perp_wall_dist = (ray->ray_x - data->player.px \
			+ (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->ray_y - data->player.py \
			+ (1 - ray->step_y) / 2) / ray->dir_y;
}

void	set_line_height(t_rays *ray, t_program *data)
{
	data->images.line_height = (int)(1080 / ray->perp_wall_dist);
	data->images.draw_start = (1080 / 2) - (data->images.line_height / 2);
	if (data->images.draw_start < 0)
		data->images.draw_start = 0;
	data->images.draw_end = (data->images.line_height / 2) + (1080 / 2);
	if (data->images.draw_end >= 1080)
		data->images.draw_end = 1080 - 1;
}

void	draw_image(t_program *data, int x, int side)
{
	int	y;

	y = 0;
	while (y < data->images.draw_start)
	{
		mlx_put_pixel(data->images.main_img, x, y, 0x00C8FFFF);
		y++;
	}
	y = data->images.draw_start;
	while (y < data->images.draw_end)
	{
		if (side == 1)
			mlx_put_pixel(data->images.main_img, x, y, \
			(0x00C8FFFF >> 1) & 8355711);
		else
			mlx_put_pixel(data->images.main_img, x, y, 0xFF0000FF);
		y++;
	}
	while (y < 1080)
	{
		mlx_put_pixel(data->images.main_img, x, y, 0xC8C800FF);
		y++;
	}
}
