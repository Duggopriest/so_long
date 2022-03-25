#include "so_long.h"

double	ft_floor(double n)
{
	return ((double) (int) n);
}

void	pos_swap(t_vector2 *a, t_vector2 *b)
{
	t_vector2 temp;

	temp.x = a->x;
	temp.y = a->y;
	a->x = b->x;
	a->y = b->y;
	b->x = temp.x;
	b->y = temp.y;
}

void	draw_triangle(t_vector2 *p0, t_vector2 *p1, t_vector2 *p2, t_data *img, int color)
{
	t_int	x0;
	t_int	x1;
	t_int	x2;
	t_int	*x_right;
	t_int	*x_left;
	int	x;
	int	y;
	int	m;

	if (p1->y < p0->y)
		pos_swap(p1, p0);
	if (p2->y < p0->y)
		pos_swap(p2, p0);
	if (p2->y < p1->y)
		pos_swap(p2, p1);
	printf("p0.y = %d\n", p0->y);
	printf("p1.y = %d\n", p1->y);
	printf("p2.y = %d\n", p2->y);
	Interpolate(p0->y, p0->x, p1->y, p1->x, &x0);
	Interpolate(p1->y, p1->x, p2->y, p2->x, &x1);
	Interpolate(p0->y, p0->x, p2->y, p2->x, &x2);

	m = 0;
	while(m < x1.size)
	{
		printf("x1->array[%d] = %d\n", m, x1.array[m]);
		if(x1.array[m] > 2000)
		{
			printf("\nerror\n");
			usleep(1000000);
		}
		m++;
	}
	usleep(100000000);
	//draw_line(p0->x, p0->y, p1->x, p1->y, img);
	//draw_line(p2->x, p2->y, p1->x, p1->y, img);
	//draw_line(p0->x, p0->y, p2->x, p2->y, img);
	//printf("lines done\n");

	m = x1.size / 2;
	if(x2.array[m] < x1.array[m])
	{
		x_left = &x2;
		x_right = &x1;
	}
	else
	{
		x_left = &x1;
		x_right = &x2;
	}
	//printf("left.y = %d\n", x_left->array[m]);
	//printf("right.y = %d\n", x_right->array[m]);

	y = p0->y;
	while (y < p2->y)
	{
		x = x_left->array[y - p0->y];
		//printf("left = %d	right = %d\n", x_left->array[y - p0->y], x_right->array[y - p0->y]);
		while (x < x_right->array[y - p0->y])
		{
			printf("x = %d	y = %d\n", x, y);
			pixel_put(img, x, y, color);
			x++;
		}
		printf("next line\n");
		y++;
	}
}
