/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:50:55 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/31 16:20:11 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_program *data)
{
	t_rays	*ray;

	data->images.x = 0;
	ray = rays_lstnew();
	while (data->images.x < data->screen.width)
	{
		data->screen.cam_x = (2 * data->images.x / data->screen.width) - 1;
		ray_init(ray, data);
		set_sidedist(ray, data);
		launch_ray(ray, data);
		set_line_height(ray, data);
		textures(data, ray, &data->colors);
		rays_lstadd_back(&ray, rays_lstnew());
		ray = ray->next;
		data->images.x++;
	}
	while (data->images.x > 0)
	{
		ray = ray->prev;
		data->images.x--;
	}
	free_list(ray);
}
