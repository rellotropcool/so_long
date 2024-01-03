/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:23:16 by aule-bre          #+#    #+#             */
/*   Updated: 2024/01/03 14:54:24 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int				fd_map;
	static t_map	map;
	static t_vars	vars;

	if (argc != 2)
		return (write(1, "invalid number of maps\n", 23), -1);
	fd_map = open(argv[1], O_RDONLY);
	map.map = map_init(fd_map);
	if (!map_is_valid(&map))
		return (0);
	vars_gen(&vars, &map);
	vars.c = 0;
	print_map(&vars);
	mlx_hook(vars.win.addr, 17, 0, ft_close, &vars);
	mlx_key_hook(vars.win.addr, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
