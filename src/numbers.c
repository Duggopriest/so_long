/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:23:00 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/26 04:49:17 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// t_numa	*new_numa(void)
// {
// 	t_numa	*n;
// 	int		i;

// 	n = malloc(sizeof(t_numa) * 11);
// 	i = 0;
// 	while (i < 11)
// 		n[i++] = malloc(sizeof(t_numa) + 1);
// 	return (n);
// }

t_numa	*grab_numbers(t_render *r)
{
	t_numa	*t;
	int		a;
	int		b;

	putstr("loading number textures...");
	t = malloc(sizeof(t_numa) * 11);
	t[0].i = mlx_xpm_file_to_image(r->mlx,
			"text/00.xpm", &a, &b);
	t[1].i = mlx_xpm_file_to_image(r->mlx,
			"text/01.xpm", &a, &b);
	t[2].i = mlx_xpm_file_to_image(r->mlx,
			"text/02.xpm", &a, &b);
	t[3].i = mlx_xpm_file_to_image(r->mlx,
			"text/03.xpm", &a, &b);
	t[4].i = mlx_xpm_file_to_image(r->mlx,
			"text/04.xpm", &a, &b);
	t[5].i = mlx_xpm_file_to_image(r->mlx,
			"text/05.xpm", &a, &b);
	t[6].i = mlx_xpm_file_to_image(r->mlx,
			"text/06.xpm", &a, &b);
	t[7].i = mlx_xpm_file_to_image(r->mlx,
			"text/07.xpm", &a, &b);
	t[8].i = mlx_xpm_file_to_image(r->mlx,
			"text/08.xpm", &a, &b);
	t[9].i = mlx_xpm_file_to_image(r->mlx,
			"text/09.xpm", &a, &b);
	return (t);
}

void	draw_num(t_render *r, int c, int os)
{
	if (c >= 0 && c <= 9)
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->numt[c].i, os, 10);
}

void	display_num(t_render *r)
{
	if (r->moves < 100)
	{
		draw_num(r, r->moves / 10, 10);
		draw_num(r, r->moves % 10, 15);
	}
	else
	{
		draw_num(r, 9, 1);
		draw_num(r, 9, 5);
	}
}
