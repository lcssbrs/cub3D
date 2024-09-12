/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:11:11 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/21 20:11:12 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

int	ray_down(float angle)
{
	return (angle > 0 && angle < PI);
}

int	ray_up(float angle)
{
	return (!ray_down(angle));
}

int	ray_right(float angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

int	ray_left(float angle)
{
	return (!ray_right(angle));
}
