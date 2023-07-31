/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:29:08 by hsebille          #+#    #+#             */
/*   Updated: 2023/07/27 15:14:00 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_format(char *line)
{
	if (ft_strlen(line) < 4)
		return (1);
	else if (ft_strncmp(&line[ft_strlen(line) - 4], ".cub", 5) != 0)
		return (1);
	return (0);
}

int	pre_parsing(int argc, char **argv)
{
	if (argc != 2)
		error(ARGS, NULL);
	else if (map_format(argv[1]) == 1)
		error(EXTENSION, argv[1]);
	else
		return (0);
	return (1);
}

int	get_fd(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		error(DIRECTORY, file);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		error(BAD_FILE, file);
		return (-1);
	}
	return (fd);
}
