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

int	check_values(t_map *map)
{
	int	i;

	int(c) = 0;
	int(e) = 0;
	int(p) = 0;
	i = 0;
	while (map->map[i])
	{
		if (map->map[i] == '0' || map->map[i] == '1' || map->map[i] == '\n')
			;
		else if (map->map[i] == 'C')
			c = 1;
		else if (map->map[i] == 'E')
			e++;
		else if (map->map[i] == 'P')
		{
			map->start = i;
			p++;
		}
		else
			break ;
		i++;
	}
	if (c && e == 1 && p == 1 && !map->map[i])
		return (1);
	return (0);
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
	if (!map->map)
		return (0);
	if (!check_rectangle(map))
		return (printf("rectangle error\n"), 0);
	if (!check_values(map))
		return (printf("values error\n"), 0);
	if (!check_borders(map->map))
		return (printf("borders error\n"), 0);
	return (printf("map valid\n"), 1);
}
