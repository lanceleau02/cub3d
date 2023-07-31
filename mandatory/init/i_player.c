/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:54:04 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/26 14:28:36 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_program *data)
{
	find_player(data);
	if (data->map_content[(int)trunc(data->player.py - 0.5)] \
		[(int)trunc(data->player.px - 0.5)] == 'N')
	{
		data->player.dir_x = 0.0;
		data->player.dir_y = -1.0;
	}
	else if (data->map_content[(int)trunc(data->player.py - 0.5)] \
		[(int)trunc(data->player.px - 0.5)] == 'S')
	{
		data->player.dir_x = 0.0;
		data->player.dir_y = 1.0;
	}
	else if (data->map_content[(int)trunc(data->player.py - 0.5)] \
		[(int)trunc(data->player.px - 0.5)] == 'W')
	{
		data->player.dir_x = -1.0;
		data->player.dir_y = 0.0;
	}
	else if (data->map_content[(int)trunc(data->player.py - 0.5)] \
		[(int)trunc(data->player.px - 0.5)] == 'E')
	{
		data->player.dir_x = 1.0;
		data->player.dir_y = 0.0;
	}
}
