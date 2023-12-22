#include "so_long.h"

int map_is_endable(t_map *map, int *current, char *tile_checker, int *count);

void    check_next_tiles(t_map *map, int *current, char *tile_checker, int *count)
{  
    int i;

    i = 0;
    if (big_check_around(map, current))
        {
            check_around_bis(map, current, count, tile_checker);
            *current = next_tile(current, count[2], map);
            map_is_endable(map, current, tile_checker, count);
        }
    while (i < 4)
    {
        if (check_around(map, current, count))
        {
            *current = next_tile(current, count[2], map);
            if (count[2])
                count[2]--;
            else
                count[2] = 3; 
            map_is_endable(map, current, tile_checker, count);
        }
        i++;
    }
}

int map_is_endable(t_map *map, int *current, char *tile_checker, int *count)
{
    printf("current : %d\nmap :\n%s\ntile checker :\n%s\ncollectibles : %d\nexit : %d\n", *current, map->map, tile_checker, count[0], count[1]);
    while (*current)
    {
        if(map->map[*current] == 'C' && tile_checker[*current] != '1')
            count[0]++;
        if(map->map[*current] == 'E' && tile_checker[*current] != '1')
            count[1]++;
        tile_checker[*current] = '1';
        if (count[0] == map->collec && count[1] == 1)
            return (1);
        check_next_tiles(map, current, tile_checker, count);
    }
    return (0);
}