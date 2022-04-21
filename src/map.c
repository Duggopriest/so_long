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

t_grid	*grab_grid(char	*path)
{
	t_grid	*new;
	int		fd;
	char	*str;

	new = malloc(sizeof(*new));
	new->grid = malloc(300 + sizeof(new->grid));
	fd = open(path, O_RDONLY);
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

t_map	*int_map(char *map_path)
{
	t_map	*m;
	int		j;

	m = malloc(sizeof(*m));
	m->grid = grab_grid(map_path);
	m->ti = malloc(sizeof(t_tile **));
	j = 0;
	while (j <= m->grid->h)
		m->ti[j++] = malloc(sizeof(t_tile) * m->grid->w);
	return (m);
}

t_map	*build_map(t_render *r)
{
	t_map		*m;
	int			j;
	int			i;

	m = int_map(r->path);
	m->t = grab_textures(r);
	r->m = m;
	j = 0;
	while (j < m->grid->h)
	{
		i = -1;
		while (++i < m->grid->w)
			draw_map(m->grid->grid[j][i], j, i, r);
		j++;
	}
	return (m);
}
