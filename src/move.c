/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:23:00 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/07 04:56:08 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap(char *a, char *b, t_render *r)
{
	static char	c = '0';

	if (*a == 'C')
		r->obj = 1;
	if (r->obj == 1 && *a == 'E')
		printf("win\n");
	if (c == 'E')
		*b = 'E';
	else
		*b = '0';
	c = *a;
	*a = 'P';
}

int	move(int k, t_render *r)
{
	int	x;
	int	y;

	x = r->m->px;
	y = r->m->py;
	if (k == 119)
		if (r->m->grid->grid[y - 1][x] != '1')
			swap(&r->m->grid->grid[y - 1][x], &r->m->grid->grid[y][x], r);
	if (k == 115)
		if (r->m->grid->grid[y + 1][x] != '1')
			swap(&r->m->grid->grid[y + 1][x], &r->m->grid->grid[y][x], r);
	if (k == 'd')
		if (r->m->grid->grid[y][x + 1] != '1')
			swap(&r->m->grid->grid[y][x + 1], &r->m->grid->grid[y][x], r);
	if (k == 'a')
		if (r->m->grid->grid[y][x - 1] != '1')
			swap(&r->m->grid->grid[y][x - 1], &r->m->grid->grid[y][x], r);
	return (1);
}

int	keypress(int keycode, t_render *r)
{
	printf("	%i\n", keycode);
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(r->vars->mlx, r->vars->mlx_win);
		exit(0);
	}
	else
		move(keycode, r);
	return (0);
}
