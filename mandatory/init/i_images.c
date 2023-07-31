/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_images.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:46:37 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/31 17:38:48 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	resize_img(t_program *data)
{
	bool	checker;

	checker = mlx_resize_image(data->images.n_wall, 1024, 1024);
	if (checker == false)
		return (1);
	checker = mlx_resize_image(data->images.s_wall, 1024, 1024);
	if (checker == false)
		return (1);
	checker = mlx_resize_image(data->images.e_wall, 1024, 1024);
	if (checker == false)
		return (1);
	checker = mlx_resize_image(data->images.w_wall, 1024, 1024);
	if (checker == false)
		return (1);
	return (0);
}

int	init_images(t_program *data)
{
	data->images.main_img = mlx_new_image(data->mlx, 1920, 1080);
	data->images.n_wall = mlx_new_image(data->mlx, 1920, 1080);
	data->images.n_wall = mlx_texture_to_image(data->mlx, \
		data->textures.north_t);
	data->images.s_wall = mlx_new_image(data->mlx, 1920, 1080);
	data->images.s_wall = mlx_texture_to_image(data->mlx, \
		data->textures.south_t);
	data->images.e_wall = mlx_new_image(data->mlx, 1920, 1080);
	data->images.e_wall = mlx_texture_to_image(data->mlx, \
		data->textures.east_t);
	data->images.w_wall = mlx_new_image(data->mlx, 1920, 1080);
	data->images.w_wall = mlx_texture_to_image(data->mlx, \
		data->textures.west_t);
	if (resize_img(data) == 1)
		return (1);
	return (0);
}
