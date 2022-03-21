#include "mlx.h"
#include "so_long.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;	
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

#include <stdio.h>
void	draw_square(int	x, int y, int size, t_data *img)
{
	int	i;
	int	j;

	j = y + size + 1;
	while (--j > y)
	{
		i = x + size + 1;
		while (--i > x)
			if (i > x && i < x + size && j > y && j < y + size)
				pixel_put(img, i, j, create_trgb(i, i, j, j));
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
int	main(void)
{
	t_vars	vars;
	t_data	img;
	int	i;
	int j = 0;
	int	t = 0;
	
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "so_long");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	while (j < 1080)
	{
		i = 0;
		while (i < 1920)
		{
			printf("running i%d j%d\n", i, j);
			if (t > 0)
			{
				t = -1;
				draw_square(i, j, 20, &img);
			}
			else
			{
				t = 1;
				printf("drawing circle");
				draw_circlef(&img, i, j, 10, create_trgb( j, j, i, i));
			}
			i += 20;
		}
		j += 20;
		if (t > 0)
			t = -1;
		else
			t = 1;
	}

	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_key_hook(vars.mlx_win, keypress, &vars);
	mlx_loop(vars.mlx);
}
