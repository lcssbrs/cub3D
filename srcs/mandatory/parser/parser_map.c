/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:10:33 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/21 20:19:41 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

int	get_player_pos(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	if (!map->map)
		return (-5);
	while (map->map[y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (ft_strrchr("NSEW", map->map[y][x]))
			{
				map->pos_x = x;
				map->pos_y = y;
				map->tab->direction_player = map->map[y][x];
				map->player++;
			}
		}
		y++;
	}
	if (map->player == 0 || map->player > 1)
		return (-5);
	return (0);
}

int	ft_check_wall(char **map, int y, int x)
{
	int	i;
	int	j;

	i = ft_strlen(map[y]);
	j = ft_strlen2(map, 0);
	if (y == 0 || (i - 1) == 0 || (j - 1) == 0 || x == 0)
		return (-5);
	if (map[y - 1][x - 1] == '3' || map[y - 1][x] == '3'
			|| map[y - 1][x + 1] == '3')
		return (-5);
	else if (map[y][x - 1] == '3' || map[y][x + 1] == '3'
			|| map[y + 1][x - 1] == '3' || map[y + 1][x] == '3'
			|| map[y + 1][x + 1] == '3')
		return (-5);
	return (0);
}

int	ft_parse_map(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (ft_strrchr("013NSWE ", map->map[y][x]))
			{
				if (map->map[y][x] == '0' || ft_strrchr("NSWE", map->map[y][x]))
					if (ft_check_wall(map->map, y, x) < 0)
						return (-5);
			}
			else
				return (-5);
		}
	}
	map->tab->error = ft_raycasting(map, map->tab);
	return (map->tab->error);
}
