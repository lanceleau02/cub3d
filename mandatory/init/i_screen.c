/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_screen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:54:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/26 14:29:14 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_screen(t_program *data)
{
	if (data->map_content[(int)trunc(data->player.py - 0.5)] \
		[(int)trunc(data->player.px - 0.5)] == 'N')
	{
		data->screen.plane_x = 0.66;
		data->screen.plane_y = 0.0;
	}
	else if (data->map_content[(int)trunc(data->player.py - 0.5)] \
		[(int)trunc(data->player.px - 0.5)] == 'S')
	{
		data->screen.plane_x = -0.66;
		data->screen.plane_y = 0.0;
	}
	else if (data->map_content[(int)trunc(data->player.py - 0.5)] \
		[(int)trunc(data->player.px - 0.5)] == 'W')
	{
		data->screen.plane_x = 0.0;
		data->screen.plane_y = -0.66;
	}
	if (data->map_content[(int)trunc(data->player.py - 0.5)] \
		[(int)trunc(data->player.px - 0.5)] == 'E')
	{
		data->screen.plane_x = 0.0;
		data->screen.plane_y = 0.66;
	}
	data->screen.width = 1920;
}
