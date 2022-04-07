/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:32:22 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/07 04:39:08 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_loop(t_render *r)
{
	int	i;
	int	j;

	j = 0;
	printf("drawing\n");
	while (j < r->m->grid->h)
	{
		i = -1;
		printf("\n");
		while (++i < r->m->grid->w)
			printf("%c", r->m->grid->grid[j][i]);//draw_map(r->m->grid->grid[j][i], j, i, r);
		j++;
	}
}