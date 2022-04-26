/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:29:19 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/26 04:48:53 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_textures {
	void	*player;
	void	*player2;
	void	*ground;
	void	*obj;
	void	*wall;
	void	*exit;
	void	*bad;
	int		w;
	int		h;
}	t_textures;

typedef struct s_numt {
	void	*n0;
	void	*n1;
	void	*n2;
	void	*n3;
	void	*n4;
	void	*n5;
	void	*n6;
	void	*n7;
	void	*n8;
	void	*n9;
	int		w;
	int		h;
}	t_numt;

typedef struct s_grid {
	char	**grid;
	int		h;
	int		w;
}	t_grid;

typedef struct s_render {
	void		*mlx;
	void		*mlx_win;
	t_grid		*grid;
	t_numt		*numt;
	int			obj;
	int			moves;
	int			px;
	int			py;
	t_textures	*t;
}	t_render;

int			keypress(int keycode, t_render *r);
t_grid		*grab_grid(char	*path, t_render *r);
void		draw_map(char c, int j, int i, t_render *r);
int			render_next_frame(t_render *render);
void		*get_size(char *path, t_render *r);
void		putstr(char *str);
void		error_handle(t_render *r, char *path);
void		exit_game(t_render *r);
void		ft_putnbr(int n);
void		display_num(t_render *r);
t_numt		*grab_numbers(t_render *r);
t_textures	*grab_textures(t_render *r);
void		render_new_frame(t_render *r);

#endif
