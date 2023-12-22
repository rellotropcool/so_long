#include "so_long.h"

void fill_checker(char *str, t_map *map)
{
    int i;

    i = -1;
    while (++i < (map->x + 1) * map->y)
    {
    	if (i && (i % (map->x + 1)) == map->x)
	    	str[i] = 10;
	    else 
	    	str[i] = '0';
   	}
    str[i - 1] = 0;
}   

int check_around(t_map *map, int *current, int *count)
{
    if (count[2] == RIGHT && (map->map[*current + 1] == '1'))
    {
        count[2] = UP;
        return (0);
    }
    if (count[2] == LEFT && (map->map[*current - 1] == '1'))
        {
        count[2] = DOWN;
        return (0);
    }
    if (count[2] == DOWN && (map->map[*current + map->x + 1] == '1'))
        {
        count[2] = RIGHT;
        return (0);
    }
    if (count[2] == UP && (map->map[*current - map->x - 1] == '1'))
        {
        count[2] = LEFT;
        return (0);
    }
    return (1);
}

void check_around_bis(t_map *map, int *current, int *count, char *tile_checker)
{
    if (count[2] == RIGHT && (tile_checker[*current + 1] == '1'))
        count[2] = UP;
    if (count[2] == LEFT && (tile_checker[*current - 1] == '1'))
        count[2] = DOWN;
    if (count[2] == DOWN && (tile_checker[*current + map->x + 1] == '1'))
        count[2] = RIGHT;
    if (count[2] == UP && (tile_checker[*current - map->x - 1] == '1'))
        count[2] = LEFT;
}


int big_check_around(t_map *map, int *current)
{
    if (map->map[*current - 1] == '1')
        return (0);
    if (map->map[*current + 1] == '1')
        return (0);
    if (map->map[*current + map->x + 1] == '1')
        return (0);
    if (map->map[*current - map->x - 1] == '1')
        return (0);
    return (1);
}

int next_tile(int *current, int direction, t_map *map)
{
    if (direction == UP)
        return (*current - map->x - 1);
    if (direction == DOWN)
        return (*current + map->x + 1);
    if (direction == LEFT)
        return (*current - 1);
    if (direction == RIGHT)
        return (*current + 1);
    return (0);
}