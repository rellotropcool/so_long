#include "so_long.h"

void	print_map(t_vars *vars)
{
	int i;
	int j;

	j = 0;
	while (j < vars->map.y)
	{
		i = 0;
		while (i < vars->map.x)
		{
			if (vars->map.map[j * (vars->map.x + 1) + i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win.addr,
					vars->wall.addr, i * 40, j * 40);
			else if (vars->map.map[j * (vars->map.x + 1) + i] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win.addr,
					vars->coll.addr, i * 40, j * 40);
			else if (vars->map.map[j * (vars->map.x + 1) + i] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win.addr,
					vars->exit.addr, i * 40, j * 40);
			else if (vars->map.map[j * (vars->map.x + 1) + i] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win.addr,
					vars->start.addr, i * 40, j * 40);
			else
				mlx_put_image_to_window(vars->mlx, vars->win.addr,
					vars->empty.addr, i * 40, j * 40);
			i++;
		}
		j++;
	}
	printf("%s\n", vars->map.map);
	return ;
}