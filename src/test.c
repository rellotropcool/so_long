#include "so_long.h"

int	main(int argc, char **argv)
{
	int				fd_map;
	static t_map	map;
	static t_vars	vars;

	if (argc != 2)
		return (printf("invalid number of maps\n"), -1);
	fd_map = open(argv[1], O_RDONLY);
	map.map = map_init(fd_map);
	if (!map_is_valid(&map))
		return (0);
	vars_gen(&vars, &map);
	print_map(&vars);
	mlx_key_hook(vars.win.addr, key_hook, &vars);
	mlx_loop(vars.mlx);
}
