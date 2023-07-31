/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:59:49 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/25 13:02:46 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* int	ft_checknl(char *stash)
{
	int	i;

	i = 0;
	while (stash != NULL && stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new_s;
	int		i;
	int		j;

	new_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && s2[j])
	{
		new_s[i] = s2[j];
		i++;
		j++;
	}
	new_s[i] = '\0';
	free(s1);
	free(s2);
	return (new_s);
}

int	ft_definelinesize(char *stash)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (stash != NULL && stash[i])
	{
		if (stash[i] == '\n')
		{
			len++;
			break ;
		}
		len++;
		i++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, const char *src, int position, int size)
{
	int	i;

	dest = malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src != NULL && src[position])
	{
		dest[i] = src[position];
		i++;
		position++;
	}
	dest[i] = '\0';
	return (dest);
} */
