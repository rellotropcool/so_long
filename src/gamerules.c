/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamerules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:21:44 by aule-bre          #+#    #+#             */
/*   Updated: 2023/12/29 15:21:46 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gamerules(t_vars *vars)
{
	if (vars->map.map[vars->pos.y * (vars->map.x + 1) + vars->pos.x] == 'C')
	{
		vars->map.map[vars->pos.y * (vars->map.x + 1) + vars->pos.x] = '0';
		vars->map.collec--;
	}
	if (!vars->map.collec
		&& (vars->map.map[vars->pos.y * (vars->map.x
					+ 1) + vars->pos.x] == 'E'))
	{
		write(1, "C4EST GAGNER EN \n", 16);
		ft_putnbr(vars->c);
		write (1, " COUPS\n", 7);
		ft_close(vars);
	}
}

int	ft_close(t_vars *vars)
{
	if (vars->map.map != NULL)
	{
		free(vars->map.map);
		mlx_destroy_image(vars->mlx, vars->coll.addr);
		mlx_destroy_image(vars->mlx, vars->end.addr);
		mlx_destroy_image(vars->mlx, vars->player.addr);
		mlx_destroy_image(vars->mlx, vars->wall.addr);
		mlx_destroy_image(vars->mlx, vars->empty.addr);
		mlx_destroy_image(vars->mlx, vars->start.addr);
		mlx_destroy_window(vars->mlx, vars->win.addr);
	}
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	return(exit(0), 0);
}
