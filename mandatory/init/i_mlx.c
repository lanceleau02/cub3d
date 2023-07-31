/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:21:09 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/31 17:42:02 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	middle_free(t_program *data)
{
	if (data->textures.north_t != NULL)
		mlx_delete_texture(data->textures.north_t);
	if (data->textures.south_t != NULL)
		mlx_delete_texture(data->textures.south_t);
	if (data->textures.west_t != NULL)
		mlx_delete_texture(data->textures.west_t);
	if (data->textures.east_t != NULL)
		mlx_delete_texture(data->textures.east_t);
	ft_free_taboftab(data->map);
	ft_free_taboftab(data->map_content);
	free_textures(&data->textures, &data->colors);
}

int	load_png(t_program *data)
{
	data->textures.north_t = mlx_load_png(data->textures.north);
	data->textures.south_t = mlx_load_png(data->textures.south);
	data->textures.west_t = mlx_load_png(data->textures.west);
	data->textures.east_t = mlx_load_png(data->textures.east);
	if (data->textures.north_t == NULL || data->textures.south_t == NULL \
		|| data->textures.west_t == NULL || data->textures.east_t == NULL)
	{
		middle_free(data);
		return (1);
	}
	return (0);
}

int	init_mlx(t_program *data)
{
	data->mlx = mlx_init(1920, 1080, "cub3d", 0);
	if (data->mlx == NULL)
	{
		error(MLX, NULL);
		return (1);
	}
	return (0);
}
