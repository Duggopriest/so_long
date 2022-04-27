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

//goes around the map checking for not 1's
int	map_checker(t_grid *g)
{
	int	i;

	i = 0;
	while (i < g->w) // checking the top
		if (g->grid[0][i++] != '1')
			return (1);
	i = 0;
	while (i < g->h)// checking the left
		if (g->grid[i++][0] != '1')
			return (1);
	i = 0;
	while (i < g->w) // checking the bottom
		if (g->grid[g->h - 1][i++] != '1')
			return (1);
	i = 0;
	while (i < g->h) // checking the right
		if (g->grid[i++][g->w - 1] != '1')
			return (1);
	return (0);
}

void	error_handle(t_render *r)
{
	if (map_checker(r->grid))// if the map is not enclosed then throw "Error\n" and exit
	{
		putstr("Error\n");
		exit(1);//exits game
	}
}
