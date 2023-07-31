/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:48:50 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/27 10:31:33 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	minus;
	long	nb;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	minus = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus *= -1;
		i++;
	}
	nb = 0;
	while (nptr[i] != '\0')
	{
		nb = nb * 10 + (nptr[i] - 48);
		if (ft_isdigit(nptr[i]) == 0 || nb * minus > 2147483647 \
			|| nb * minus < -2147483648)
			return (-1);
		i++;
	}
	return (minus * nb);
}
