/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:29:19 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/07 06:15:09 by jgobbett         ###   ########.fr       */
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

typedef struct s_textures {
	void	*player;
	void	*ground;
	void	*obj;
	void	*wall;
	void	*exit;
	int		w;
	int		h;
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

typedef struct s_tile {
	void	*img;
}	t_tile;

typedef struct s_grid {
	char	**grid;
	int		h;
	int		w;
}	t_grid;

typedef struct s_map {
	t_tile		**ti;
	int			px;
	int			py;
	t_textures	*t;
}	t_map;

typedef struct s_render {
	t_map	*m;
	t_grid	*grid;
	t_vars	*vars;
	int		obj;
}	t_render;

int		keypress(int keycode, t_render *r);
t_grid	*grab_grid(char	*path);
t_map	*build_map(t_render *r);
void	draw_map(char c, int j, int i, t_render *r);
t_grid	*grab_grid(char	*path);
int		render_next_frame(t_render *render);
void	*get_size(char *path, t_render *r);
void	putstr(char *str);
void	error_handle(t_render *r, char *path);
void	exit_game(t_render *r);
void	ft_putnbr(int n);

#endif
