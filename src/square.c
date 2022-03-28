#include "so_long.h"

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