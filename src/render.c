/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 05:37:19 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/04 07:07:38 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	*get_size(char *path, t_render *r)
{
	t_grid	*g;
	t_v2	*i;

	i = malloc(sizeof(i));
	g = malloc(sizeof(g));
	g = grab_grid(path);
	i->x = g->w;
	i->y = g->h;
	free(g);
	r->size = i;
	return (i);
}

void	draw_map(t_map *m, t_render *r)
{
	int	i;
	int	j;
	int	size;

	size = 50;
	j = 0;
	while (j < m->grid->h)
	{
		i = -1;
		while (++i < m->grid->w)
		{
			printf("	%d - %d\n", j, i);
			//if (m->player_pos->y == j && m->player_pos->x == i)
			//	mlx_put_image_to_window(r->vars->mlx,
			//		r->vars->mlx_win, m->t->player, i * size, j * size);
			//else
				mlx_put_image_to_window(r->vars->mlx,
					r->vars->mlx_win, &m->ti[0][0].img, 100, 100);
		}
		j++;
	}
}

int	render_next_frame(t_render *r)
{
	t_map	*m;
	int		i;
	int		j = -1;

	printf("building map\n");
	m = build_map(r);
	while (++j < m->grid->h)
	{
		i = 0;
		while (i < m->grid->w)
			printf("%c", m->grid->grid[j][i++]);
	}
	printf("map built\n");
	printf("drawing map\n");
	draw_map(m, r);
	printf("map drawn\n");
	mlx_put_image_to_window(r->vars->mlx,
		r->vars->mlx_win, r->img->img, 0, 0);
	return (1);
}
