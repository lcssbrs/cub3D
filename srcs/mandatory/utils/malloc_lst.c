/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:11:33 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/21 20:11:34 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

void	*lst_add(t_map *map, void *ptr)
{
	t_list	*elem;

	elem = ft_lstnew(ptr);
	if (!(elem))
	{
		free(ptr);
		return (NULL);
	}
	if (!(map->ptrs))
		map->ptrs = elem;
	else
		ft_lstadd_back(&map->ptrs, elem);
	return (ptr);
}

void	*malloc_list(t_map *map, int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	if (!lst_add(map, ptr))
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

void	*free_malloc_lst(t_map *map)
{
	ft_lstclear(&map->ptrs, free);
	return (0);
}
