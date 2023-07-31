/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:39:24 by hsebille          #+#    #+#             */
/*   Updated: 2023/07/31 17:30:29 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_map(int fd)
{
	char	**map;
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		line = ft_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	map = ft_split(line, '\n');
	free(line);
	free(tmp);
	return (map);
}

static int	invalid_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'W' && str[i] != 'E')
			return (1);
		i++;
	}
	return (0);
}

static int	map_surrounded(char **map, char *str, int y, int x)
{
	while (str[x])
	{
		if (str[x] == '0')
		{
			if (ft_ischarset("10NSWE", map[y + 1][x]) == 0)
				return (1);
			if (ft_ischarset("10NSWE", map[y - 1][x]) == 0)
				return (1);
			if (ft_ischarset("10NSWE", map[y][x + 1]) == 0)
				return (1);
			if (ft_ischarset("10NSWE", map[y][x - 1]) == 0)
				return (1);
		}
		x++;
	}
	return (0);
}

static	int	parse_map_content(char **map, int i)
{
	int	j;
	int	p_check;

	p_check = 0;
	while (map[i])
	{
		j = 0;
		if (invalid_char(&map[i][j]) \
			|| map_surrounded(map, map[i], i, j))
			return (1);
		else if (map[i][j] != '1' && map[i][j] != ' ')
			return (1);
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' \
				|| map[i][j] == 'W' || map[i][j] == 'E')
				p_check++;
			j++;
		}
		i++;
	}
	if (p_check != 1)
		return (1);
	return (0);
}

char	**get_map_content(char **map, int start)
{
	char	**content;
	int		j;

	skip_blank(map, &start);
	if (parse_map_content(map, start))
	{
		return (NULL);
	}
	content = malloc(sizeof(char *) * (get_lines(map) + 1));
	if (content == NULL)
		return (NULL);
	j = 0;
	while (map[start])
	{
		content[j] = ft_substr(map[start], 0, ft_strlen(map[start]));
		if (content[j] == NULL)
		{
			ft_free_taboftab(content);
			return (NULL);
		}
		j++;
		start++;
	}
	content[j] = NULL;
	return (content);
}
