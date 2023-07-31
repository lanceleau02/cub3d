/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:48:12 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/25 14:00:01 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_player(t_program *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_content[i])
	{
		j = 0;
		while (data->map_content[i][j])
		{
			if (data->map_content[i][j] == 'N' || data->map_content[i][j] == 'S'
				|| data->map_content[i][j] == 'W'
				|| data->map_content[i][j] == 'E')
			{
				data->player.px = j + 0.5;
				data->player.py = i + 0.5;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
