/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:29:19 by jgobbett          #+#    #+#             */
/*   Updated: 2022/03/25 17:42:28 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_int
{
	int	*array;
	int	size;
}	t_int;

typedef struct s_v2 {
	int	x;
	int	y;
}	t_v2;

typedef struct s_img {
	void	*img;
	int		w;
	int		h;
}	t_img;

typedef struct s_textures {
	t_img	*player;
	t_img	*ground;
	t_img	*obj;
	t_img	*goal;
	t_img	*wall;
}	t_textures;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}	t_vars;

typedef struct s_render {
	t_data	*img;
	t_vars	*vars;
	t_v2	window;
}	t_render;

typedef struct s_tile {
	t_img	*img;
	t_v2	*pos;
}	t_tile;

typedef struct s_grid {
	char	**grid;
	int		h;
	int		w;
}	t_grid;

typedef struct s_map {
	t_tile	**tiles;
	t_grid	*grid;
	t_v2	*player_pos;
}	t_map;

int		dist(int fx, int fy, int sx, int sy);
void	pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(unsigned char t, unsigned char r,
			 unsigned char g, unsigned char b);
int		keypress(int keycode, t_vars *vars);
t_grid	*grab_grid(char	*path);

#endif
