/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_all.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:41:42 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/27 15:50:05 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	error_bis(int type, char *arg)
{
	if (type == BAD_FILE)
	{
		ft_putstr_fd("cub3d: ", 2);
		perror(arg);
	}
	else if (type == COLORS)
		ft_putstr_fd("cub3d: Invalid color(s).\n", 2);
	else if (type == MAP)
		ft_putstr_fd("cub3d: Invalid map.\n", 2);
}

void	error(int type, char *arg)
{
	ft_putstr_fd("Error\n", 2);
	if (type == MLX)
		ft_putstr_fd("cub3d: Impossible to load mlx.", 2);
	if (type == ARGS)
	{
		ft_putstr_fd("cub3d: Invalid number of arguments -> ", 2);
		ft_putstr_fd("usage : ./cub3d [map.cub]\n", 2);
	}
	else if (type == EXTENSION)
	{
		ft_putstr_fd("cub3d: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": Invalid map format, need [map.cub]\n", 2);
	}
	else if (type == DIRECTORY)
	{
		ft_putstr_fd("cub3d: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": is a directory\n", 2);
	}
	else
		error_bis(type, arg);
}
