/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:59:02 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/21 10:20:59 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int		ft_checknl(char *stash);
int		ft_definelinesize(char *stash);
char	*ft_clean_stash(char *stash);
char	*ft_defineline(char *stash, char *line);
char	*ft_definestash(char *buf, char *stash);
char	*ft_readfd(int fd, char *stash);
char	*ft_strcpy(char *dest, const char *src, int position, int size);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
