/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:09:13 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/21 20:09:15 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

char	*ft_strdup_long(t_map *map, const char *s1, int size)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc_list(map, (size + 1) * sizeof(char));
	if (!(dest))
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		if (dest[i] == ' ')
			dest[i] = '3';
		i++;
	}
	while (i < size)
	{
		dest[i] = '3';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(t_map *map, const char *s1)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = ft_strlen(s1);
	dest = malloc_list(map, (size + 1) * sizeof(char));
	if (!(dest))
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
