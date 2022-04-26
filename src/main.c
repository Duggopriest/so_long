/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 05:57:49 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/26 04:03:17 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_render	*r;

	r = malloc(sizeof(t_render) + 1);
	if (argc != 2)
	{
		putstr("plz include map\n");
		return (0);
	}
	r->obj = 0;
	r->grid = 0;
	r->grid = grab_grid(argv[1], r);
	r->numt = grab_numbers(r);
	putstr("done\n");
	r->mlx = mlx_init();
	r->mlx_win = mlx_new_window(r->mlx, r->grid->w * 50 + 10,
			r->grid->h * 50 + 10, "so_long");
	r->m = build_map(r);
	display_num(r);
	error_handle(r, argv[1]);
	putstr("game loaded");
	mlx_key_hook(r->mlx_win, keypress, r);
	mlx_loop_hook(r->mlx, render_next_frame, r);
	mlx_loop(r->mlx);
}
