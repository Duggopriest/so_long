/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:23:00 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/01 08:23:01 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int keycode, t_render *r)
{
	printf("%i\n", keycode);
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(r->vars->mlx, r->vars->mlx_win);
		exit(0);
	}
	return (0);
}
