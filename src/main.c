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

	if (argc < 2 || argc > 2)
	{
		putstr("plz include map\n");
		return (0);
	}
	r.obj = 0;
	r.path = argv[1];
	get_size(argv[1], &r);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, r.size->x * 50,
			r.size->y * 50, "so_long");
	r.vars = &vars;
	r.m = build_map(&r);
	if (error_handle(&r, argv[1]))
		return (0);
	mlx_key_hook(vars.mlx_win, keypress, &r);
	mlx_loop_hook(r.vars->mlx, render_next_frame, &r);
	mlx_loop(r.vars->mlx);
}
