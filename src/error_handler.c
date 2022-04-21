/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 05:39:49 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/07 06:17:08 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(0, &str[i++], 1);
}

int	map_checker(t_grid *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g->w)
		if (g->grid[0][i++] != '1')
			j = 1;
	while (i < g->h)
		if (g->grid[i++][0] != '1')
			j = 1;
	while (i < g->w)
		if (g->grid[g->h][i++] != '1')
			j = 1;
	while (i < g->h)
		if (g->grid[i++][g->w] != '1')
			j = 1;
	if (j)
		putstr("Error\n");
	return (j);
}

int	error_handle(t_render *r, char *path)
{
	if (map_checker(r->m->grid))
		return (1);
	return (0);
}

void	exit_game(t_render *r)
{
	mlx_destroy_window(r->vars->mlx, r->vars->mlx_win);
	exit(0);
}