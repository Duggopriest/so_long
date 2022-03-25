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

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>

typedef struct s_int
{
	int	*array;
	int	size;
}	t_int;

typedef struct	s_vector2 {
	int	x;
	int	y;
}	t_vector2;

typedef struct	s_data {
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

typedef struct	s_render {
	t_data	*img;
	t_vars	*vars;
}	t_render;

void	draw_circlef(t_data *img, int x, int y, int size, int color);
int		dist(int fx, int fy, int sx, int sy);
void	pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
void	draw_line(int fx, int fy, int sx, int sy, t_data *img);
void	Interpolate(int fx, int fy, int sx, int sy, t_int *values);
void	draw_triangle(t_vector2 *p0, t_vector2 *p1, t_vector2 *p2, t_data *img, int color);
void	swapi(int *a, int *b);

#endif
