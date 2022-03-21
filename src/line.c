#include "so_long.h"
#include <stdlib.h>

void	swapi(int *a, int *b)
{
	int	*temp;
	temp = a;
	a = b;
	b = temp;
}

int	abs(int	a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

int	*append(int *array, double d, int size)
{
	int	*new;
	int	i;

	i = size;
	new = (int *)malloc((i + 1) * sizeof(int));
	new[i] = d;
	while (--i)
		new[i] = array[i];
	free(array);
	return (new);
}

int *Interpolate(int fx, int fy, int sx, int sy)
{
	double	a;
	double	d;
	int	i;
	int	*values;
	int	size;

	values = (int *)malloc(sizeof(int) * 1);
	size = 0;
	if (fx == sx)
       return (&sy);
    a = (double)(sy - fy) / (double)(sx - fx);
    d = fy;
	i = fx;
    while (i < sx)
	{
		printf("d = %f\n", d + a);
        values = append(values, d, ++size);
        d = d + a;
		i++;
    }
    return (values);
}

void	draw_line(int fx, int fy, int sx, int sy, t_data *img)
{
	int	*ys;
	int	*xs;
	int	x;
	int	y;
    if (abs(sx - fx) > abs(sy - fy))
	{
        if (fx > sx)
		{
            swapi(&fx, &sx);
			swapi(&fy, &sy);
        }
		x = fx;
        ys = Interpolate(fx, fy, sx, sy);
        while (x < sx)
		{
			pixel_put(img, x, ys[x - fx], 0x00FF0000);
			x++;
		}
    } 
	else 
	{
        if (fy > sy) 
		{
            swapi(&fx, &sx);
			swapi(&fy, &sy);
        }
		y = fy;
        xs = Interpolate(fy, fx, sy, sx);
        while (y < sy)
		{
			pixel_put(img, xs[y - fy], y, 0x00FF0000);
			y++;
		}
    }
}


/*
void	draw_line(int x0, int y0, int x1, int y1, t_data *img)
{
	if (x0 > x1)
		swapi(&x0, &x1);
	if (y0 > y1)
		swapi(&y0, &y1);
	double	a = (double)(y1 - y0) / (double)(x1 - x0);
    double	b = y0 - a * x0;
    double	x = x0;
	double	y;
	while (x < x1) 
	{
        y = a * x + b;
		pixel_put(img, x++, y, 0x00FF0000);
		printf("a = %f\nx = %f\n", a, x);
	}
}*/
