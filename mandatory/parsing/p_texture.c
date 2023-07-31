/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:58:19 by hsebille          #+#    #+#             */
/*   Updated: 2023/07/31 17:13:39 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*set_texture(char *line)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] == 'C' || line[i] == 'F') && ft_strlen(line) > 3)
		return (ft_substr(line, i + 2, ft_strlen(line)));
	else if (line[i] == '.' && line[i + 1] == '/')
		return (ft_substr(line, i + 2, ft_strlen(line)));
	return (NULL);
}

void	free_textures(t_texture *textures, t_colors *colors)
{
	if (textures != NULL)
	{
		if (textures->north != NULL)
			free(textures->north);
		if (textures->south != NULL)
			free(textures->south);
		if (textures->west != NULL)
			free(textures->west);
		if (textures->east != NULL)
			free(textures->east);
	}
	if (colors != NULL)
	{
		if (colors->c_floor)
			free(colors->c_floor);
		if (colors->c_ceiling)
			free(colors->c_ceiling);
	}
}

static int	define_textures_colors(t_program *data, int i, int j)
{
	char	*substr;

	substr = ft_substr(data->map[i], j, spacechr(&data->map[i][j]));
	if (data->textures.north == NULL && ft_strncmp(substr, "NO", 3) == 0)
		data->textures.north = set_texture(&data->map[i][j + 2]);
	else if (data->textures.south == NULL && ft_strncmp(substr, "SO", 3) == 0)
		data->textures.south = set_texture(&data->map[i][j + 2]);
	else if (data->textures.west == NULL && ft_strncmp(substr, "WE", 3) == 0)
		data->textures.west = set_texture(&data->map[i][j + 2]);
	else if (data->textures.east == NULL && ft_strncmp(substr, "EA", 3) == 0)
		data->textures.east = set_texture(&data->map[i][j + 2]);
	else if (data->colors.c_floor == NULL && ft_strncmp(substr, "F", 2) == 0)
		data->colors.c_floor = set_texture(&data->map[i][j]);
	else if (data->colors.c_ceiling == NULL && ft_strncmp(substr, "C", 2) == 0)
		data->colors.c_ceiling = set_texture(&data->map[i][j]);
	else if (ft_strlen(data->map[i]) > 0 && data->map[i][j] != '\0')
	{
		free(substr);
		free_textures(&data->textures, &data->colors);
		error(MAP, NULL);
		return (1);
	}
	free(substr);
	return (0);
}

static int	error_handling(t_program *data, int i)
{
	data->map_content = get_map_content(data->map, i);
	if (data->map_content == NULL)
	{
		free_textures(&data->textures, &data->colors);
		error(MAP, NULL);
	}
	else if (colors_parsing(&data->colors) == 1)
	{
		ft_free_taboftab(data->map_content);
		free_textures(&data->textures, &data->colors);
		error(COLORS, NULL);
	}
	else
		return (0);
	return (1);
}

int	get_all_map(t_program *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i] && (got_walls(&data->textures) == 0 \
		|| got_colors(&data->colors) == 0))
	{
		j = 0;
		while (data->map[i][j] == ' ' || data->map[i][j] == '\t')
			j++;
		if (define_textures_colors(data, i, j) == 1)
			return (1);
		i++;
	}
	if (error_handling(data, i) == 1)
		return (1);
	return (0);
}
