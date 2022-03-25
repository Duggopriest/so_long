#include "so_long.h"
#include <stdlib.h>

void	swapi(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int	abs(int	a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

int	*ft_append(t_int *values, float d)
{
	int	*new;
	int	i;

	i = values->size;
	new = malloc((i) * sizeof(int *));
	if (d < 2000)
	new[i] = d;
	while (--i > 0)
		new[i] = values->array[i];
	free(values->array);
	values->size++;
	return (new);
}

void	Interpolate(int fx, int fy, int sx, int sy, t_int *values)
{
	float	a;
	float	d;
	int		i;
	
	values->array = malloc(((sx - fx) + 1) * sizeof(int));
	values->size = 0;
	printf("malloced %d bytes\n", sx - fx);
    a = (float)(sy - fy) / (float)(sx - fx);
    d = fy;
	i = fx;
	while (i < sx)
	{
		printf("\nd = %f\n", d);
        values->array[values->size] = (int)d;
		printf("array[%d] = %d\n", i, values->array[values->size]);
		d = d + a;
		values->size++;
		i++;
    }
	printf("interpolate done\n");
}

void	draw_line(int fx, int fy, int sx, int sy, t_data *img)
{
	t_int	ys;
	t_int	xs;
	int		x;
	int		y;
    
	if (abs(sx - fx) > abs(sy - fy))
	{
        if (fx > sx)
		{
            swapi(&fx, &sx);
			swapi(&fy, &sy);
        }
		x = fx;
        Interpolate(fx, fy, sx, sy, &ys);
		while (x < sx)
		{
			if (ys.array[x - fx] < 1000)
				pixel_put(img, x, ys.array[x - fx], 0x00FF0000);
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
        Interpolate(fy, fx, sy, sx, &xs);
        while (y < sy && y - fy >= 0)
		{
			
			if (xs.array[y - fy] < 1080)
				pixel_put(img, xs.array[y - fy], y, 0x00FF0000);
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
