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

t_numt	*grab_numbers(t_render *r)
{
	t_numt	*t;

	t = malloc(sizeof(t) + 1);
	t->n0 = mlx_xpm_file_to_image(r->mlx,
			"text/00.xpm", &t->w, &t->h);
	t->n1 = mlx_xpm_file_to_image(r->mlx,
			"text/01.xpm", &t->w, &t->h);
	t->n2 = mlx_xpm_file_to_image(r->mlx,
			"text/02.xpm", &t->w, &t->h);
	t->n3 = mlx_xpm_file_to_image(r->mlx,
			"text/03.xpm", &t->w, &t->h);
	t->n4 = mlx_xpm_file_to_image(r->mlx,
			"text/04.xpm", &t->w, &t->h);
	t->n5 = mlx_xpm_file_to_image(r->mlx,
			"text/05.xpm", &t->w, &t->h);
	t->n6 = mlx_xpm_file_to_image(r->mlx,
			"text/06.xpm", &t->w, &t->h);
	t->n7 = mlx_xpm_file_to_image(r->mlx,
			"text/07.xpm", &t->w, &t->h);
	t->n8 = mlx_xpm_file_to_image(r->mlx,
			"text/08.xpm", &t->w, &t->h);
	t->n9 = mlx_xpm_file_to_image(r->mlx,
			"text/09.xpm", &t->w, &t->h);
	return (t);
}

void	draw_num2(t_render *r, int c, int os)
{
	if (c == 6)
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->numt->n6, os, 10);
	else if (c == 7)
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->numt->n7, os, 10);
	else if (c == 8)
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->numt->n8, os, 10);
	else if (c == 9)
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->numt->n9, os, 10);
}

void	draw_num(t_render *r, int c, int os)
{
	if (c == 0)
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->numt->n0, os, 10);
	else if (c == 1)
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->numt->n1, os, 10);
	else if (c == 2)
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->numt->n2, os, 10);
	else if (c == 3)
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->numt->n3, os, 10);
	else if (c == 4)
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->numt->n4, os, 10);
	else if (c == 5)
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->numt->n5, os, 10);
	else
		draw_num2(r, c, os);
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
