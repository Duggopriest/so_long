#include "mlx.h"
#include "so_long.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

#include <stdio.h>
void	draw_square(int	x, int y, int size, t_data *img, int color)
{
	int	i;
	int	j;

	j = y + size + 1;
	while (--j > y)
	{
		i = x + size + 1;
		while (--i > x)
			if (i > x && i < x + size && j > y && j < y + size)
				pixel_put(img, i, j, color);
	}	
}

#include <stdlib.h>

int keypress(int keycode, t_vars *vars)
{
	printf("%i\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	return (0);
}

#include <unistd.h>
int	render_next_frame(t_render *render)
{
	/*
	static int i = 0;	
	static int j = 0;
	static int r = 0;
	static int g = 0;
	static int b = 0;
	static int t = 1;

	if (j >= 1000)
		j = 0;
	if (i >= 1880)
	{
		i = 0;
		j += 20;
	}
	else
		i += 20;
	r++;
	g = r + g;
	b = g + b;
	if (t > 0)
	{
		t = -1;
		draw_square(i, j, 20, render->img, create_trgb(1, r, g, b));
	}
	else
	{
		t = 1;
		draw_circlef(render->img, i, j, 10, create_trgb( 1, r, g, b));
	}
	*/

	//----------------------------------
	/*
	static float j = .5;
	static float i = 0;
	static float a = 1;
	if (i < 1920 && j < 1080)
	{
		draw_line(i++, 0, j++, 1100, render->img);
		//j *= 1.0047;
		//i += a;
		//a *= 0.999;
	}
	*/
	//----------------------------------
	t_vector2 p0;
	t_vector2 p1;
	t_vector2 p2;

	p0.x = 0;
	p0.y = 0;
	p1.x = 10;
	p1.y = 100;
	p2.x = 50;
	p2.y = 50;
	draw_triangle(&p0, &p1, &p2, render->img, create_trgb(1, 0, 1, 0));
	mlx_put_image_to_window(render->vars->mlx, render->vars->mlx_win, render->img->img, 0, 0);
	return (1);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	t_render	render;
	int	i = 0;
	double j = .5;
	int	t = 0;
	
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "so_long");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	render.img = &img;
	render.vars = &vars;

	t_vector2 p0;
	t_vector2 p1;
	t_vector2 p2;

	p0.x = 0;
	p0.y = 0;

	p1.x = 10;
	p1.y = 100;

	p2.x = 50;
	p2.y = 500;
	draw_triangle(&p0, &p1, &p2, render.img, create_trgb(1, 0, 1, 0));

	printf("done\n");
	
	mlx_key_hook(vars.mlx_win, keypress, &vars);
	//mlx_loop_hook(vars.mlx, render_next_frame, &render);
	mlx_loop(vars.mlx);
}
