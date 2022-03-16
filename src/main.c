#include "mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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

void	draw_square(int	y, int x, int size, t_data *img)
{
	int	i;
	int	j;

	j = y + size + 1;
	while (--j > y)
	{
		i = x + size + 1;
		while (--i > x)
			if (i > x && i < x + size && j > y && j < y + size)
				pixel_put(img, i, j, create_trgb(0, 0, i, j));
	}	
}

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}	t_vars;
#include <stdio.h>
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
	t_vars vars;
	//t_data	img;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "so_long");
	
	//img.img = mlx_new_image(vars.mlx, 1920, 1080);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	//draw_square(0, 0, 1000, &img);
	//pixel_put(&img, 50, 50, 0x00FF0000);
	//mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	
	//mlx_hook(vars.mlx, 33, 1L << 17, exit_game, &vars);
	mlx_key_hook(vars.mlx_win, keypress, &vars);
	mlx_loop(vars.mlx);
}
