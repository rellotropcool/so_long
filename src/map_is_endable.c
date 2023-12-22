#include "so_long.h"

int map_is_endable(t_map *map, int current, char *tile_checker, int *count);

void    check_next_tiles(t_map *map, int current, char *tile_checker, int *count)
{  
    printf("ok, %d\n", map->x);
    map_is_endable(map, current + map->x + 1, tile_checker, count);
    map_is_endable(map, current - 1, tile_checker, count);
    map_is_endable(map, current + 1, tile_checker, count);
    map_is_endable(map, current - map->x - 1, tile_checker, count);
}

int map_is_endable(t_map *map, int current, char *tile_checker, int *count)
{
    printf("current : %d %d\nmap :\n%s\ntile checker :\n%s\ncollectibles : %d\nexit : %d\n", current % map->x, current / map->x, map->map, tile_checker, count[0], count[1]);
    if (map->map[current] != '1')
    {
        printf("value : %c\n", map->map[current]);
        if(map->map[current] == 'C' && tile_checker[current] != '1')
            count[0]++;
        if(map->map[current] == 'E' && tile_checker[current] != '1')
            count[1]++;
        tile_checker[current] = '1';
        check_next_tiles(map, current, tile_checker, count);
    }
    //if (no_tiles(map, current, )count[0] == map->collec && count[1] == 1)
    //    return (1);
    return (0);
}