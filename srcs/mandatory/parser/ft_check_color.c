/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:10:26 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/21 20:10:27 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

int	ft_atoi_color(char *str, int *i, int *res)
{
	while (str[*i] == ' ' || (str[*i] > 8 && str[*i] < 14) || str[*i] == ',')
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
		return (*res = -1);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		(*res) = *res * 10 + str[*i] - '0';
		(*i)++;
	}
	return (*res);
}

int	ft_control_color(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255)
		return (-4);
	return (0);
}

int	ft_rgb(int *r, int *g, int *b)
{
	return ((((*r << 8) + *g) << 8) + *b);
}

int	ft_get_color(char *str, int *i, t_color *color, int index)
{
	int	tmp;

	tmp = 0;
	(*i)++;
	ft_atoi_color(str, i, &color[index].r);
	ft_atoi_color(str, i, &color[index].g);
	ft_atoi_color(str, i, &color[index].b);
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] != '\0')
		return (-4);
	if (ft_atoi_color(str, i, &tmp) != 0
		|| ft_control_color(color[index].r, color[index].g, color[index].b)
		|| color[index].r < 0 || color[index].g < 0 || color[index].b < 0)
		return (-4);
	color[index].color = ft_rgb(&color[index].r,
			&color[index].g, &color[index].b);
	return (0);
}

int	check_color(t_color *color, char *str, int *check, int *j)
{
	int	error;

	if (str[*j] == 'F')
	{
		error = ft_get_color(str, j, color, 0);
		if (!(error))
			(*check) = 1;
	}
	else
	{
		error = ft_get_color(str, j, color, 1);
		if (!(error))
			(*check) = 1;
	}
	return (error);
}
