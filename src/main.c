#include "mlx.h"
#include "so_long.h"

int	render_next_frame(t_render *render)
{
	mlx_put_image_to_window(render->vars->mlx,
		render->vars->mlx_win, render->img->img, 0, 0);
	return (1);
}

int	main(void)
{
	t_grid	*grid;
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("starting\n");
	grid = grab_grid("test.txt");
	printf("assigned\n");
	printf("h = %d		w = %d\n", grid->h, grid->w);
	while (grid->h > j)
	{
		i = 0;
		while (grid->w > i)
			printf("%c", grid->grid[j][i++]);
		j++;
	}
	/*
	t_data		img;
	t_vars		vars;
	t_render	render;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 500, 500, "so_long");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	render.img = &img;
	render.vars = &vars;
	mlx_key_hook(vars.mlx_win, keypress, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &render);
	mlx_loop(vars.mlx);*/
}
