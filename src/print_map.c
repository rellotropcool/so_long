/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:23:02 by aule-bre          #+#    #+#             */
/*   Updated: 2023/12/29 15:23:03 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_vars *vars, int i, int j)
{
	if (vars->map.map[j * (vars->map.x + 1) + i] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win.addr,
			vars->wall.addr, i * 40, j * 40);
	else if (vars->map.map[j * (vars->map.x + 1) + i] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win.addr,
			vars->coll.addr, i * 40, j * 40);
	else if (vars->map.map[j * (vars->map.x + 1) + i] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win.addr,
			vars->end.addr, i * 40, j * 40);
	else if (vars->map.map[j * (vars->map.x + 1) + i] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win.addr,
			vars->start.addr, i * 40, j * 40);
	else
		mlx_put_image_to_window(vars->mlx, vars->win.addr,
			vars->empty.addr, i * 40, j * 40);
}

void	print_map(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	while (j < vars->map.y)
	{
		i = 0;
		while (i < vars->map.x)
		{
			put_img(vars, i, j);
			i++;
		}
		j++;
		mlx_put_image_to_window(vars->mlx, vars->win.addr, vars->player.addr,
			vars->pos.x * 40, vars->pos.y * 40);
	}
	return ;
}
