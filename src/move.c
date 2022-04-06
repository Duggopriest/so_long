/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:23:00 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/06 10:10:03 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap(char *a, char *b)
{
	char	*c;

	c = a;
	a = b;
	b = c;
}

int	move(int k, t_render *r)
{
	int	x;
	int	y;

	x = r->m->pp->x;
	y = r->m->pp->y;
	if (k == 'w')
		if (r->m->grid->grid[y + 1][x] == '0')
			swap(&r->m->grid->grid[y + 1][x], &r->m->grid->grid[y][x]);
	if (k == 's')
		if (r->m->grid->grid[y - 1][x] == '0')
			swap(&r->m->grid->grid[y - 1][x], &r->m->grid->grid[y][x]);
	if (k == 'd')
		if (r->m->grid->grid[y][x + 1] == '0')
			swap(&r->m->grid->grid[y][x + 1], &r->m->grid->grid[y][x]);
	if (k == 'a')
		if (r->m->grid->grid[y][x - 1] == '0')
			swap(&r->m->grid->grid[y][x - 1], &r->m->grid->grid[y][x]);
	return (1);
}

int	keypress(int keycode, t_render *r)
{
	printf("%i\n", keycode);
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(r->vars->mlx, r->vars->mlx_win);
		exit(0);
	}
	else
		move(keycode, r);
	return (0);
}
