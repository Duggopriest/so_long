/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 05:57:49 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/07 06:12:01 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_render	r;

	if (argc != 2)
	{
		putstr("plz include map\n");
		return (0);
	}
	r.obj = 0;
	r.grid = grab_grid(argv[1]);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, r.grid->w * 50,
			r.grid->h * 50, "so_long");
	r.vars = &vars;
	r.m = build_map(&r);
	error_handle(&r, argv[1]);
	mlx_key_hook(r.vars->mlx_win, keypress, &r);
	mlx_loop_hook(r.vars->mlx, render_next_frame, &r);
	mlx_loop(r.vars->mlx);
}
