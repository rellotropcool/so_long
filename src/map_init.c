/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:22:29 by aule-bre          #+#    #+#             */
/*   Updated: 2023/12/29 15:22:30 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_init(int fd)
{
	int			c;
	static char	*map;
	char		*tmp;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	c = 1;
	tmp = malloc(2 * sizeof(char));
	while (c > 0)
	{
		c = read(fd, tmp, 1);
		if (c != 1)
			break ;
		tmp[1] = 0;
		map = ft_strjoin(map, tmp);
	}
	free(tmp);
	return (map);
}
