#include "so_long.h"

int	keypress(int keycode, t_vars *vars)
{
	printf("%i\n", keycode);
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	return (0);
}
