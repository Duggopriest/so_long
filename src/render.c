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

void	draw_map(char c, int j, int i, t_render *r)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(r->vars->mlx,
			r->vars->mlx_win, r->m->t->ground, i * 50, j * 50);
		mlx_put_image_to_window(r->vars->mlx,
			r->vars->mlx_win, r->m->t->player, (i * 50) + 5, (j * 50) + 5);
		r->m->py = j;
		r->m->px = i;
	}
	else if (c == '0')
		mlx_put_image_to_window(r->vars->mlx,
			r->vars->mlx_win, r->m->t->ground, i * 50, j * 50);
	else if (c == 'C')
		mlx_put_image_to_window(r->vars->mlx,
			r->vars->mlx_win, r->m->t->obj, i * 50, j * 50);
	else if (c == 'E')
		mlx_put_image_to_window(r->vars->mlx,
			r->vars->mlx_win, r->m->t->exit, i * 50, j * 50);
	else if (c == '1')
		mlx_put_image_to_window(r->vars->mlx,
			r->vars->mlx_win, r->m->t->wall, i * 50, j * 50);
}

//loop the frames
int	render_next_frame(t_render *r)
{
	return (1);
}
