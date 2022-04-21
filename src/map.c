/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:31:41 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/07 06:01:50 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

t_textures	*grab_textures(t_render *r)
{
	t_textures	*t;

	t = malloc(sizeof(t));
	t->player = mlx_xpm_file_to_image(r->vars->mlx,
			"text/P.xpm", &t->w, &t->h);
	t->ground = mlx_xpm_file_to_image(r->vars->mlx,
			"text/0.xpm", &t->w, &t->h);
	t->obj = mlx_xpm_file_to_image(r->vars->mlx,
			"text/C.xpm", &t->w, &t->h);
	t->exit = mlx_xpm_file_to_image(r->vars->mlx,
			"text/E.xpm", &t->w, &t->h);
	t->wall = mlx_xpm_file_to_image(r->vars->mlx,
			"text/1.xpm", &t->w, &t->h);
	return (t);
}

t_grid	*grab_grid(char	*path)
{
	t_grid	*new;
	int		fd;
	char	*str;

	new = malloc(sizeof(t_grid));
	new->grid = malloc(300 * sizeof(*new->grid));
	fd = open(path, O_RDONLY);
	new->h = 0;
	while (1)
	{
		new->grid[new->h] = get_next_line(fd);
		if (!new->grid[new->h] || new->h > 100)
			break ;
		new->h++;
	}
	new->w = ft_strlen(&new->grid[0][0]) - 1;
	return (new);
}

t_map	*int_map(t_render *r)
{
	t_map	*m;
	int		j;

	m = malloc(sizeof(t_map));
	m->ti = malloc(100);
	j = 0;
	while (j <= r->grid->h)
		m->ti[j++] = malloc(sizeof(t_tile) * r->grid->w);
	return (m);
}

t_map	*build_map(t_render *r)
{
	t_map		*m;
	int			j;
	int			i;

	m = int_map(r);
	m->t = grab_textures(r);
	r->m = m;
	j = 0;
	while (j < r->grid->h)
	{
		i = -1;
		while (++i < r->grid->w)
			draw_map(r->grid->grid[j][i], j, i, r);
		j++;
	}
	return (m);
}
