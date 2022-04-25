/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 05:37:19 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/07 06:11:10 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	player_animation(int j, int i, t_render *r)
{
	static int	b = 0;

	mlx_put_image_to_window(r->mlx,
		r->mlx_win, r->m->t->ground, i * 50 + 5, j * 50 + 5);
	if (b == 1)
	{
		b = 0;
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->m->t->player, i * 50 + 10, j * 50 + 10);
	}
	else
	{
		b = 1;
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->m->t->player2, i * 50 + 5, j * 50 + 5);
	}
	r->m->py = j;
	r->m->px = i;
}

void	draw_map(char c, int j, int i, t_render *r)
{
	if (c == 'P')
		player_animation(j, i, r);
	else if (c == '0')
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->m->t->ground, i * 50 + 5, j * 50 + 5);
	else if (c == 'C')
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->m->t->obj, i * 50 + 5, j * 50 + 5);
	else if (c == 'E')
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->m->t->exit, i * 50 + 5, j * 50 + 5);
	else if (c == '1')
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->m->t->wall, i * 50 + 5, j * 50 + 5);
	else if (c == 'B')
		mlx_put_image_to_window(r->mlx,
			r->mlx_win, r->m->t->bad, i * 50 + 5, j * 50 + 5);
}

//loop the game until end condition
int	render_next_frame(t_render *r)
{
	return (1);
}
