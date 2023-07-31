/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:54:39 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/25 14:02:36 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	delete_image(t_program *data, int x)
{
	int	y;

	y = 0;
	while (y < data->images.draw_start)
	{
		mlx_put_pixel(data->images.main_img, x, y, 0x00000000);
		y++;
	}
	y = data->images.draw_start;
	while (y < data->images.draw_end)
	{
		mlx_put_pixel(data->images.main_img, x, y, 0x00000000);
		y++;
	}
	while (y < 1080)
	{
		mlx_put_pixel(data->images.main_img, x, y, 0x00000000);
		y++;
	}
	return (0);
}
