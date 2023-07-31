/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:57:35 by hsebille          #+#    #+#             */
/*   Updated: 2023/07/13 13:38:09 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_rays	*rays_lstlast(t_rays *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
		return (lst);
	}
	return (0);
}

t_rays	*rays_lstnew(void)
{
	t_rays	*new_element;

	new_element = malloc(sizeof(t_rays));
	if (new_element == NULL)
		return (NULL);
	new_element->hit = 0;
	new_element->next = NULL;
	return (new_element);
}

void	rays_lstadd_back(t_rays **lst, t_rays *new)
{
	t_rays	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = rays_lstlast(*lst);
		new->prev = tmp;
		tmp->next = new;
	}
}

void	free_list(t_rays *ray)
{
	t_rays	*tmp;

	while (ray != NULL)
	{
		tmp = ray;
		ray = ray->next;
		free(tmp);
	}
}
