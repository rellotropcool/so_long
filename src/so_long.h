#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
	t_sys	exit;
	t_coo	pos;
	t_map	map;
}			t_vars;

int			ft_strlen(char *s);
char		*ft_strdup(char *str, int len);
char		*ft_strjoin(char *s1, char *s2);
char		*map_init(int fd);
int			map_is_valid(t_map *map);
void		vars_gen(t_vars *vars, t_map map);
void		print_map(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);

#endif
