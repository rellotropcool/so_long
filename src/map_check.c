/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:22:07 by aule-bre          #+#    #+#             */
/*   Updated: 2023/12/29 15:22:09 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map->map[i] != '\n')
		i++;
	map->x = i;
	while (map->map[j])
	{
		if (j % (i + 1) != i && (map->map[j] == '\n' || !map->map[j]))
			return (0);
		else if (j % (i + 1) == i && (map->map[j] != '\n' && map->map[j]))
			return (0);
		j++;
	}
	map->y = j / i;
	return (1);
}

int	ft_strlen2(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != '\n')
			j++;
		i++;
	}
	return (j);
}

int	check_values(t_map *map)
{
	int	i;
	int	o;
	int	e;
	int	p;
	int	c;

	c = ft_count(map->map, 'C');
	e = ft_count(map->map, 'E');
	p = ft_count(map->map, 'P');
	o = ft_count(map->map, '0');
	i = ft_count(map->map, '1');
	if (c + e + p + i + o != ft_strlen2(map->map))
		return (0);
	if (!c || e != 1 || p != 1)
		return (0);
	map->start = get_p(map->map);
	map->start_dup = get_p(map->map);
	map->collec = c;
	return (1);
}

int	check_borders(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		if (map[i++] != '1')
			return (0);
	while (map[i])
	{
		if (map[i] == '\n')
			if (map[i + 1] && (map[i - 1] != '1' || map[i + 1] != '1'))
				return (0);
		i++;
	}
	while (map[--i] != '\n')
		if (map[i] != '1')
			return (0);
	return (1);
}

int	map_is_valid(t_map *map)
{
	char	str[4096];

	map->previous = map->start;
	if (!map->map)
		return (write(1, "no map loser\n", 13), 0);
	if (!check_rectangle(map))
		return (write(1, "rectangle error\n", 16), 0);
	if (!check_values(map))
		return (write(1, "values error\n", 13), 0);
	if (!check_borders(map->map))
		return (write(1, "borders error\n", 14), 0);
	fill_checker(str, map);
	if (!map_is_endable(map, &map->start_dup, str))
		return (write(1, "map impossible\n", 15), 0);
	return (write(1, "map valid\n", 10), 1);
}
