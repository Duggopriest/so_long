/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:25:53 by jgobbett          #+#    #+#             */
/*   Updated: 2022/03/21 12:45:22 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int ft_squr(int x)
{
	int lower = 1;
	int upper = x;
	int root = lower + (upper - lower) / 2;

	if (x < 0)
		return (0);
	if (x == 0 || x == 1)
		return (x);
	while (root > x / root || root + 1 <= x/(root+1))
	{
		if (root > x/root)
			upper = root;
		else
			lower = root;
		root = lower + (upper - lower) / 2;
	}
	return (root);
}

int	dist(int fx, int fy, int sx, int sy)
{
	return (ft_squr((sx - fx) * (sx - fx) + (sy - fy) * (sy - fy)));
}

void	draw_circlef(t_data *img, int x, int y, int size, int color)
{
	int	i;
	int	j;
	int	box;

	j = 0;
	box = size * 2;
	while (++j < box)
	{
		i = 0;
		while (++i < box)
		{
			if (dist(i, j, size, size) < size)
				pixel_put(img, i + x, j + y, color);
		}
	}
}
