/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:10:57 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/21 20:10:59 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

void	get_screen_size(t_map *map)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	mlx_get_screen_size(map->mlx_ptr, &width, &height);
	if (map->win_w > width)
		map->win_w = width;
	if (map->win_h > height)
		map->win_h = height;
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	pixel_get_color(t_img *txtrs, int x, int y)
{
	int	color;
	int	*int_addr;

	int_addr = (int *)txtrs->addr;
	if (y == 0 || x == 0)
		return (0);
	color = int_addr[y * txtrs->x + x];
	return (color);
}
