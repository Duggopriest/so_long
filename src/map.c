/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:31:41 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/25 09:38:50 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	ft_str(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == 'C')
			j++;
	return (j);
}

t_textures	*grab_textures(t_render *r)
{
	t_textures	*t;

	putstr("textures loading...");
	t = malloc(sizeof(t) + 10);
	t->player = mlx_xpm_file_to_image(r->mlx,
			"text/P.xpm", &t->w, &t->h);
	t->player2 = mlx_xpm_file_to_image(r->mlx,
			"text/P2.xpm", &t->w, &t->h);
	t->ground = mlx_xpm_file_to_image(r->mlx,
			"text/0.xpm", &t->w, &t->h);
	t->obj = mlx_xpm_file_to_image(r->mlx,
			"text/C.xpm", &t->w, &t->h);
	t->exit = mlx_xpm_file_to_image(r->mlx,
			"text/E.xpm", &t->w, &t->h);
	t->wall = mlx_xpm_file_to_image(r->mlx,
			"text/1.xpm", &t->w, &t->h);
	t->bad = mlx_xpm_file_to_image(r->mlx,
			"text/B.xpm", &t->w, &t->h);
	putstr("done\n");
	return (t);
}

t_grid	*grab_grid(char	*path, t_render *r)
{
	t_grid	*new;
	int		fd;
	char	*str;

	putstr("grid loading...");
	new = malloc(sizeof(t_grid) + 1);
	new->grid = malloc(50 * sizeof(t_grid) + 1);
	fd = open(path, O_RDONLY);
	new->h = 0;
	while (1)
	{
		new->grid[new->h] = get_next_line(fd);
		if (!new->grid[new->h] || new->h > 100)
			break ;
		r->obj += ft_str(new->grid[new->h]);
		new->h++;
	}
	close(fd);
	new->w = ft_strlen(&new->grid[0][0]) - 1;
	putstr("done\n");
	return (new);
}
