/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:58:50 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/27 11:20:05 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data(t_program *data)
{
	data->map = get_map(data->fd);
	if (data->map == NULL)
		return (1);
	if (get_all_map(data) == 1)
	{
		ft_free_taboftab(data->map);
		return (1);
	}
	return (0);
}
