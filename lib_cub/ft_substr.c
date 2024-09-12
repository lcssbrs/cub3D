/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:09:30 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/21 20:09:32 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

char	*ft_substr(t_map *map, char *s, unsigned int start, size_t len)
{
	char		*dest;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	dest = malloc_list(map, (len + 1) * sizeof(char));
	if (!(dest))
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			dest[j] = s[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_substr_cub(t_map *map, char *s, unsigned int start, size_t len)
{
	char		*dest;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	dest = malloc_list(map, (len + 1) * sizeof(char));
	if (!(dest))
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			dest[j] = s[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
