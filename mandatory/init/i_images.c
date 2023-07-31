/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_images.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:46:37 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/26 13:25:33 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	mlx_resize_image(data->images.n_wall, 1024, 1024);
	mlx_resize_image(data->images.s_wall, 1024, 1024);
	mlx_resize_image(data->images.e_wall, 1024, 1024);
	mlx_resize_image(data->images.w_wall, 1024, 1024);
	return (0);
}
