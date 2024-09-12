/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:09:34 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/21 20:09:35 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_read_fd(t_map *map, char *dst, int fd)
{
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0
		|| !(buf))
		return (NULL);
	if (dst == NULL)
		dst = ft_strdup(map, "");
	while (!(ft_strchr(dst, '\n')))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		buf[ret] = '\0';
		dst = ft_strjoin(map, dst, buf);
		if (ret == 0)
			break ;
	}
	free(buf);
	return (dst);
}

int	get_next_line(t_map *map, int fd, char **line)
{
	static char	*dst;
	char		*ptr;
	char		*tmp;

	dst = ft_read_fd(map, dst, fd);
	if (!(dst) || !line)
		return (-1);
	ptr = ft_strchr(dst, '\n');
	if (ptr)
	{
		tmp = dst;
		*line = ft_substr(map, tmp, 0, ptr - dst);
		dst = ft_strdup(map, dst + (ptr - dst) + 1);
		return (1);
	}
	else
	{
		*line = ft_strdup(map, dst);
		dst = NULL;
		return (0);
	}
}
