/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:23:00 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/07 06:10:44 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			ft_putnbr(n);
		}
		else if (n < 10)
		{
			c = n + '0';
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(n / 10);
			c = (n % 10) + '0';
			write(1, &c, 1);
		}
	}
}

void	swap(char *a, char *b, t_render *r)
{
	static char	c = '0';

	if (*a == 'C')
		r->obj = 1;
	if (r->obj == 1 && *a == 'E')
	{
		putstr("win\n");
		exit_game(r);
	}
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
	if (k == 'w' || k == 13)
		if (r->grid->grid[y - 1][x] != '1')
			swap(&r->grid->grid[y - 1][x], &r->grid->grid[y][x], r);
	if (k == 's' || k == 1)
		if (r->grid->grid[y + 1][x] != '1')
			swap(&r->grid->grid[y + 1][x], &r->grid->grid[y][x], r);
	if (k == 'd' || k == 2)
		if (r->grid->grid[y][x + 1] != '1')
			swap(&r->grid->grid[y][x + 1], &r->grid->grid[y][x], r);
	if (k == 'a' || k == 0)
		if (r->grid->grid[y][x - 1] != '1')
			swap(&r->grid->grid[y][x - 1], &r->grid->grid[y][x], r);
	return (1);
}

void	render_new_frame(t_render *r)
{
	int	j;
	int	i;

	j = 0;
	while (j < r->grid->h)
	{
		i = -1;
		while (++i < r->grid->w)
			draw_map(r->grid->grid[j][i], j, i, r);
		j++;
	}
}

int	keypress(int k, t_render *r)
{
	static int	i = 0;

	if (k == 65307 || k == 53)
		exit_game(r);
	else if (k == 'w' || k == 's' || k == 'a' || k == 'd'
			|| k == 13 || k == 1 || k == 0 || k == 2)
	{
		i++;
		ft_putnbr(i);
		putstr("\n");
		move(k, r);
		render_new_frame(r);
	}
	return (0);
}
