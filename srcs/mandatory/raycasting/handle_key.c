/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:10:53 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/21 20:10:55 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

int	ft_exit(t_map *map)
{
	if (map->txtrs[0].mlx_img)
		mlx_destroy_image(map->mlx_ptr, map->txtrs[0].mlx_img);
	if (map->txtrs[1].mlx_img)
		mlx_destroy_image(map->mlx_ptr, map->txtrs[1].mlx_img);
	if (map->txtrs[2].mlx_img)
		mlx_destroy_image(map->mlx_ptr, map->txtrs[2].mlx_img);
	if (map->txtrs[3].mlx_img)
		mlx_destroy_image(map->mlx_ptr, map->txtrs[3].mlx_img);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	map->win_ptr = NULL;
	return (0);
}

int	handle_keypress(int keysym, t_map *map)
{
	if (keysym == XK_Escape)
		ft_exit(map);
	if (keysym == XK_Up)
		map->play->walk_direct = 1;
	if (keysym == XK_Down)
		map->play->walk_direct = -1;
	if (keysym == XK_Right)
		map->play->turn_direct = 1;
	if (keysym == XK_Left)
		map->play->turn_direct = -1;
	if (keysym == XK_w)
		map->play->walk_direct = 1;
	if (keysym == XK_s)
		map->play->walk_direct = -1;
	if (keysym == XK_d)
		map->play->turn_direct = 1;
	if (keysym == XK_a)
		map->play->turn_direct = -1;
	return (0);
}

int	handle_keyrelease(int keysym, t_map *map)
{
	if (keysym == XK_Up)
		map->play->walk_direct = 0;
	if (keysym == XK_Down)
		map->play->walk_direct = 0;
	if (keysym == XK_Right)
		map->play->turn_direct = 0;
	if (keysym == XK_Left)
		map->play->turn_direct = 0;
	if (keysym == XK_w)
		map->play->walk_direct = 0;
	if (keysym == XK_s)
		map->play->walk_direct = 0;
	if (keysym == XK_d)
		map->play->turn_direct = 0;
	if (keysym == XK_a)
		map->play->turn_direct = 0;
	return (0);
}
