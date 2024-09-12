/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:11:17 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/21 20:11:18 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

void	load_textures(t_cub *tab, t_map *map)
{
	int	i;

	i = 0;
	map->txtrs = malloc_list(map, (sizeof(t_img) * 4) + 1);
	fill_txt(map, &map->txtrs[0], tab->path_no);
	fill_txt(map, &map->txtrs[1], tab->path_so);
	fill_txt(map, &map->txtrs[2], tab->path_ea);
	fill_txt(map, &map->txtrs[3], tab->path_we);
}
