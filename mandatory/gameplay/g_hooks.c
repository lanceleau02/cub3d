/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:51:28 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/26 15:03:48 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	up_down(t_program *data, float mv_factor_x, float mv_factor_y)
{
	if (data->map_content[(int)trunc(data->player.py)] \
		[(int)trunc((data->player.px + mv_factor_x))] != '1')
		data->player.px += mv_factor_x;
	if (data->map_content[(int)trunc((data->player.py + mv_factor_y))] \
		[(int)trunc(data->player.px)] != '1')
		data->player.py += mv_factor_y;
}

static void	left_right(t_program *data, float mv_factor_x, float mv_factor_y)
{
	if (data->map_content[(int)trunc(data->player.py)] \
		[(int)trunc((data->player.px - mv_factor_y))] != '1')
		data->player.px -= mv_factor_y;
	if (data->map_content[(int)trunc((data->player.py + mv_factor_x))] \
		[(int)trunc(data->player.px)] != '1')
		data->player.py += mv_factor_x;
}

static void	rotation(t_program *data, float constant)
{
	data->player.old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(constant) \
		- data->player.dir_y * sin(constant);
	data->player.dir_y = data->player.old_dir_x * sin(constant) \
		+ data->player.dir_y * cos(constant);
	data->screen.old_plane_x = data->screen.plane_x;
	data->screen.plane_x = data->screen.plane_x * cos(constant) \
		- data->screen.plane_y * sin(constant);
	data->screen.plane_y = data->screen.old_plane_x * sin(constant) \
		+ data->screen.plane_y * cos(constant);
}

void	exit_program(t_program *data)
{
	ft_free_taboftab(data->map);
	ft_free_taboftab(data->map_content);
	free(data->colors.c_ceiling);
	free(data->colors.c_floor);
	mlx_delete_image(data->mlx, data->images.n_wall);
	mlx_delete_image(data->mlx, data->images.s_wall);
	mlx_delete_image(data->mlx, data->images.w_wall);
	mlx_delete_image(data->mlx, data->images.e_wall);
	mlx_delete_image(data->mlx, data->images.main_img);
	free(data->textures.north);
	free(data->textures.south);
	free(data->textures.west);
	free(data->textures.east);
	mlx_delete_texture(data->textures.north_t);
	mlx_delete_texture(data->textures.south_t);
	mlx_delete_texture(data->textures.west_t);
	mlx_delete_texture(data->textures.east_t);
	mlx_terminate(data->mlx);
	exit(0);
}

void	key_hook(void *param)
{
	t_program	*data;
	float		speed;		

	data = (t_program *)param;
	speed = 0.07 / hypot(data->player.dir_x, data->player.dir_y);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE) == true)
		exit_program(data);
	raycasting(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) == true)
		up_down(data, (data->player.dir_x * speed), \
		(data->player.dir_y * speed));
	if (mlx_is_key_down(data->mlx, MLX_KEY_S) == true)
		up_down(data, -(data->player.dir_x * speed), \
		-(data->player.dir_y * speed));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D) == true)
		left_right(data, (data->player.dir_x * speed), \
		(data->player.dir_y * speed));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A) == true)
		left_right(data, -(data->player.dir_x * speed), \
		-(data->player.dir_y * speed));
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) == true)
		rotation(data, 0.07);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) == true)
		rotation(data, -0.07);
	delete_image(data, data->images.x);
}
