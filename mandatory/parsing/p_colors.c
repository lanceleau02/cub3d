/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_colors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:47:52 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/27 14:42:03 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	invalid_comma(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ',')
		return (1);
	while (str[i])
	{
		if (str[i] == ',' && !str[i + 1])
			return (1);
		if (str[i] == ',' && str[i + 1])
			if (str[i + 1] == ',')
				return (1);
		i++;
	}
	return (0);
}

static int	colors_core(int	*i_type, char **type)
{
	int	i;
	int	stash;

	i = 0;
	while (type[i])
	{
		stash = ft_atoi(type[i]);
		if (stash < 0 || stash > 255)
			return (1);
		else if (i < 3)
			i_type[i] = stash;
		i++;
	}
	if (i != 3)
		return (1);
	return (0);
}

int	colors_parsing(t_colors *colors)
{
	char	**floor;
	char	**ceiling;

	if (invalid_comma(colors->c_floor) == 1
		|| invalid_comma(colors->c_ceiling) == 1)
		return (1);
	floor = ft_split(colors->c_floor, ',');
	if (floor == NULL || floor[0] == NULL)
		return (1);
	ceiling = ft_split(colors->c_ceiling, ',');
	if (ceiling == NULL || ceiling[0] == NULL)
		return (1);
	if (colors_core(colors->i_floor, floor) == 1 \
		|| colors_core(colors->i_ceiling, ceiling) == 1)
	{
		ft_free_taboftab(floor);
		ft_free_taboftab(ceiling);
		return (1);
	}
	ft_free_taboftab(floor);
	ft_free_taboftab(ceiling);
	return (0);
}
