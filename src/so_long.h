/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:24:51 by aule-bre          #+#    #+#             */
/*   Updated: 2023/12/29 15:24:52 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef UP
#  define UP 1
# endif
# ifndef DOWN
#  define DOWN 3
# endif
# ifndef LEFT
#  define LEFT 2
# endif
# ifndef RIGHT
#  define RIGHT 0
# endif

typedef struct s_coo
{
	int		x;
	int		y;
}			t_coo;

typedef struct s_map
{
	int		x;
	int		y;
	char	*map;
	int		start;
	int		start_dup;
	int		collec;
	int		previous;
}			t_map;

typedef struct s_sys
{
	void	*addr;
	int		x;
	int		y;

}			t_sys;

typedef struct s_vars
{
	void	*mlx;
	t_sys	win;
	t_sys	player;
	t_sys	wall;
	t_sys	empty;
	t_sys	coll;
	t_sys	start;
	t_sys	end;
	t_coo	pos;
	t_map	map;
	int		c;
}			t_vars;

int			ft_strlen(char *s);
char		*ft_strdup(char *str, int len);
char		*ft_strjoin(char *s1, char *s2);
int			ft_count(char *str, char c);
int			get_p(char *map);
char		*map_init(int fd);
int			map_is_valid(t_map *map);
void		fill_checker(char *str, t_map *map);
void		fill_map(t_map *map, int current, char *tile_checker);
int			map_is_endable(t_map *map, int *current, char *tile_checker);
int			vars_gen(t_vars *vars, t_map *map);
void		print_map(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
void		ft_putnbr(int nb);
void		gamerules(t_vars *vars);
void		ft_close(t_vars *vars);

#endif
