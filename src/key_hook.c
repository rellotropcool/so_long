#include "so_long.h"

int	check_up(t_vars *vars)
{
	int	x;
	int	y;
	int	len;

	x = vars->pos.x;
	y = vars->pos.y;
	len = vars->map.x + 1;
	if (vars->map.map[(y - 1) * len + x] == '1')
		return (0);
	return (1);
}

int	check_down(t_vars *vars)
{
	int	x;
	int	y;
	int	len;

	x = vars->pos.x;
	y = vars->pos.y;
	len = vars->map.x + 1;
	if (vars->map.map[(y + 1) * len + x] == '1')
		return (0);
	return (1);
}

int	check_left(t_vars *vars)
{
	int	x;
	int	y;
	int	len;

	x = vars->pos.x;
	y = vars->pos.y;
	len = vars->map.x + 1;
	if (vars->map.map[y * len + x - 1] == '1')
		return (0);
	return (1);
}

int	check_right(t_vars *vars)
{
	int	x;
	int	y;
	int	len;

	x = vars->pos.x;
	y = vars->pos.y;
	len = vars->map.x + 1;
	if (vars->map.map[y * len + x + 1] == '1')
		return (0);
	return (1);
}

int	ft_close(t_vars *vars)
{
	(void)vars;
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65361 && check_left(vars))
		vars->pos.x--;
	if (keycode == 65363 && check_right(vars))
		vars->pos.x++;
	if (keycode == 65362 && check_up(vars))
		vars->pos.y--;
	if (keycode == 65364 && check_down(vars))
		vars->pos.y++;
	//if (keycode == 17 || keycode == 65307)
		//return(ft_close(vars));
	printf("%d\n", keycode);
	print_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win.addr, vars->player.addr,
		vars->pos.x * 40, vars->pos.y * 40);
	return (0);
}
