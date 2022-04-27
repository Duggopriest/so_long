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

void	grab_tx(t_render *r)
{
	putstr("loading number textures...");
	r->numt = grab_numbers(r); // grabs number textures
	putstr("done\n");
	r->t = grab_textures(r); // grabs the map textures
	putstr("drawing map...");
	render_new_frame(r); // draws the next frame
	putstr("done\n");
}

int	main(int argc, char **argv)
{
	t_render	*r; // this holds most 

	r = malloc(sizeof(t_render));
	if (argc != 2) // checks for the correct amount of inputs
	{
		putstr("plz include map\n");
		return (0);
	}
	r->obj = 0;
	r->grid = 0;
	r->moves = 0;
	r->grid = grab_grid(argv[1], r); //reads the argv[1] (directory) and assigns it to a char **
	error_handle(r); // checks map if its valid
	r->mlx = mlx_init();
	r->mlx_win = mlx_new_window(r->mlx, r->grid->w * 50 + 10,
			r->grid->h * 50 + 10, "so_long"); // uses grid to change the resolution and adds padding
	grab_tx(r); // grabs textures
	mlx_key_hook(r->mlx_win, keypress, r); // sends the key presses to the "keypress" and gives it the r struct
	mlx_loop_hook(r->mlx, render_next_frame, r); // make the game render new frames
	putstr("game loaded!\n");
	mlx_loop(r->mlx); // make the window stay up
}
