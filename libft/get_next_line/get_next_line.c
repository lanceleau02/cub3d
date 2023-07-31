/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:58:06 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/25 13:02:39 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char	*ft_readfd(int fd, char *stash)
{
	char	*buf;
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	while (ft_checknl(stash) == 0 && ret > 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL);
		ret = read(fd, buf, BUFFER_SIZE);
		if ((stash == NULL && ret == 0) || ret == -1)
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		buf[ret] = '\0';
		stash = ft_definestash(buf, stash);
		i++;
	}
	return (stash);
}

char	*ft_definestash(char *buf, char *stash)
{
	char	*copy;
	int		i;

	if (stash == NULL)
	{
		copy = malloc(sizeof(char) * ft_strlen(buf) + 1);
		if (copy == NULL)
			return (NULL);
		i = 0;
		while (buf[i])
		{
			copy[i] = buf[i];
			i++;
		}
		copy[i] = '\0';
		free(buf);
		buf = NULL;
		return (copy);
	}
	stash = ft_strjoin(stash, buf);
	return (stash);
}

char	*ft_defineline(char *stash, char *line)
{
	int		i;

	line = malloc(sizeof(char) * (ft_definelinesize(stash) + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			line[i] = '\n';
			i++;
			break ;
		}
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clean_stash(char *stash)
{
	int		i;
	int		size;
	char	*new_stash;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		new_stash = NULL;
		free(stash);
		stash = NULL;
		return (NULL);
	}
	i++;
	size = 0;
	while (stash[i + size])
		size++;
	new_stash = NULL;
	new_stash = ft_strcpy(new_stash, stash, i, size);
	free(stash);
	stash = NULL;
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_readfd(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = NULL;
	line = ft_defineline(stash, line);
	stash = ft_clean_stash(stash);
	if (line[0] == '\0')
	{
		free(stash);
		stash = NULL;
		free(line);
		line = NULL;
		return (NULL);
	}
	return (line);
} */

static int	nl_in_str(char *s)
{
	int	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*join(char *line, char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line != NULL && line[i] != '\0')
		i++;
	str = malloc(sizeof(char) * (i + BUFFER_SIZE + 1));
	i = 0;
	while (line != NULL && line[i] != '\0')
	{
		str[i] = line[i];
		i++;
	}
	j = 0;
	while (buf[j] != '\0')
	{
		str[i] = buf[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(line);
	return (str);
}

static int	cut(char *line, char **buf)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	*buf = malloc(sizeof(char) * (i + 2));
	j = 0;
	while (j <= i)
	{
		(*buf)[j] = line[j];
		j++;
	}
	(*buf)[j] = '\0';
	if (nl_in_str(line) == 0 || line[j] == '\0')
		return (1);
	i = 0;
	while (line[j] != '\0')
	{
		line[i] = line[j];
		i++;
		j++;
	}
	line[i] = '\0';
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			read_bytes;
	static char	*line = NULL;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buf[read_bytes] = '\0';
		line = join(line, buf);
		if (nl_in_str(line) == 1)
			break ;
	}
	free(buf);
	buf = NULL;
	if (line != NULL)
		read_bytes = cut(line, &buf);
	if (read_bytes == 1)
	{
		free(line);
		line = NULL;
	}
	return (buf);
}
