/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:31:41 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/04 05:38:30 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

t_textures	*grab_textures(t_render *render)
{
	t_textures	t;
	t_textures	*new;

	t.player = mlx_xpm_file_to_image(render->vars->mlx,
			"textures/player.xpm", &t.w, &t.h);
	t.ground = mlx_xpm_file_to_image(render->vars->mlx,
			"textures/ground.xpm", &t.w, &t.h);
	t.obj = mlx_xpm_file_to_image(render->vars->mlx,
			"textures/obj.xpm", &t.w, &t.h);
	t.exit = mlx_xpm_file_to_image(render->vars->mlx,
			"textures/exit.xpm", &t.w, &t.h);
	t.wall = mlx_xpm_file_to_image(render->vars->mlx,
			"textures/wall.xpm", &t.w, &t.h);
	new = &t;
	return (new);
}

t_grid	*grab_grid(char	*path)
{
	t_grid	*new;
	int		fd;
	char	*str;

	new = malloc(sizeof(new));
	new->grid = malloc(100 * sizeof(new->grid));
	fd = open(path, O_RDONLY);
	while (1)
	{
		new->grid[new->h] = get_next_line(fd);
		if (!new->grid[new->h] || new->h > 100)
			break ;
		new->h++;
	}
	new->w = ft_strlen(&new->grid[0][0]);
	return (new);
}

void	assign_img(char a, int j, int i, t_map *m, t_render *r)
{
	if (m->grid->grid[j][i] == 'p')
	{
		m->ti[j][i].img = &m->t->player;
		m->player_pos->y = j;
		m->player_pos->x = i;
	}
	else if (a == '0')
		m->ti[j][i].img = &m->t->ground;
	else if (a == 'C')
		m->ti[j][i].img = &m->t->obj;
	else if (a == 'E')
		m->ti[j][i].img = &m->t->exit;
	else if (a == '1')
		m->ti[j][i].img = m->t->wall;
}

t_map	*int_map(char *map_path)
{
	t_map	*m;
	int		i;
	int		j;

	m = malloc(sizeof(m));
	m->grid = grab_grid(map_path);
	m->ti = malloc(m->grid->h * sizeof(m->ti));
	j = 0;
	while (j < m->grid->h)
			m->ti[j++] = malloc(sizeof(t_tile) * m->grid->w);
	return (m);
}

t_map	*build_map(t_render *r)
{
	t_map		*m;
	int			j;
	int			i;

	m = int_map(r->path);
	printf("	grabbing textures\n");
	m->t = grab_textures(r);
	j = 0;
	printf("	assigning tiles\n");
	while (j < m->grid->h)
	{
		i = 0;
		while (i < m->grid->w)
			assign_img(m->grid->grid[j][i++], j, i, m, r);
		j++;
	}
	return (m);
}
