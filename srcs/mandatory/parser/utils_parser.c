/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:10:38 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/21 20:10:39 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

int	ft_atoi_cub(char *str, int *j)
{
	long		res;

	res = 0;
	while (str[*j] == ' ' || (str[*j] > 8 && str[*j] < 14))
		(*j)++;
	if (str[*j] == '-' || str[*j] == '+')
		return (0);
	while (str[*j] >= '0' && str[*j] <= '9')
	{
		res = res * 10 + str[*j] - '0';
		(*j)++;
	}
	return (res);
}

char	*ft_strdup_cub(t_map *map, char *s1, int *j)
{
	int		p;
	int		size;
	char	*dest;

	p = 0;
	size = ft_strlen(s1);
	dest = malloc_list(map, (size + 1) * sizeof(char));
	if (!(dest))
		return (0);
	while (s1[*j])
	{
		dest[p] = s1[*j];
		p++;
		(*j)++;
	}
	dest[p] = '\0';
	return (dest);
}
