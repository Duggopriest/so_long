/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 05:57:49 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/07 04:44:14 by jgobbett         ###   ########.fr       */
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
		printf("plz include map\n");
		return (0);
	}
	r.obj = 0;
	r.path = argv[1];
	get_size(argv[1], &r);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, r.size->x * 50,
			r.size->y * 50, "so_long");
	r.vars = &vars;
	printf("building map\n");
	r.m = build_map(&r);
	printf("map built\n");
	mlx_key_hook(vars.mlx_win, keypress, &r);
	mlx_loop_hook(r.vars->mlx, render_next_frame, &r);
	mlx_loop(r.vars->mlx);
}
/*
int	main(int argc, char **argv)
{
	t_data		img;
	t_vars		vars;
	t_render	r;

	r.path = argv[1];
	get_size(argv[1], &r);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, r.size->x * 50,
			r.size->y * 50, "so_long");
	img.img = mlx_new_image(vars.mlx, r.size->x * 50, r.size->y * 50);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	r.img = &img;
	r.vars = &vars;
	mlx_key_hook(vars.mlx_win, keypress, &r);
	mlx_loop_hook(vars.mlx, render_next_frame, &r);
	mlx_loop(vars.mlx);
}
*/
