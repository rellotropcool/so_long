#include "so_long.h"

void	vars_gen(t_vars *vars, t_map map)
{
	vars->win.x = map.x * 40;
	vars->win.y = map.y * 40;
	vars->mlx = mlx_init();
	vars->map = map;
	vars->pos.x = map.start % (map.x + 1);
	vars->pos.y = map.start / (map.x + 1);
	vars->win.addr = mlx_new_window(vars->mlx, vars->win.x, vars->win.y,
			"so_long aule-bre");
	vars->player.addr = mlx_xpm_file_to_image(vars->mlx, "imgs/player.xpm",
			&vars->player.x, &vars->player.y);
	vars->empty.addr = mlx_xpm_file_to_image(vars->mlx, "imgs/empty.xpm",
			&vars->player.x, &vars->player.y);
	vars->wall.addr = mlx_xpm_file_to_image(vars->mlx, "imgs/wall.xpm",
			&vars->player.x, &vars->player.y);
	vars->coll.addr = mlx_xpm_file_to_image(vars->mlx, "imgs/coll.xpm",
			&vars->player.x, &vars->player.y);
	vars->start.addr = mlx_xpm_file_to_image(vars->mlx, "imgs/start.xpm",
			&vars->player.x, &vars->player.y);
	vars->exit.addr = mlx_xpm_file_to_image(vars->mlx, "imgs/exit.xpm",
			&vars->player.x, &vars->player.y);
}