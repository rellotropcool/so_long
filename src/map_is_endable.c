/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_endable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:22:41 by aule-bre          #+#    #+#             */
/*   Updated: 2023/12/29 15:22:42 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(t_map *map, int current, char *tile_checker)
{
	if (map->map[current] != '1' && tile_checker[current] != '1')
	{
		tile_checker[current] = '1';
		fill_map(map, current + 1, tile_checker);
		fill_map(map, current - 1, tile_checker);
		fill_map(map, current + map->x + 1, tile_checker);
		fill_map(map, current - map->x - 1, tile_checker);
	}
}

int	map_is_endable(t_map *map, int *current, char *tile_checker)
{
	int	collec;
	int	exit;
	int	i;

	i = 0;
	collec = 0;
	exit = 0;
	fill_map(map, *current, tile_checker);
	while (map->map[i])
	{
		if (map->map[i] == 'C' && tile_checker[i] == '1')
			collec++;
		if (map->map[i] == 'E' && tile_checker[i] == '1')
			exit++;
		i++;
	}
	if (collec == map->collec && exit == 1)
		return (1);
	return (0);
}
