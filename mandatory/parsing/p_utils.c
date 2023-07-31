/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:53:35 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/31 17:30:33 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	spacechr(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

int	got_walls(t_texture *textures)
{
	if (textures->north == NULL)
		return (0);
	if (textures->south == NULL)
		return (0);
	if (textures->west == NULL)
		return (0);
	if (textures->east == NULL)
		return (0);
	return (1);
}

int	got_colors(t_colors *colors)
{
	if (colors->c_floor == NULL)
		return (0);
	if (colors->c_ceiling == NULL)
		return (0);
	return (1);
}

void	skip_blank(char **map, int *start)
{
	int	j;

	j = 0;
	while (map[*start])
	{
		j = 0;
		while (map[*start][j] == ' ' || map[*start][j] == '\t')
			j++;
		if (ft_strlen(map[*start]) > 0 && map[*start][j] != '\0')
			break ;
		*start += 1;
	}
}
