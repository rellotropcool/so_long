#include <stdio.h>
#include "mlx/mlx.h"
#include <X11/keysym.h>      

typedef struct  s_coo {
    int x;
    int y;
}               t_coo;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    t_coo player;
    t_coo img_size;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
    if (keycode == 65361 && vars->player.x)
        vars->player.x -= 50;
    if (keycode == 65363 && vars->player.x < 1900 - vars->img_size.x)
        vars->player.x += 50;
    if (keycode == 65362 && vars->player.y)
        vars->player.y -= 50;
    if (keycode == 65364 && vars->player.y < 1050 - vars->img_size.y)
        vars->player.y += 50;
    printf("%d\n", keycode);
    printf("%d %d\n", vars->player.x, vars->player.y);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->player.x, vars->player.y);
    return (0);
}

int     render_next_frame(t_vars vars)
{
    return ((void)vars, 0);
}

int	main(void)
{
    static t_vars  vars;

	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1900, 1050, "so_long aule-bre");
    vars.img = mlx_xpm_file_to_image(vars.mlx, "test.xpm", &vars.img_size.x, &vars.img_size.y);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
}
