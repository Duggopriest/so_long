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

void	*get_size(char *path, t_render *r)
{
	t_grid	*g;
	t_v2	*i;

	i = malloc(sizeof(i));
	g = malloc(sizeof(g) + 1);
	g = grab_grid(path);
	i->x = g->w;
	i->y = g->h;
	free(g);
	r->size = i;
	return (i);
}

int	render_next_frame(t_render *r)
{
	int	j;
	int	i;

	j = 0;
	while (j < r->m->grid->h)
	{
		i = -1;
		while (++i < r->m->grid->w)
			draw_map(r->m->grid->grid[j][i], j, i, r);
		j++;
	}
	return (1);
}
